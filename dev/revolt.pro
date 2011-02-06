 CONFIG += qt lsdl debug
 INCLUDEPATH += include
 HEADERS += include/synth.hpp include/sound_hardware.hpp include/sound_object.hpp include/sdl_sound_hardware.hpp include/mixer.hpp include/preset_data.hpp
 SOURCES += src/synth.cpp src/sound_hardware.cpp src/sdl_sound_hardware.cpp src/mixer.cpp src/preset_data.cpp
 SOURCES += src/main.cpp
 LIBS += -lSDL
 TARGET = ../revolt
 
 OBJECTS_DIR = tmp
 
 win32 {
     SOURCES +=
 }
 unix {
     SOURCES +=
 }
 !exists( src/main.cpp ) {
     error( "No main.cpp file found" )
 }
 win32:debug {
     CONFIG += console
 }
