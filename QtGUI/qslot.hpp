#ifndef QSLOT_HPP
#define QSLOT_HPP

#include <QToolButton>
#include <iostream>

#include "info.hpp"

class QBasicNode;

//! An input/output slot to a QNode. */
class QSlot : public QToolButton
{
private:
  Q_OBJECT

  //! ID of the input/output.
  int ID;

public:
  //! Note of ID: Each input/output slot of a node needs unique one.
  explicit QSlot(QWidget *parent = 0, int id = 0);
  ~QSlot();

  //! Slot's parent is always QBasicNode or inherits it; Here it's readily casted.
  QBasicNode *node_parent;

  //! If the slot is of 'input' type, here's the slot it might be connected to.
  QSlot *connected_output_slot;

  //! If the slot is of 'output' type, here are the slots it might be connected to.
  vector <QSlot *> connected_input_slots;

  void setID(int id) { ID = id; }
  int getID() { return ID; }

  //! Basically throws the event to NodeGroup.
  void mousePressEvent(QMouseEvent *event);

  //! Adds a connection.
  void addConnection(QSlot *target);

  //! Removes a connection.
  void removeConnection(QSlot *target);

  //! Removes all connections.
  void removeConnections();
};

#endif // QSLOT_HPP
