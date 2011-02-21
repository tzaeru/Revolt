/*! main.cpp is not supposed to link mixer, hardware and synths together, but this shall do for now. */

#include <iostream>
#include <SDL/SDL.h>

/* GUI related things */
#include <QApplication>
#include "mainwindow.h"


/* Audio related things. */
#include "preset_data.hpp"
#include "synth.hpp"
#include "sdl_sound_hardware.hpp"
#include "mixer.hpp"
/**********************/

int main(int argc, char *argv[]) {
	
	QApplication app(argc, argv);

	MainWindow GUI;

	GUI.show();
	
	app.exec();
	
	return 0;
}
