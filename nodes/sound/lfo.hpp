/*! LFO plugin for that neat pulse. */

#ifndef LFO_HPP
#define LFO_HPP

#include "sound_object.hpp"

class LFO : public SoundObject
{

private:
  /*! The frequency of the LFO. */
  float frequency;

  /*! LFO's strength. */
  int amplitude;

  /*! LFO's wave. */
  float * wave;

  /*! Length of a wave. */
  int wave_length;

  int roller;

public:
  LFO(int samp) { samplerate = samp; }
  bool Update();

  void SetWaveform(float *waveform, int length) { wave = waveform; wave_length = length; }

  /*! Sets the amplitude. */
  void SetAmplitude(int amp) { amplitude = amp; }

  /*! Sets the frequency the synth is played at. Should be used with piano rolls and everything else soon enough. */
  void SetFrequency(float freq) { frequency = freq; }

  void AddSource(SoundObject *_source);
};


#endif // LFO_HPP
