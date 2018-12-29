/*
 * SPDX-License-Identifier: GPL-3.0+
 * 
 * Copyright (C) 2008 to 2011 Masanori Morise
 * Copyright (C) 2008 to 2011（ZteerのUTAU関連物置き場）
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see: <http://www.gnu.org/licenses/>.
 */
 
#include "config.h"

#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <espeak-ng/espeak_ng.h>
#include <espeak-ng/speak_lib.h>
#include <espeak-ng/encoding.h>

#include "ecantorix.h"
#include "tn_fnds.h"


//input
static float* tn_fnds_input;
static float tn_fnds_midi_pitch;
static int tn_fnds_input_length;
extern int samplerate;

void window(float *wav, int length)
{
    int i;
    for(i = 0;i < length; i++)
    {
			wav[i] = wav[i] * (0.5 - 0.5*cos(2.0*M_PI*(float)(i+1)/((float)(length+1))));
    }
}
void agc(float *wav, int length)
{
    float maxValue = 0;
    int i;
    for(i = 0;i < length; i++)
    {
        if(fabs(wav[i])>maxValue) maxValue=fabs(wav[i]); 
    }
    if(maxValue>0.5)
    {
        for(i = 0;i < length; i++)
        {
            wav[i]/=maxValue;
            wav[i]*=0.5; 
        }
    }
}

void printmax(float *wav, int length,char* label) //for debugging
{
    float maxValue = 0;
    int i;
    for(i = 0;i < length; i++)
    {
        if(fabs(wav[i])>maxValue) maxValue=fabs(wav[i]); 
    }
    fprintf(stderr,"max %s = %f\n",label,maxValue);
   
}

float interp_linear(float* x,float* y,int nx,float ref)
{
    int i;
    for(i=0; i<nx-1; i++)
    {
        if(ref>=x[i] && ref <= x[i+1])
        {
            float x1=x[i];
            float x2=x[i+1];
            float tmp = (ref-x1)/(x2-x1);
            return y[i]*(1-tmp)+y[i+1]*tmp;
        }
    }
    fprintf(stderr,"INTERP_LINEAR: out of range\n");
    return NAN;
}

float copyIn(float* buffera,float* bufferb,int buffer_length,int* pulseLocations,int pCount,float pos)
{
    
    int i,j;
    int found = -1;
    int ref = pos*samplerate;
    int pulse0 = 0;
    for(i=0;i<pCount-1;i++)
    {
        if(pulseLocations[i-1]<=ref && pulseLocations[i] > ref) {found = i; break;}
    }
    if(ref<pulseLocations[0])
    {
		found = 0;
		pulse0 = 1;
	}
    if(found>=0)
    {
        //fprintf(stderr,"copyIn %i %i %i %i\n",pulseLocations[found-1],pulseLocations[found],ref,tn_fnds_input_length);
        for(i=0;i<buffer_length;i++)
        {
            j = i - buffer_length/2 + pulseLocations[found-1];
            if(j>0 && j<tn_fnds_input_length) buffera[i] = tn_fnds_input[j];
            else buffera[i] = 0;
        }
        for(i=0;i<buffer_length;i++)
        {
            j = i - buffer_length/2 + pulseLocations[found];
            if(j>0 && j<tn_fnds_input_length) bufferb[i] = tn_fnds_input[j];
            else bufferb[i] = 0;
        }
        if(pulse0) return 0.5;
        float zz = pulseLocations[found-1]-pulseLocations[found];
        float nn = pulseLocations[found-1]-ref;
        return (nn/zz);
        
    }
    fprintf(stderr,"copy in failed lastPulseLocationIs=%i ref=%i\n",pulseLocations[pCount-2],ref);
    #if 0
    for(i=0;i<pCount-1;i++)
    {
        fprintf(stderr,"ploc: %i ref: %i\n",pulseLocations[i],ref);
    }
    #endif
    return 2.0;
}

void ola_agc(float* output_buffer,int output_buffer_length,float* buffer,int buffer_length,int pos)
{
    int i,j;
    int overflow_counter = 0;
    float max_pos=0;
    float max_neg=0;
    
    for(int i=0;i<buffer_length;i++)
    {
         j = i - buffer_length/2 + pos;
         if(j>0 && j<output_buffer_length) { 
			 output_buffer[j] += buffer[i];
			 if(fabs(output_buffer[j])>0.5) {;
				 if(output_buffer[j] > 0 &&  output_buffer[j]>max_pos) max_pos =  output_buffer[j];
				 if(output_buffer[j] < 0 && -output_buffer[j]>max_neg) max_neg = -output_buffer[j];
				 overflow_counter++;
			 }
		 }
    }
    if(overflow_counter==0) return;
    for(int i=0;i<buffer_length;i++)
    {
         j = i - buffer_length/2 + pos;
         if(j>0 && j<output_buffer_length) {
			 if(output_buffer[j]>0 && max_pos>0) {output_buffer[j]/=max_pos; output_buffer[j]*=0.5; } 
			 if(output_buffer[j]<0 && max_neg>0) {output_buffer[j]/=max_neg; output_buffer[j]*=0.5; }
			 
		 }
	}
    
}

int findWedge(int start,int T0,float factor)
{
    int wedge;
    float peak=0;
    int i;
    for(i = start;i < T0*factor+1+start;i++)
    {
        if(i>tn_fnds_input_length-1) break;
        if(tn_fnds_input[i] > peak)
        {
            peak = tn_fnds_input[i];
            wedge = i;
        }
    }
    return wedge;
}

int getPulseLocations(int T0,int* pulseLocations)
{
    int pCount=0;
    int wedge = findWedge(0,T0,2);
    if(pulseLocations) pulseLocations[pCount] = wedge;
    pCount++;
    int i=wedge;
    while(i<tn_fnds_input_length-T0*2){
        wedge = findWedge(i+T0*0.25,T0,1);
        if(pulseLocations) pulseLocations[pCount] = wedge;
        i = wedge;
        pCount++;
    }
    return pCount;
}

void tn_fnds_find_pulse_locations(ecantorix_note_t* note,int debug)
{
	tn_fnds_input =        &note->samples[note->preutter];
	tn_fnds_input_length = note->voiced;
	tn_fnds_midi_pitch   = note->f0;
	
	int T0 = (int)((samplerate / tn_fnds_midi_pitch)+0.5);
	int pCount=getPulseLocations(T0,0);
    int* pulseLocations = malloc(sizeof(int)*pCount);
    getPulseLocations(T0,pulseLocations);
    
    int cutoff = pulseLocations[pCount-5]+T0;//skip the last 10 pulses
    if(cutoff>=tn_fnds_input_length) cutoff=tn_fnds_input_length;
    
    //fprintf(stderr,"tn_fnds: cutoff=%i\n",cutoff);
    
    note->pCount=pCount;
    note->pulseLocations=pulseLocations;
    note->cutoff=cutoff;
    
    if(debug)
    {
    for(int i=0;i<tn_fnds_input_length;i++)
    {
        tn_fnds_input[i]*=0.5;
    }
    for(int i=0;i<pCount;i++)
    {
       tn_fnds_input[pulseLocations[i]] = 1;
    }
	}   
}

int tn_fnds_synth(ecantorix_note_t* note,float* x,float* y,int n,float* obuffer,int obuffer_length)
{
	tn_fnds_input =        &note->samples[note->preutter];
	tn_fnds_input_length = note->voiced;
	tn_fnds_midi_pitch   = note->f0;
	
	
	int T0 = (int)((samplerate / tn_fnds_midi_pitch)+0.5);
	
	float x_end = x[n-1];
	
	int offset = note->start*samplerate;
    float* output = &obuffer[offset+note->preutter];
	int output_length = x_end*samplerate;
	
	float currentTime = 0;
    float currentIndex = 0;
    float* buffer = malloc(sizeof(float)*T0*2);
    float* buffera = malloc(sizeof(float)*T0*2);
    float* bufferb = malloc(sizeof(float)*T0*2);
    while(currentTime<x_end)
    {
        currentTime += 1.0/tn_fnds_midi_pitch;
        currentIndex = currentTime*samplerate;
        
        if(currentTime>=x_end) break;
        
        float pos = interp_linear(x,y,n,currentTime);
        
        int t = (int)currentIndex;
        memset(bufferb,0,sizeof(float)*T0*2);
        memset(buffera,0,sizeof(float)*T0*2);
        float interp = copyIn(buffera,bufferb,T0*2,note->pulseLocations,note->pCount,pos);
        for(int i=0;i<T0*2;i++)
        {
            buffer[i]=buffera[i]*(1-interp)+bufferb[i]*interp;
        }
        window(buffer,T0*2);
        agc(buffer,T0*2);
        
        ola_agc(output,output_length,buffer,T0*2,t);
    }
    for(int i=0;i<output_length;i++)
    {
		output[i] *= note->max_gain;	
	}
    
    return output_length;
}
