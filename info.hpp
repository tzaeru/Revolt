//! Holds the type of global data not fit to nodecontainer.hpp and few general purpose includes. */
#ifndef INFO_HPP
#define INFO_HPP

#include <QtGui/QApplication>
#include <QTime>

using namespace std;

namespace node { };
using namespace node;

extern QApplication *app;


extern int currentFrame;
extern QTime myTimer;

#endif // INFO_HPP
