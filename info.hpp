//! Holds the type of global data not fit to nodecontainer.hpp and few general purpose includes. */
#ifndef INFO_HPP
#define INFO_HPP

#include <vector>
#include <iostream>

#include <QtGui/QApplication>
#include <QTime>

using namespace std;

extern QApplication *app;


extern int currentFrame;
extern QTime myTimer;

#endif // INFO_HPP
