/*! Wrapper is a class which holds all the SoundObject instances and hardware.
  * Always use Wrapper when creating UIs, since Wrapper is needed for over the
  * internet communication, communication between different UIs and for
  * saving the project! */

#ifndef WRAPPER_HPP
#define WRAPPER_HPP

#include <vector>
#include <map>
#include <string>

/* Audio related things. */
#include "preset_data.hpp"
#include "synth.hpp"
#include "sdl_sound_hardware.hpp"
#include "mixer.hpp"
/**********************/

class Wrapper{
private:
  SoundHardware *sound_hardware;

public:
  std::map<std::string, SoundObject *> sound_objects;

  void AddSoundHardware(SoundHardware * _sound_hardware) { sound_hardware = _sound_hardware; }

  void AddSoundObject(std::string name, SoundObject * sound_object)
  { sound_objects.insert(std::pair<std::string, SoundObject*>(name, sound_object) ); }

  void RemoveSoundObject();
};

#endif // WRAPPER_HPP
