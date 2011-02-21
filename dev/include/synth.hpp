/*! Class for all synthesizers .
 * 
 */

#ifndef SYNTH_HPP_
#define SYNTH_HPP_

#include "preset_data.hpp"
#include "sound_object.hpp"

class Synth : public SoundObject {
	private:
		/*! The destination a sample is sent to. */
		SoundObject *destination;
		/*! The frequency a sound is to played at. */
		float frequency;
		/*! Played sound's volume. */
		int amplitude;
		/*! The sample rate. */
		int samplerate;
		
		/*! Length of a wave. */
		int wave_length;
		/*! Pointer to a waveform. */
		float *wave;
		
		/*! Pointer to PresetData object from which to requests precalced and -set data. */
		PresetData * preset_data;
		
		/*! Roll point for reading data from *wave. */
		float roller;
		
		/*! The size of step/increment to go with when iterating through wave-variable. */
		float increment;
		
	public:
		/*! Constructor for Synth.
		 * @param freq Frequency
		 * @param amp Amplitude
		 * @param samp Samplerate
		 * @param preset Pointer to PresetData object from which to requests preset stuff, such as precalced waves.
		 */
		Synth(float freq, int amp, int samp, PresetData * preset);
		
    /*! Sets the amplitude. */
    void SetAmplitude(int amp) { amplitude = amp; }

    /*! Sets the frequency the synth is played at. Should be used with piano rolls and everything else soon enough. */
		void SetFrequency(float freq) { frequency = freq; }

    /*! Sets next sample ready; As only one thread is used at the moment, this is useless method. */
    void Update();
};

#endif
