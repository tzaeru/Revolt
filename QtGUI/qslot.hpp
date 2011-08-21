#ifndef QSLOT_HPP
#define QSLOT_HPP

#include <QToolButton>

//! An input/output slot to a QNode. */
class QSlot : public QToolButton
{
private:
  Q_OBJECT

  //! ID of the input/output, needed by Node.
  int ID;

public:
  //! Node of ID: Each input/output slot of a node needs unique one, but two nodes can share same IDs between their slots.
  explicit QSlot(QWidget *parent = 0, int id = 0);
  ~QSlot();

  void setID(int id) { ID = id; }
  int getID() { return ID; }

  //! Basically throws the event to NodeGroup.
  void mousePressEvent(QMouseEvent *event);
};

#endif // QSLOT_HPP
