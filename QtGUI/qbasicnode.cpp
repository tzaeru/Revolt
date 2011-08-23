#include <QTimer>

#include "qbasicnode.hpp"
#include "ui_basicnode.h"

#include "../nodes/addition.hpp"
#include "../nodes/timer.hpp"

QBasicNode::QBasicNode(QWidget *parent, QString name, int in, int out) :
    QFrame(parent),
    ui(new Ui::BasicNode)
{
  ui->setupUi(this);

  this->nameLabel = new QLabel(this);
  this->nameLabel->setText(name);
  this->nameLabel->move(1, 13);
  this->nameLabel->show();

  if (name == QString("addition"))
    node = new Addition(in, out);
  else if (name == QString("timer"))
    node = new Timer(in, out);


  this->setObjectName(QString("BasicNode"));
  this->setAccessibleName(name);

  if (name == QString("addition"))
  {
    update_timer = new QTimer(this);
    connect(update_timer, SIGNAL(timeout()), this, SLOT(updateNode()));
    update_timer->start(1000/40);
  }

  /*! Creating input and then output slots. */
  QRect rect;

  int i, j;

  for (i = 0; i < in; i++)
  {
    inputs.push_back(new QSlot(this, i));

    rect.setX(this->x() + 1 + i*13);
    rect.setWidth(12);
    rect.setY(this->y() + 1);
    rect.setHeight(12);

    inputs[i]->setChecked (false);
    inputs[i]->setGeometry(rect);
    inputs[i]->setObjectName("Slot");
    inputs[i]->setAccessibleName("input");
    inputs[i]->setID(i);
    inputs[i]->show();
  }

  for (j = 0; j < out; j++)
  {
    outputs.push_back(new QSlot(this, j));

    rect.setX(this->x() + 1 + j*13);
    rect.setWidth(12);
    rect.setY((this->y() + this->height()) - 14);
    rect.setHeight(12);

    outputs[j]->setChecked (false);
    outputs[j]->setGeometry(rect);
    outputs[j]->setObjectName("Slot");
    outputs[j]->setAccessibleName("output");
    outputs[j]->setID(j);
    outputs[j]->show();
  }

  if (nameLabel->width() > i * 13 && nameLabel->width() > j * 13)
    this->resize(nameLabel->width() + 13, nameLabel->height() + 28);
  else if (i * 13 > j * 13)
  {
    this->resize(i * 13 + 13, nameLabel->height() + 28);
  }
  else
    this->resize(j * 13 + 13, nameLabel->height() + 28);
}

QBasicNode::~QBasicNode()
{
    delete ui;
}

void QBasicNode::updateNode()
{
  if (nameLabel->text() == QString("addition"))
  {
    node->Update();

    this->update();
  }
}

void QBasicNode::moveEvent( QMoveEvent * event )
{

  updateLocation();
}
