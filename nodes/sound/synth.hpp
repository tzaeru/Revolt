/*! Class for all synthesizers .
 * 
 */

#ifndef SYNTH_HPP_
#define SYNTH_HPP_

#include "waveform.hpp"
#include "sound_object.hpp"

class Synth : public SoundObject {
	private:
		/*! The frequency a sound is to played at. */
		float frequency;

		/*! Played sound's volume. */
		int amplitude;
		
		/*! Length of a wave. */
    int wave_length;

		/*! Pointer to a waveform. */
		float *wave;
		
		/*! Roll point for reading data from *wave. */
		float roller;
		
		/*! The size of step/increment to go with when iterating through wave-variable. */
		float increment;
		
	public:
		/*! Constructor for Synth.
		 * @param samp Samplerate
		 */
    Synth(int samp);

    /*! Gives a pointer to the waveform of the synth.
        @param wave Pointer to waveform
        @param wave_length Length of the waveform in samples. */
    void SetWaveform(float *waveform, int length) { wave = waveform; wave_length = length; }
		
    /*! Sets the amplitude. */
    void SetAmplitude(int amp) { amplitude = amp; }

    /*! Sets the frequency the synth is played at. Should be used with piano rolls and everything else soon enough. */
		void SetFrequency(float freq) { frequency = freq; }

    /*! Sets next sample ready; As only one thread is used at the moment, this is useless method. */
    bool Update();
};

#endif
