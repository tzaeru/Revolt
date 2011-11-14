#include "qbasicnode.hpp"
#include "qnodegroup.hpp"
#include "qslot.hpp"
#include "ui_basicnode.h"

#include "../nodecontainer.hpp"
#include "../nodes/addition.hpp"
#include "../nodes/timer.hpp"

QBasicNode::QBasicNode(QWidget *parent, NodeHandler *handler, QString name, int in, int out) :
  QFrame(parent)
{
  node_handler = handler;

  layout = new QGridLayout;
  layout->setSpacing(2);

  /*Adding in actions for the right click menu menu. */
  QAction *act;

  act = new QAction(QString("Remove"), this);
  act->setStatusTip(tr("Remove this node"));

  connect(act, SIGNAL(triggered()), this, SLOT(removeSelf()));
  menu.addAction(act);

  /* Done adding actions. */

  this->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
  this->setAutoFillBackground(true);

  this->nameLabel = new QLabel(this);
  this->nameLabel->setText(name);

  nameLabel->installEventFilter(this);

  node = node_handler->create_node(name.toStdString());
  if (name == "Counter" || name == "OpenGL window")
    node = node_handler->create_node("Node");

  this->setObjectName(QString("BasicNode"));
  this->setAccessibleName(name);

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

    layout->addWidget(outputs[j], 2, j, Qt::AlignLeft | Qt::AlignBottom);
  }

}

void QBasicNode::updateNode()
{

}

void QBasicNode::mouseReleaseEvent(QMouseEvent *event)
{
  if (event->button() == Qt::RightButton)
  {
    menu.exec(mapToGlobal(event->pos()));
  }
  else
    QCoreApplication::sendEvent(this->parent(), (QEvent*)event);
}

void QBasicNode::moveEvent( QMoveEvent * event )
{
  (void)event;

  updateLocation();
}

bool QBasicNode::eventFilter(QObject *obj, QEvent *event)
{

  if (event->type() == QEvent::MouseButtonPress)
  {
    QMouseEvent* mouse_event = static_cast<QMouseEvent *>(event);
    if (mouse_event && mouse_event->button() == Qt::RightButton)
    {
      //QCoreApplication::sendEvent(this->parent(), (QEvent*)event);
      return QObject::eventFilter(obj, event);
    }
    else
    {
      QCoreApplication::sendEvent(this->parent(), (QEvent*)event);
      return true;
    }
  }
  else
  {
    // standard event processing
    return QObject::eventFilter(obj, event);
  }
}

void QBasicNode::removeSelf()
{
  QNodeGroup *node_group = static_cast<QNodeGroup *>(this->parent());
  node_group->removeNode(this);
}

QBasicNode::~QBasicNode()
{
  cout<<"QtDEL: "<<this->objectName().toStdString()<<" calls destruction of node at: "<<node<<"\n";

  node_handler->delete_node(node);

  cout<<"QtDEL: Destroyed succesfully: ";
  cout<<this->objectName().toStdString()<<"\n\n";
}
