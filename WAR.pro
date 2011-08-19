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
    QtGUI/qnodegroup.cpp \
    QtGUI/qbasicnode.cpp \
    QtGUI/qslot.cpp \
    QtGUI/mainwindow.cpp

HEADERS  += nodes/supernode.hpp \
    nodes/timer.hpp \
    nodes/slot.hpp \
    nodes/wavegraph.hpp \
    nodes/addition.hpp \
    QtGUI/qnodegroup.hpp \
    QtGUI/qbasicnode.hpp \
    info.hpp \
    QtGUI/qslot.hpp \
    QtGUI/mainwindow.hpp

FORMS    += QtGUI/mainwindow.ui \
    QtGUI/basicnode.ui
