#include "mixer.hpp"

inline Sint16 Mixer::Mix(Sint16* to_mix1,  Sint16* to_mix2) {
	
	return *to_mix1 + *to_mix2; 
	
	//return ((*to_mix1 + *to_mix2) - (*to_mix1 * *to_mix2)) / max_amplitude; 
}

Sint16* Mixer::GetSample(int length) {
	
	for (int i = 0; i < source.size(); i++)
		source[i]->Update(length);
		
	for (int i = 0; i < source.size(); i++)
		samples[i] = source[i]->GetSample();
	
	if (samples.size() > 0)
		sample = samples[0];
	
	if (samples.size() > 1) {
		for (int i = 0; i < length/2; i++) {
			sample[i] = Mix(&samples[0][i], &samples[1][i]);
			}
		 }
	
	/*
	if (samples.size() > 2)
		return;*/
	
	//sample = samples[0];
	
	return sample;
}

void Mixer::AddSynth(Synth *src) {
	source.push_back(src);
	samples.push_back(NULL);
}
