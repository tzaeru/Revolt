/*! synth.hpp for detailed info.
 */

#include "synth.hpp"
#include <math.h>

#define PI 3.1416

Synth::Synth(float freq, int amp, int samp, PresetData * preset)
	: frequency(freq), amplitude(amp), samplerate(samp), preset_data(preset) {
	roller = 0;
	
	channel = 0;
	
	wave_length = preset_data->GetPreset(wave);
}

void Synth::Update() {
	//float increment = (2* PI) / (samplerate / (float)frequency);
  printf("hei hei");
	
	increment = wave_length / (samplerate / (float)frequency);
	/*
	delete []sample;
	sample = new Sint16[sample_length/2];
*/

	for (int i = 0; i < sample_length/2; i++) {
		if (roller >= wave_length)
			roller = 0;
		if (channel%2 == 0)
			sample[i] = wave[(int)roller] * amplitude;
		else
      sample[i] = wave[(int)roller] * amplitude;
		if (channel%2 == 0)
			roller += increment;
		channel++;
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
