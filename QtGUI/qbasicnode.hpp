/*! A basic node, all nodes should inherit this. */

#ifndef BASICNODE_HPP
#define BASICNODE_HPP

#include <QFrame>
#include <QMouseEvent>
#include <QLabel>

#include "qslot.hpp"

#include "info.hpp"

namespace Ui {
    class BasicNode;
}

class QBasicNode : public QFrame
{
  Q_OBJECT

  /*! If true, the node is being dragged.
    */
  bool moving;

  QLabel *nameLabel;

public:
  explicit QBasicNode(QWidget *parent = 0, QString name = QString("node"),
                     int in = 0, int out = 0);
  ~QBasicNode();

  vector < QToolButton *> inputs;
  vector < QToolButton *> outputs;

private:
    Ui::BasicNode *ui;
};

#endif // BASICNODE_HPP
