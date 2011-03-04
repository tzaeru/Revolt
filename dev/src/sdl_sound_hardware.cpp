#include "sdl_sound_hardware.hpp"

#define PI 3.1416
#include <math.h>

float iOne = 0;

Mixer* masta;

void Callback2(void *u, Uint8 *final_sample, int length) {
	Sint16* sample = masta->GetSample();
  printf("8\n");
	Sint16 *temp = (Sint16*)final_sample;
printf("9\n");
	
	for (int i = 0; i < length/2; i++)
	{
		*temp++ = sample[i];
		}
printf("10\n");
	/*
	Sint16 *p = (Sint16*)final_sample;
	
	int amplitude = 32767;
	
	float increment = (2* PI) / (48000 / (float)100); 
	
	for (;length > 0; length-=2) {
		*p++ = amplitude * sin(iOne);
		iOne += increment;
	}*/

}

SDLSoundHardware::SDLSoundHardware(int samp, int length)
  : SoundHardware(samp, length) {
}

int SDLSoundHardware::Init() {
	masta = mixer;
	channels = 2;
	mixer->SetSampleLength(sample_length * channels);

	SDL_AudioSpec r={samplerate,AUDIO_S16,2,0,sample_length,0,0,Callback2,NULL};

	SDL_OpenAudio(&r,NULL);

 	SDL_Delay(250);

 	SDL_PauseAudio(0);

	return 1;
}
