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
  QFrame *moving;
  //! An image to which all lines between connected slots are drawn to.
  QImage *lineImage;

  //! The menu to add nodes.
  QMenu menu;

  //! 1 if line is being moved, 0 if no line is being moved.
  bool movingLine;
  //! Line that is being moved.
  int lineMoved;
  //! Which end of the line is being moved, 1 equals QPoint::p1, 2 equals QPoint::p2
  char lineEnd;
  //! All the lines between spots.
  vector < QLine > lines;
};

#endif // NODEGROUP_HPP
