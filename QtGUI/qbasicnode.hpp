/*! A basic node, all nodes should inherit this. */

#ifndef BASICNODE_HPP
#define BASICNODE_HPP

#include <QFrame>
#include <QMouseEvent>
#include <QLabel>
#include <QGridLayout>
#include <QMenu>

#include "info.hpp"

class QSlot;
class NodeHandler;

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
  explicit QBasicNode(QWidget *parent = 0, NodeHandler* handler = NULL, QString name = QString("node"),
                     int in = 0, int out = 0);
  virtual ~QBasicNode();

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

  //! Pointer to the NodeHandler to which nodes are to be created.
  NodeHandler * node_handler;

  //! The menu to handle the node.
  QMenu menu;

  //! Create input and output slots
  void CreateSlots(int in, int out);

  //! Reimplemented to trigger the signal.
  void moveEvent ( QMoveEvent * event );

  bool eventFilter(QObject *obj, QEvent *event);

  //! Reimplemented for grabbing right house button.
  void mouseReleaseEvent(QMouseEvent *event);

signals:
  /*! Updates the location of the slot. */
  void updateLocation();

public slots:
  /*! Removes self, calls NodeGroup. */
  void removeSelf();

  //! Reimplemented to update node.
  virtual void updateNode();

private:
    Ui::BasicNode *ui;
};

#endif // BASICNODE_HPP
