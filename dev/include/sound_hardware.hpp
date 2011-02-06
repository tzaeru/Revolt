/*! Sound hardware class.
 * This should be inherited by whatever library is used for communication with the soundcard.
 */

#ifndef SOUND_HARDWARE_HPP_
#define SOUND_HARDWARE_HPP_

#include "mixer.hpp"

class SoundHardware {
	protected:
		/*! The sample rate. */
		int samplerate;
		/*! The mixer SoundHardware requests samples from. */
		Mixer *mixer;
		
	public:
		SoundHardware(int samp, Mixer* mix);
		
		virtual int Init();
};

#endif
