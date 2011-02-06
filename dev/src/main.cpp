/*! main.cpp is not supposed to link mixer, hardware and synths together, but this shall do for now. */

#include <iostream>
#include <SDL/SDL.h>

#include "preset_data.hpp"
#include "synth.hpp"
#include "sdl_sound_hardware.hpp"
#include "mixer.hpp"

int max_amp = 32767;

//int argc, char *argv[]
int main() {
	PresetData preset_data;
	preset_data.Init();
	
	Synth *synth = new Synth(100, max_amp/4, 48000, &preset_data);
	Synth *synth2 = new Synth(440, max_amp/4, 48000, &preset_data);
	
	Mixer *mixer = new Mixer(max_amp);
	mixer->AddSynth(synth);
	mixer->AddSynth(synth2);
	
	SoundHardware* sound_hardware = new SDLSoundHardware(48000, mixer);
	sound_hardware->Init();

	int time = SDL_GetTicks();
	
	for (int i = SDL_GetTicks(); i < time + 8000; i = SDL_GetTicks()) {
		if (i%1000 > 750 || i%2000 > 1500) {
			synth->SetFrequency(124);
			synth2->SetFrequency(460);
	}
		else {
			synth->SetFrequency(100);
			synth2->SetFrequency(440);
	}
		
	}

	return 0;
}
