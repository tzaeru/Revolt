#-------------------------------------------------
#
# Project created by QtCreator 2011-08-10T11:43:13
#
#-------------------------------------------------

QT       += core gui opengl

CONFIG += debug E

TARGET = WAR
TEMPLATE = app

LIBS += -lSDL


SOURCES += main.cpp\
    nodes/supernode.cpp \
    nodes/timer.cpp \
    nodes/slot.cpp \
    nodes/wavegraph.cpp \
    nodes/addition.cpp \
    QtGUI/qnodegroup.cpp \
    QtGUI/qbasicnode.cpp \
    QtGUI/mainwindow.cpp \
    QtGUI/qslot.cpp \
    nodecontainer.cpp \
    QtGUI/qcounter.cpp \
    QtGUI/qopenglnode.cpp \
    nodes/sound/wrapper.cpp \
    nodes/sound/waveform.cpp \
    nodes/sound/synth.cpp \
    nodes/sound/sound_hardware.cpp \
    nodes/sound/sdl_sound_hardware.cpp \
    nodes/sound/preset_data.cpp \
    nodes/sound/mixer.cpp \
    nodes/sound/lfo.cpp

HEADERS  += nodes/supernode.hpp \
    nodes/timer.hpp \
    nodes/slot.hpp \
    nodes/wavegraph.hpp \
    nodes/addition.hpp \
    QtGUI/qnodegroup.hpp \
    QtGUI/qbasicnode.hpp \
    QtGUI/mainwindow.hpp \
    info.hpp \
    QtGUI/qslot.hpp \
    nodecontainer.hpp \
    QtGUI/qcounter.hpp \
    QtGUI/qopenglnode.hpp \
    nodes/sound/wrapper.hpp \
    nodes/sound/waveform.hpp \
    nodes/sound/synth.hpp \
    nodes/sound/sound_object.hpp \
    nodes/sound/sound_hardware.hpp \
    nodes/sound/sdl_sound_hardware.hpp \
    nodes/sound/preset_data.hpp \
    nodes/sound/mixer.hpp \
    nodes/sound/lfo.hpp

FORMS    += QtGUI/mainwindow.ui \
    QtGUI/basicnode.ui \
    QtGUI/qcounter.ui
