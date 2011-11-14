/*! A superclass for all objects which are able to receive and sent audio data.
  * Everything handling audio data should inherit this class. GetSample(), Update(),
  * name and associated setter/getter, channels, sample_length, sample, and so forth
  * are universal and have to be callable. */

#ifndef SOUND_OBJECT_HPP_
#define SOUND_OBJECT_HPP_

#include <string>

#include <SDL/SDL.h>

#include <vector>

#include "../supernode.hpp"


class SoundObject : public SuperNode{
	protected:
		/*! Single 'sample' to be sent to the destination. */
		Sint16 *sample;
		
		/*! The length of a sample. */
		int sample_length;
		
    /*! Keeps track which channel is ought to be given a sample for. */
    int channel;

    /*! The destination a sample is sent to. */
    std::vector <SoundObject *> destination;
    /*! Source of a sample. */
    std::vector<SoundObject *>source;

    /*! The ID of a sound object, used to remove it from the sound source(s) of other SoundObject such as the Mixer. */
    std::string name;

    /*! The sample rate. */
    int samplerate;

  public:

    SoundObject()
      : SuperNode(1, 1)
    {

    }


    /*! Adder and Remover of sound source. */
    virtual void AddSource(SoundObject * _source) { }
    //virtual void RemoveSource(SoundObject * _source) { }

    /*! Adder and Remover of destination. */
    virtual void AddDestination(SoundObject * _destination) { }
    virtual void RemoveDestination(SoundObject * _destination) { }

    /*! Getter and Setter for the name of the SoundObject instance. */
    std::string GetName() { return name; }
    void SetName(int _name) { name = _name; }

		/*! Sets the sample variable. */
		void SetSample(Sint16 *received_sample) { sample = received_sample;}
    /*! Gets a sample. */
		virtual Sint16* GetSample() { return sample; }
    /*! Sets the sample length. */
    void SetSampleLength(int length) { printf("SoundObject: Setting sample length..\n"); sample_length = length; sample = new Sint16[sample_length];}
    /*! Updates the object. */
    virtual bool Update() { }
};

#endif
