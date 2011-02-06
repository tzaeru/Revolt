#include <math.h>
#include "preset_data.hpp"

#define PI 3.14159265

int PresetData::Init() {
	/* Creates a sine wave. */
	float *sine = NULL;
	int length = 10000;
	wave_lengths.push_back(length);
	sine = new float[length];
	
	float step_size = (2*PI)/length;
	
	for (int i = 0; i < length; i++) {
		sine[i] = sin(i * step_size);
	}
	
	waves.push_back(sine);
	
	return 0;
}

int PresetData::GetPreset(float *&preset_d) {
	for (int i = 0; i < wave_lengths[0]; i++) {
	}
	preset_d = *&waves[0];
	return wave_lengths[0];
}
