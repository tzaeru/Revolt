#include "../nodecontainer.hpp"

#include <QtGui>

#include "qnodegroup.hpp"
#include "qbasicnode.hpp"
#include "qcounter.hpp"
#include "qslot.hpp"

#include "../nodes/supernode.hpp"

QNodeGroup::QNodeGroup(QWidget *parent)
  : QFrame(parent)
{
  this->setObjectName("NodeGroup");

  setMinimumSize(200, 200);
  setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);

  setAcceptDrops(true);

  /*Adding in actions for the menu. */
  QAction *act;

  act = new QAction(QString("Timer"), this);
  act->setStatusTip(tr("Timer"));
  connect(act, SIGNAL(triggered()), this, SLOT(addNode()));
  menu.addAction(act);

  act = new QAction(QString("Addition"), this);
  act->setStatusTip(tr("Addition"));
  connect(act, SIGNAL(triggered()), this, SLOT(addNode()));
  menu.addAction(act);

  act = new QAction(QString("Counter"), this);
  act->setStatusTip(tr("Counter"));
  connect(act, SIGNAL(triggered()), this, SLOT(addNode()));
  menu.addAction(act);

  moving = false;
  moving_line = 0;

  this->setMouseTracking(true);
}

QNodeGroup::~QNodeGroup()
{

}


void QNodeGroup::mousePressEvent(QMouseEvent *event)
{
  this->update();

  if (moving)
    moving = NULL;
  if (event->button() == Qt::LeftButton)
  {
    QWidget *child = childAt(mapFromGlobal(QCursor::pos()));

    if (child)
    {
      if (child->objectName() == QString("BasicNode"))
        moving = child;
      else if (child->parentWidget()->objectName() == QString("BasicNode") && child->objectName() != QString("Slot"))
        moving = child->parentWidget();
      else if (!moving && !moving_line && child && child->objectName() == QString("Slot"))
      {
        moving_line = true;

        QSlot* child_slot = qobject_cast<QSlot *>(child);
        temp_line_start = child_slot;
        temp_line_end = mapFromGlobal(QCursor::pos());
      }

    else if (moving_line)
    {
      if (child && child->objectName() == QString("Slot"))
      {
        QSlot* child_slot = qobject_cast<QSlot *>(child);

        if (child_slot->accessibleName() == QString("output") && temp_line_start->accessibleName() == QString("input"))
        {
          child_slot->connected_slots.push_back(temp_line_start);

          QBasicNode *input_node = qobject_cast<QBasicNode *>(temp_line_start->parentWidget());
          QBasicNode *output_node = qobject_cast<QBasicNode *>(child_slot->parentWidget());

          QObject::connect(input_node, SIGNAL(updateLocation()), this, SLOT(updateLine()));
          QObject::connect(output_node, SIGNAL(updateLocation()), this, SLOT(updateLine()));

          input_node->node->Connect(temp_line_start->getID(), child_slot->getID(), output_node->node);
        }
        else if (child_slot->accessibleName() == QString("input") && temp_line_start->accessibleName() == QString("output"))
        {
          temp_line_start->connected_slots.push_back(child_slot);

          QBasicNode *input_node = qobject_cast<QBasicNode *>(child_slot->parentWidget());
          QBasicNode *output_node = qobject_cast<QBasicNode *>(temp_line_start->parentWidget());
          QObject::connect(input_node, SIGNAL(updateLocation()), this, SLOT(updateLine()));
          QObject::connect(output_node, SIGNAL(updateLocation()), this, SLOT(updateLine()));

          input_node->node->Connect(child_slot->getID(), temp_line_start->getID(), output_node->node);
        }
      }
      moving_line = false;
    }
      }
  }
}

void QNodeGroup::updateLine()
{
  this->update();
}

void QNodeGroup::mouseMoveEvent(QMouseEvent *event)
{
  if (moving)
  {
    moving->move(event->pos());
  }
  if (moving_line)
  {
    temp_line_end = mapFromGlobal(QCursor::pos());
    //lines[1][lineMoved] = QCursor::pos();

    //lines[lineMoved].setP2(event->pos());
    this->update();
  }
}

void QNodeGroup::mouseReleaseEvent(QMouseEvent *event)
{
  if (moving)
    moving = NULL;
  if (event->button() == Qt::RightButton)
  {
    menu.exec(mapToGlobal(event->pos()));
  }
}

void QNodeGroup::paintEvent(QPaintEvent * pEvent)
{

  QFrame::paintEvent(pEvent);

  QPainter painter(this);

  painter.setRenderHint(QPainter::Antialiasing, false);
  painter.setPen(QPen(Qt::SolidPattern, 0));

  if (moving_line)
  {
    painter.drawLine(temp_line_start->parentWidget()->mapTo(this, QPoint(temp_line_start->x() + temp_line_start->width()/2, temp_line_start->y() + temp_line_start->height()/2)), temp_line_end);
  }
  for (int node_count = 0; node_count < nodes.size(); node_count++)
  {
    for (int slot_count = 0; slot_count < nodes[node_count]->outputs.size(); slot_count++)
    {
      QSlot *line_start = nodes[node_count]->outputs[slot_count];
      for (int connection_count = 0; connection_count < line_start->connected_slots.size(); connection_count++)
      {
        QSlot *line_end = line_start->connected_slots[connection_count];

        painter.drawLine(line_end->parentWidget()->mapTo(this, QPoint(line_end->x() + line_end->width()/2, line_end->y() + line_end->height()/2)),
                         line_start->parentWidget()->mapTo(this,  QPoint(line_start->x() + line_start->width()/2, line_start->y() + line_start->height()/2)));
      }
    }
  }
}

void QNodeGroup::addNode()
{
  QAction * action = qobject_cast<QAction *>(sender());
  QString temp = action->text();

  QBasicNode *new_node;

  if (temp == "Timer")
  {
    new_node = new QBasicNode(this, QString("timer"), 0, 1);
    nodes.push_back(new_node);
    new_node->show();
  }
  else if (temp == "Addition")
  {
    new_node = new QBasicNode(this, QString("addition"), 2, 1);
    nodes.push_back(new_node);
    new_node->show();
  }
  else if (temp == "Counter")
  {
    new_node = new QCounter(this, QString("counter"), 1, 0);
    nodes.push_back(new_node);
    new_node->show();
  }
}
