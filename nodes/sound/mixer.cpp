#include "mixer.hpp"

inline Sint16 Mixer::Mix(Sint16* to_mix1,  Sint16* to_mix2) {
	
	return *to_mix1 + *to_mix2; 
	
	//return ((*to_mix1 + *to_mix2) - (*to_mix1 * *to_mix2)) / max_amplitude; 
}

Sint16* Mixer::GetSample() {
printf("5\n");
  for (unsigned int i = 0; i < source.size(); i++)
		source[i]->Update();
		
  for (unsigned int i = 0; i < source.size(); i++)
		samples[i] = source[i]->GetSample();
  printf("6\n");
	if (samples.size() > 0)
		sample = samples[0];
	
	if (samples.size() > 1) {
		for (int i = 0; i < sample_length/2; i++) {
			sample[i] = Mix(&samples[0][i], &samples[1][i]);
			}
		 }
    printf("7\n");
	/*
	if (samples.size() > 2)
		return;*/
	
	//sample = samples[0];
	
	return sample;
}

void Mixer::AddSource(SoundObject * _source) {
  printf("MIXER:\n");
  printf("  Adding Synth..\n  Creating source..\n");
  _source->SetSampleLength(sample_length);
  printf("  Linking source..\n");
  source.push_back(_source);
  printf("  Creating empty sample array..\n");
	samples.push_back(NULL);
}
