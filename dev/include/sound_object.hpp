/*! A superclass for all objects which are able to receive and sent audio data. */

#ifndef SOUND_OBJECT_HPP_
#define SOUND_OBJECT_HPP_

#include <string>

#include <SDL/SDL.h>


class SoundObject{
	protected:
		/*! Single 'sample' to be sent to the destination. */
		Sint16 *sample;
		
		/*! The length of a sample. */
		int sample_length;
		
    /*! Keeps track which channel is ought to be given a sample for. */
    int channel;
		
  public:
    /*! The ID of a sound object, used to remove it from the sound source(s) of other SoundObject such as the Mixer. */
    std::string name;
    std::string GetName() { return name; }
    void SetName(int _name) { name = _name; }

		/*! Sets the sample variable. */
		void SetSample(Sint16 *received_sample) { sample = received_sample;}
    /*! Gets a sample. */
		virtual Sint16* GetSample() { return sample; }
    /*! Sets the sample length. */
    void SetSampleLength(int length) { printf("SoundObject: Setting sample length..\n"); sample_length = length; sample = new Sint16[sample_length];}
    /*! Updates the object. */
    virtual void Update() { }
};

#endif
