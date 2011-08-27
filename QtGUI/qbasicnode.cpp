#include <QTimer>

#include "qbasicnode.hpp"
#include "ui_basicnode.h"

#include "../nodes/addition.hpp"
#include "../nodes/timer.hpp"

QBasicNode::QBasicNode(QWidget *parent, QString name, int in, int out) :
  QFrame(parent)
{
  node_handler = NodeHandler::Instance();

  layout = new QGridLayout;
  layout->setSpacing(2);

  this->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
  this->setAutoFillBackground(true);

  this->nameLabel = new QLabel(this);
  this->nameLabel->setText(name);

  nameLabel->installEventFilter(this);

  if (name == QString("addition"))
    node = node_handler->create_node("Addition");
  else if (name == QString("timer"))
    node = node_handler->create_node("Timer");
  else if (name == QString("counter"))
    node = new SuperNode(1, 0);


  this->setObjectName(QString("BasicNode"));
  this->setAccessibleName(name);

  if (name == QString("counter"))
  {
    update_timer = new QTimer(this);
    connect(update_timer, SIGNAL(timeout()), this, SLOT(updateNode()));
    update_timer->start(1000/4);
  }

  /*! Creating input and then output slots. */
  CreateSlots(in, out);

  layout->addWidget(nameLabel, 1, 0);

  this->setLayout(layout);
  layout->activate();
  layout->setMargin(1);
  this->show();
}

void QBasicNode::CreateSlots(int in, int out)
{
  int i, j;

  for (i = 0; i < in; i++)
  {
    inputs.push_back(new QSlot(this, i));
    inputs[i]->setMinimumSize(12, 12);
    inputs[i]->setMaximumSize(12, 12);
    inputs[i]->setChecked (false);
    inputs[i]->setObjectName("Slot");
    inputs[i]->setAccessibleName("input");
    inputs[i]->setID(i);

    layout->addWidget(inputs[i], 0, i, Qt::AlignLeft | Qt::AlignTop);
  }

  for (j = 0; j < out; j++)
  {
    outputs.push_back(new QSlot(this, j));
    outputs[j]->setMinimumSize(12, 12);
    outputs[j]->setMaximumSize(12, 12);
    outputs[j]->setObjectName("Slot");
    outputs[j]->setAccessibleName("output");
    outputs[j]->setID(j);

    layout->addWidget(outputs[j], 2, j);
  }

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

bool QBasicNode::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseButtonPress)
  {
    QCoreApplication::sendEvent(this->parent(), (QEvent*)event);
    return true;
  }
  else
  {
    // standard event processing
    return QObject::eventFilter(obj, event);
  }
}


QBasicNode::~QBasicNode()
{
  delete node;
  delete ui;
}
