#include "qslot.hpp"
#include "info.hpp"

QSlot::QSlot(QWidget *parent, int id)
  : QToolButton(parent)
{
  ID = id;
}

QSlot::~QSlot()
{

}

void QSlot::mousePressEvent(QMouseEvent *event)
{
  QToolButton::mousePressEvent(event);

  QCoreApplication::sendEvent(this->parent()->parent(), (QEvent*)event);
}
