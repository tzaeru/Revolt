/*! Sound hardware class.
 * This should be inherited by whatever exact class is used for communication with the soundcard.
 */

#ifndef SOUND_HARDWARE_HPP_
#define SOUND_HARDWARE_HPP_

#include "mixer.hpp"

class SoundHardware : public SoundObject {
	protected:
		/*! The sample rate. */
		int samplerate;

		/*! The mixer SoundHardware requests samples from. */
		Mixer *mixer;

		/*! Length of an individual sample. */
		int sample_length;

    /*! Amount of channels (suggesting 2 for this stage of developement) */
		int channels;
		
	public:
    SoundHardware(int samp, int length);

    void AddMixer(Mixer *_mixer) { mixer = _mixer; }

		virtual int Init();
};

#endif
