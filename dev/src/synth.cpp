/*! synth.hpp for detailed info.
 */

#include "synth.hpp"
#include <math.h>

#define PI 3.1416

Synth::Synth(float freq, int amp, int samp, PresetData * preset)
	: frequency(freq), amplitude(amp), samplerate(samp), preset_data(preset) {
	roller = 0;
	
	sample = new Sint16[512];
	
	wave_length = preset_data->GetPreset(wave);
}

void Synth::Update(int length) {
	//float increment = (2* PI) / (samplerate / (float)frequency);
	
	increment = wave_length / (samplerate / (float)frequency);
	
	delete []sample;
	sample = new Sint16[length/2];


	for (int i = 0; i < length/2; i++) {
		if (roller >= wave_length)
			roller = 0;
		
		sample[i] = wave[(int)roller] * amplitude;
		roller += increment;
		/*
		sample[i] = (Sint16)(amplitude * sin(roll));
		roll += increment;*/
	}
	
}

/*
void sa(void *u, Uint8 *s, int l) {
	Sint16 *p = (Sint16*)s;
	

	increment = (2* PI) / (SAMPLERATE / (float)frequency); 
	
	for (;l > 0; l-=2) {
		*p++ = amplitude * sin(iOne);
		iOne += increment;
	}
	
}
*/
