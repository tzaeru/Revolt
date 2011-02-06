
#include "sound_hardware.hpp"


SoundHardware::SoundHardware(int samp, Mixer* mix)
	: samplerate(samp), mixer(mix){


}

int SoundHardware::Init() {
	return 1;
}
