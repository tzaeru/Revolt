#ifndef NODEGROUP_HPP
#define NODEGROUP_HPP

#include "info.hpp"

#include <QFrame>

#include <QMouseEvent>
#include <QMenu>

#include <QPainter>

namespace Ui {
class NodeGroup;
}

class QSlot;
class QBasicNode;

//! QNodeGroup is a graphical unit that owns a set of nodes created within it.
/*! Basically, it also handles all the mouse and keyboard events,
  * creation of more nodes, connecting of slots of nodes, so forth.
  * Multiple NodeGroups are easy to create either as their own windows
  * or as multiwindows by not specifying a parent to the new NodeGroup.
  */
class QNodeGroup : public QFrame
{
  Q_OBJECT

public:

  explicit QNodeGroup(QWidget *parent = 0);
  ~QNodeGroup();
  /*
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    */

  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *pEvent);

  void paintEvent(QPaintEvent * pEvent);

public slots:
  //! Adds a node to the group.
  void addNode();

private:
  //! Holds a pointer to any currently mouse dragged frames, else value is NULL
  QWidget *moving;
  //! An image to which all lines between connected slots are drawn to.
  QImage *lineImage;

  //! The menu to add nodes.
  QMenu menu;

  //! List of nodes.
  vector < QBasicNode *> nodes;

  //! 1 if line is being moved, 0 if no line is being moved.
  bool moving_line;
  //! Line that is being moved.
  int line_moved;
  //! Which end of the line is being moved, 1 equals QPoint::p1, 2 equals QPoint::p2
  char lineEnd;
  //! Pointer to the slot from which a line is drawn.
  QSlot *temp_line_start;
  //! A temporary line end; Line that isn't yet connected.
  QPoint temp_line_end;

public slots:

  //! Updates the line points.
  void updateLine();
};

#endif // NODEGROUP_HPP
