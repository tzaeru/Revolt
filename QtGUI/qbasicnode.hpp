/*! A basic node, all nodes should inherit this. */

#ifndef BASICNODE_HPP
#define BASICNODE_HPP

#include <QFrame>
#include <QMouseEvent>
#include <QLabel>
#include <QGridLayout>

#include "../nodecontainer.hpp"
#include "qslot.hpp"
#include "info.hpp"

class QSlot;

namespace node {
  class SuperNode;
}

namespace Ui {
    class BasicNode;
}

//! Basic graphical node unit, holds input/output slots and keeps track of what's connected to what.
class QBasicNode : public QFrame
{
  Q_OBJECT

public:
  explicit QBasicNode(QWidget *parent = 0, QString name = QString("node"),
                     int in = 0, int out = 0);
  ~QBasicNode();

  //! The node held by this object.
  SuperNode *node;

  //! Shows the name of the label or alternatively an icon.
  QLabel *nameLabel;

  QGridLayout *layout;

  //! Container for all inputs.
  vector < QSlot *> inputs;
  //! Container for all outputs.
  vector < QSlot *> outputs;

  //! If the node shows something visual, update as needed.
  QTimer *update_timer;

  //! Pointer to the singleton of NodeHandler.
  NodeHandler * node_handler;

  //! Create input and output slots
  void CreateSlots(int in, int out);

  //! Reimplemented to trigger the signal.
  void moveEvent ( QMoveEvent * event );

  bool eventFilter(QObject *obj, QEvent *event);

signals:
  /*! Updates the location of the slot. */
  void updateLocation();

public slots:
  //! Reimplemented to update node.
  virtual void updateNode();

private:
    Ui::BasicNode *ui;
};

#endif // BASICNODE_HPP
