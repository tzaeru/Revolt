/*! A superclass for all objects which are able to receive and sent audio data. */

#ifndef SOUND_OBJECT_HPP_
#define SOUND_OBJECT_HPP_

#include <SDL/SDL.h>

class SoundObject{
	protected:
		/*! Single 'sample' to be sent to the destination. */
		Sint16 *sample;
		
	public:
		/*! Sets the sample variable. */
		void SetSample(Sint16 *received_sample) { sample = received_sample;}
		/* Gets a sample. */
		Sint16* GetSample() { return sample; }
};

#endif
