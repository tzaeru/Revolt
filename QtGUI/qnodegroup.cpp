#include "qnodegroup.hpp"
#include "qbasicnode.hpp"
#include "../nodecontainer.hpp"

#include <QtGui>

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

  moving = false;
  movingLine = 0;

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
    QFrame *child = static_cast<QLabel*>(childAt(mapFromGlobal(QCursor::pos())));

    if (child && child->objectName() == QString("BasicNode"))
      moving = child;

   if (!moving && !movingLine && child && child->objectName() == QString("Slot"))
   {
     movingLine = true;
     lines.push_back(QLine(QWidget::mapFromGlobal(QCursor::pos()), QWidget::mapFromGlobal(QCursor::pos())));
     lineMoved = lines.size()-1;
     //this->update();
   }
   else if (movingLine)
   {
     if (child && child->objectName() == QString("Slot"))
     {

     }
     else
       lines.pop_back();
     movingLine = false;
   }
  }
}

void QNodeGroup::mouseMoveEvent(QMouseEvent *event)
{
  if (moving)
  {
    moving->move(event->pos());
  }
  if (movingLine)
  {
    lines[lineMoved].setP2(event->pos());
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
    for (int i = 0; i < lines.size(); i++)
      painter.drawLine(lines[i]);
}

void QNodeGroup::addNode()
{
  QAction * action = qobject_cast<QAction *>(sender());
  QString temp = action->text();

  if (temp == "Timer")
  {
    QFrame *timer = new QBasicNode(this, QString("timer"), 0, 1);
    timer->show();
  }
  else if (temp == "Addition")
  {
    QFrame *timer = new QBasicNode(this, QString("addition"), 2, 1);
    timer->show();
  }
}
