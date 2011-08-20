#ifndef BASICNODE_HPP
#define BASICNODE_HPP

#include <QFrame>
#include <QMouseEvent>
#include <QLabel>

#include <QToolButton>

#include "info.hpp"

namespace Ui {
    class BasicNode;
}

class BasicNode : public QFrame
{
  Q_OBJECT

  /*! If true, the node is being dragged.
    */
  bool moving;

  QLabel *nameLabel;

public:
  explicit BasicNode(QWidget *parent = 0, QString name = QString("node"),
                     int in = 0, int out = 0);
  ~BasicNode();

  vector < QToolButton *> inputs;
  vector < QToolButton *> outputs;

private:
    Ui::BasicNode *ui;
};

#endif // BASICNODE_HPP
