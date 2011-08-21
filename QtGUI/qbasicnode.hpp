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

//! Basic graphical node unit, holds input/output slots and keeps track of what's connected to what.
class QBasicNode : public QFrame
{
  Q_OBJECT

  //! Shows the name of the label or alternatively an icon.
  QLabel *nameLabel;

public:
  explicit QBasicNode(QWidget *parent = 0, QString name = QString("node"),
                     int in = 0, int out = 0);
  ~QBasicNode();

  //! Container for all inputs.
  vector < QToolButton *> inputs;
  //! Container for all outputs.
  vector < QToolButton *> outputs;

private:
    Ui::BasicNode *ui;
};

#endif // BASICNODE_HPP
