/*! synth.hpp for detailed info.
 */

#include "synth.hpp"
#include <math.h>

#define PI 3.1416

Synth::Synth(int samp){

  samplerate = samp;
	roller = 0;
	
  channel = 0;
}


void Synth::Update() {
	//float increment = (2* PI) / (samplerate / (float)frequency);
	
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
