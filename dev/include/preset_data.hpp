/*! This is a class holding preset, generated waveforms and other data.
 * 
 * Generally, only one instance might be sufficient and the same instance
 * handled over to synths and other objects which might require this.
 * Initializing this is part of global Init()-process.
 */

#ifndef PRESET_DATA_HPP_
#define PRESET_DATA_HPP_

#include <vector>
#include <map>
#include <string>

class PresetData{
	private:
    /*! Pointers to the actual waves. */
		std::vector <float *> waves;

		std::vector <int> wave_lengths;
    /*! Can be used to access presets by a name, such as "sine", "saw" etc. */
		std::map <std::string, float*> preset_names;
	public:
		PresetData() {}
		int Init();
		
		/*! Returns length of the preset array and sets a pointer to the beginning of preset array. */
		int GetPreset(float *&preset_wave);
};

#endif
