 CONFIG += qt lsdl debug
 INCLUDEPATH += include
 INCLUDEPATH += QtGUI
 HEADERS += include/synth.hpp \
    include/sound_hardware.hpp \
    include/sound_object.hpp include/sdl_sound_hardware.hpp include/mixer.hpp include/preset_data.hpp \
    QtGUI/mainwindow.h \
    include/wrapper.hpp \
    QtGUI/mixerwidget.h \
    QtGUI/synthwidget.h \
    QtGUI/waveformwidget.h
 HEADERS +=
 SOURCES += src/synth.cpp src/sound_hardware.cpp src/sdl_sound_hardware.cpp src/mixer.cpp src/preset_data.cpp \
    QtGUI/mainwindow.cpp \
    src/wrapper.cpp \
    QtGUI/mixerwidget.cpp \
    QtGUI/synthwidget.cpp \
    QtGUI/waveformwidget.cpp
 SOURCES += src/main.cpp
 SOURCES +=
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

FORMS += \
    QtGUI/mainwindow.ui \
    QtGUI/mixerwidget.ui \
    QtGUI/synthwidget.ui \
    QtGUI/waveformwidget.ui
