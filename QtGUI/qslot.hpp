#ifndef QSLOT_HPP
#define QSLOT_HPP

#include <QToolButton>

#include "info.hpp"

//! An input/output slot to a QNode. */
class QSlot : public QToolButton
{
private:
  Q_OBJECT

  //! ID of the input/output.
  int ID;

public:
  //! Node of ID: Each input/output slot of a node needs unique one.
  explicit QSlot(QWidget *parent = 0, int id = 0);
  ~QSlot();

  //! If the slot connects to another (only output slots have a connection!) the connected slot is pointed to here.
  vector < QSlot *> connected_slots;

  void setID(int id) { ID = id; }
  int getID() { return ID; }

  //! Basically throws the event to NodeGroup.
  void mousePressEvent(QMouseEvent *event);
};



#endif // QSLOT_HPP
