/*! Mixer class combines the output of all synths.
 * SoundHardware's callback function requests
 * the mixer to give a final sample. */
#ifndef MIXER_HPP_
#define MIXER_HPP_

#include <SDL/SDL.h>
#include <vector>

#include "sound_object.hpp"
#include "synth.hpp"

class Mixer : public SoundObject{
	private:
    std::vector<Sint16 *>samples;
		
		int max_amplitude;
	public:
    /*! Overrides SoundObject's AddSource() */
    void AddSource(SoundObject * _source);

    Mixer (int max_amp) : max_amplitude(max_amp) {}
		
		Sint16* GetSample();
		
		inline Sint16 Mix(Sint16* to_mix1, Sint16* to_mix2);
};
#endif
