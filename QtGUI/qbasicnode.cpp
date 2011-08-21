#include "qbasicnode.hpp"
#include "ui_basicnode.h"

QBasicNode::QBasicNode(QWidget *parent, QString name, int in, int out) :
    QFrame(parent),
    ui(new Ui::BasicNode)
{
  ui->setupUi(this);

  this->nameLabel = new QLabel(this);
  this->nameLabel->setText(name);
  this->nameLabel->move(1, 13);
  this->nameLabel->show();

  this->setObjectName(QString("BasicNode"));

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
