#-------------------------------------------------
#
# Project created by QtCreator 2011-08-10T11:43:13
#
#-------------------------------------------------

QT       += core gui

TARGET = WAR
TEMPLATE = app


SOURCES += main.cpp\
    nodes/supernode.cpp \
    nodes/timer.cpp \
    nodes/slot.cpp \
    nodes/wavegraph.cpp \
    nodes/addition.cpp \
    QtGUI/nodegroup.cpp \
    QtGUI/mainwindow.cpp \
    QtGUI/basicnode.cpp

HEADERS  += nodes/supernode.hpp \
    nodes/timer.hpp \
    nodes/slot.hpp \
    nodes/wavegraph.hpp \
    nodes/addition.hpp \
    QtGUI/nodegroup.hpp \
    QtGUI/basicnode.hpp \
    QtGUI/mainwindow.hpp \
    info.hpp

FORMS    += QtGUI/mainwindow.ui \
    QtGUI/basicnode.ui
