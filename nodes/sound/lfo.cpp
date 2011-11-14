#include "lfo.hpp"

bool LFO::Update() {
  //float increment = (2* PI) / (samplerate / (float)frequency);

  int increment = wave_length / (samplerate / (float)frequency);
  /*
  delete []sample;
  sample = new Sint16[sample_length/2];
*/
  printf("1\n");
  source[0]->Update();
printf("2\n");
  sample = source[0]->GetSample();
printf("3\n");
  for (int i = 0; i < sample_length/2; i++) {
    if (roller >= wave_length)
      roller = 0;
    if (channel%2 == 0)
      sample[i] = sample[i] * (1 + (wave[(int)roller] * (float)amplitude/(float)32768));
    else
      sample[i] = sample[i] * (1 + (wave[(int)roller] * (float)amplitude/(float)32768));
    if (channel%2 == 0)
      roller += increment;
    channel++;
    /*
    sample[i] = (Sint16)(amplitude * sin(roll));
    roll += increment;*/
  }
printf("4\n");
}


void LFO::AddSource(SoundObject * _source) {
  printf("LFO:\n");
  printf("  Adding Synth..\n  Creating source..\n");
  _source->SetSampleLength(sample_length);
  printf("  Linking source..\n");
  source.push_back(_source);
}
