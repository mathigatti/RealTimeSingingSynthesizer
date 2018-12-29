#include "config.h"

#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <espeak-ng/espeak_ng.h>
#include <espeak-ng/speak_lib.h>
#include <espeak-ng/encoding.h>

#include "dictionary.h"
#include "intonation.h"
#include "mbrola.h"
#include "setlengths.h"
#include "synthdata.h"
#include "wavegen.h"

#include "phoneme.h"
#include "voice.h"
#include "synthesize.h"
#include "translate.h"
#include "ecantorix.h"
#include "carray.h"
#include "tn_fnds.h"

#define NOTES_COUNT 128

int singing_mode=0;

static double sinsy_notepos = 0;
double sinsy_tempo = 120.0;

static int sample_pos=0;
static CArray notes = 0;
static ecantorix_sample_type_t current_sample=SAMPLE_NONE;
static int current_sample_length=0;
static int current_syllable=0;
static int preutter=0;
static int voiced=0;

void sync_ecantorix_Note(ecantorix_note_t* note);

extern double midi_pitch;

static ecantorix_note_t* new_note(size_t duration,size_t pitch)
{
	ecantorix_note_t* note = malloc(sizeof(ecantorix_note_t));
	memset(note,0,sizeof(ecantorix_note_t));
	double length = duration*60.0/sinsy_tempo/960.0;
	note->start = sinsy_notepos;
    note->end = sinsy_notepos+length;
    note->pitch = pitch;
    sinsy_notepos+=length;
    return note;
}

static ecantorix_note_t* current_note=0;
int sinsy_sample_max = 1024*1024*1024/sizeof(float);//1M buffer

void sinsy_sample(short sample, ecantorix_sample_type_t type)
{
	if(current_note && sample_pos<sinsy_sample_max) {

		current_note->samples[sample_pos] = sample/32768.0;
		sample_pos++;

		if(current_sample!=type && current_sample!=SAMPLE_NONE)
		{
			fprintf(stderr,"\nsample_type %i %i\n",current_sample,current_sample_length);
			if(current_sample==SAMPLE_VOICED) {
				current_syllable++;
				if(current_syllable==1){
					voiced = current_sample_length;
				}
			}
			if(current_syllable==0) {
				preutter+=current_sample_length;
			}
			
			current_sample_length = 0;	
		}
		current_sample=type;
		current_sample_length++;
	}
	else
	{
		fprintf(stderr,"dropping samples\n");
		abort();
	}
}

double midi_freq(unsigned char m) {
    /* converts a MIDI note number to a frequency
       <http://en.wikipedia.org/wiki/MIDI_Tuning_Standard> */
    return 440 * pow(2, (double)(m-69)/12);
}

#pragma GCC visibility push(default)

ESPEAK_NG_API espeak_ng_STATUS sinsy_ng_Init(double tempo)
{
	sinsy_tempo = tempo;
	notes = CArrayNew();
    singing_mode = 1;
	return 0;
}

ESPEAK_NG_API espeak_ng_STATUS sinsy_ng_addNote(size_t duration,
                                                const char* lyric,
                                                size_t pitch,
                                                bool accent,
                                                bool staccato,
                                                sinsy_ng_SlurType slurType,
                                                sinsy_ng_SyllabicType syllabicType,
                                                bool breath)
{

    ecantorix_note_t* note = new_note(duration,pitch);
    strncpy0(note->lyric, lyric, sizeof(note->lyric)); //use strdup here
    note->staccato = staccato;
    note->accent = accent;
    note->slurType = slurType;
    note->syllabicType = syllabicType;
    note->breath = breath;
    current_note = note;
    note->samples = malloc(sizeof(float)*sinsy_sample_max);
    sample_pos = 0;
    current_syllable=0;
	preutter=0;
	voiced=0;
	note->f0 = midi_freq(note->pitch);
	if(note->lyric[0]==toupper(note->lyric[0]))
	{
		fprintf(stderr,">>> %s\n",note->lyric);
		note->max_gain=1.2;
	}
	else
	{
		fprintf(stderr,"=== %s\n",note->lyric);
		note->max_gain=0.5;
	}
    sync_ecantorix_Note(note);
    sinsy_sample(0, SAMPLE_NONE);
    note->samples = realloc (note->samples, sample_pos * sizeof(float));
    note->samples_count = sample_pos;
    note->preutter=preutter;
    note->voiced=voiced;
    note->syllables=current_syllable;

    fprintf(stderr,"\nNOTE SILLABLES%d\n",note->syllables);

    if(note->syllables>=1) tn_fnds_find_pulse_locations(note,0);
    current_note = 0;
    CArrayAdd(notes,(void*)note);
    return 0;
    
}


ESPEAK_NG_API espeak_ng_STATUS sinsy_ng_addRest(size_t duration)
{
    CArrayAdd(notes,(void*)new_note(duration,255));
    return 0;   
}

ESPEAK_NG_API float* sinsy_ng_getAudioData(int* length)
{   
	ecantorix_note_t* last_note = CArrayObjectAtIndex(notes,CArrayCount(notes)-1);
	int song_length = last_note->end*samplerate;
    float* ret = malloc(sizeof(float)*song_length);
    memset(ret,0,sizeof(float)*song_length);
    *length = song_length;

	fprintf(stderr,"entro aca 0\n");

    
    for(unsigned int i=1;i<CArrayCount(notes);i++)
	{
		ecantorix_note_t* note0 = CArrayObjectAtIndex(notes,i-1);
		ecantorix_note_t* note1 = CArrayObjectAtIndex(notes,i);
		float shift = note1->preutter*1.0/samplerate;
		note0->end -= shift;
		note1->start -= shift;
	}
    
	for(unsigned int i=0;i<CArrayCount(notes);i++)
	{
		fprintf(stderr,"entro aca 1\n");

		ecantorix_note_t* note = CArrayObjectAtIndex(notes,i);

		fprintf(stderr,"info pitch: %d, syllables: %d, lyrics: %s\n",note->pitch,note->syllables,note->lyric);
		if(note->pitch!=255 && note->syllables>=1)
		{
			fprintf(stderr,"entro aca 2\n");

			//copy left voiced segment
			int offset = note->start*samplerate;
			int cutoff = note->end*samplerate;
			int notelength = cutoff-offset;
			int p0 = note->preutter;
			int p1 = p0+note->voiced;
			int p2 = note->samples_count;
			int coda_length = p2-p1;
			for(int i=0;i<p0;i++)
			{
				ret[i+offset]=note->samples[i];
			}
			#ifdef DEBUG_INPUT
			for(int i=p0;i<p1;i++)
			{
				ret[i+offset]=note->samples[i];
			}
			for(int i=p1;i<p2;i++)
			{
				ret[i+offset]=note->samples[i];
			}
			fprintf(stderr,"silence=%i\n",notelength-note->samples_count);
			#else
			float voiced_input = note->cutoff*1.0/samplerate;
			float voiced_output = (note->end-note->start)-(coda_length+preutter)*1.0/samplerate;
			float point1 = 0.001*40;
			
			int coda_start = 0;
			
			if(point1<voiced_input && point1<voiced_output)
			{
				float x[3] = {0.0,point1,voiced_output};
				float y[3] = {0.0,point1,voiced_input};	
				coda_start = tn_fnds_synth(note,x,y,3,ret,song_length);	
			}
			else
			{
				float x[2] = {0.0,voiced_output};
				float y[2] = {0.0,voiced_input};
				coda_start = tn_fnds_synth(note,x,y,2,ret,song_length);	
			}
			
			for(int i=p1;i<p2;i++)
			{
				ret[i+offset-p1+preutter+coda_start]=note->samples[i];
			}
			#endif
		}
	}
	
	return ret;
}
