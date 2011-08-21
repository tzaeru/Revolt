#ifndef QSLOT_HPP
#define QSLOT_HPP

#include <QToolButton>

class QSlot : public QToolButton
{
private:
  Q_OBJECT

  int ID;

public:
  explicit QSlot(QWidget *parent = 0, int id = 0);
  ~QSlot();

  void setID(int id) { ID = id; }
  int getID() { return ID; }

  void mousePressEvent(QMouseEvent *event);
};

#endif // QSLOT_HPP
