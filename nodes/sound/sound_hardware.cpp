
#include "sound_hardware.hpp"


SoundHardware::SoundHardware(int samp, int length)
  : samplerate(samp), sample_length(length){


}

int SoundHardware::Init() {
	return 1;
}
