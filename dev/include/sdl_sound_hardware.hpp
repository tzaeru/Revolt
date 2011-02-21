/*! Access to sound hardware via SDL */

#ifndef SDL_SOUND_HARDWARE_HPP_
#define SDL_SOUND_HARDWARE_HPP_

#include <SDL/SDL.h>
#include "sound_hardware.hpp"

class SDLSoundHardware : public SoundHardware {
	public:
    SDLSoundHardware(int samp, int length);
		
		int Init();
};

#endif
