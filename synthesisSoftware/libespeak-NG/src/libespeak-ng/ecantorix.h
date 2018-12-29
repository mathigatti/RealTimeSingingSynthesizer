#ifndef ESPEAK_NG_ECANTORIX_H
#define ESPEAK_NG_ECANTORIX_H

typedef enum 
{
	SAMPLE_NONE=0,
	SAMPLE_VOICED=1,
	SAMPLE_UNVOICED=2,
	SAMPLE_SILENCE=3,
} ecantorix_sample_type_t;

typedef struct
{
    float start;
    float end;
    char lyric[128];
    size_t pitch;
    int accent;
    int staccato;
    sinsy_ng_SlurType slurType;
    sinsy_ng_SyllabicType syllabicType;
    bool breath;
    //generated audio data
    float* samples;
    int samples_count;
    //otoing
    int syllables; //normally one
	int preutter;  //samples
	int voiced;    //samples
	//tn_fnds
	float f0;      //Hz
	int pCount;		
    int* pulseLocations;
	int cutoff;
	//vocal dynamics
	float max_gain;
} ecantorix_note_t;

void sinsy_sample(short sample, ecantorix_sample_type_t type);
void sinsy_set_midi_freq(size_t m);


#endif
