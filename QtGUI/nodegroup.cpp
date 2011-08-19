#include "nodegroup.hpp"
#include "basicnode.hpp"

#include <QtGui>

NodeGroup::NodeGroup(QWidget *parent)
  : QFrame(parent)
{
  this->setObjectName("NodeGroup");

  setMinimumSize(200, 200);
  setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);

  setAcceptDrops(true);

  /* OLD TESTCASE
  lineImage = new QImage(this->parentWidget()->size(), QImage::Format_ARGB32);
  lineImage->fill(QPalette::Window);
  */

  /*Adding in actions for the menu. */
  QAction *act;

  act = new QAction(QString("Timer"), this);
  act->setStatusTip(tr("Open an existing file"));
  connect(act, SIGNAL(triggered()), this, SLOT(addNode()));
  menu.addAction(act);

  act = new QAction(QString("Addition"), this);
  act->setStatusTip(tr("Open an existing file"));
  connect(act, SIGNAL(triggered()), this, SLOT(addNode()));
  menu.addAction(act);
  menu.addAction("Option 2");

  moving = false;
  movingLine = 0;

  this->setMouseTracking(true);
}

NodeGroup::~NodeGroup()
{

}


void NodeGroup::mousePressEvent(QMouseEvent *event)
{
  /* Old TESTCASE
    QPainter painter(this->lineImage);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(QPen(Qt::SolidPattern, 0));
    painter.drawLine(QPointF(qrand() % 300, qrand() % 300),
                     QPointF(qrand() % 300,qrand() % 300));

                     */
  this->update();

  if (moving)
    moving = NULL;
  if (event->button() == Qt::LeftButton)
  {
    QFrame *child = static_cast<QLabel*>(childAt(event->pos()));

    if (child && child->objectName() == QString("BasicNode"))
      moving = child;

    if (child && child->objectName() == QString("Slot"))
    {

    }

   if (!moving && !movingLine && !child)
   {
     movingLine = true;
     lines.push_back(QLine(event->pos(), event->pos()));
     lineMoved = lines.size()-1;
     //this->update();
   }
   else if (movingLine)
   {
     movingLine = false;
   }
  }
}

void NodeGroup::mouseMoveEvent(QMouseEvent *event)
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

void NodeGroup::mouseReleaseEvent(QMouseEvent *event)
{
  if (moving)
    moving = NULL;
  if (event->button() == Qt::RightButton)
  {
    menu.exec(mapToGlobal(event->pos()));
  }
}

void NodeGroup::paintEvent(QPaintEvent * pEvent)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(QPen(Qt::SolidPattern, 0));
    for (int i = 0; i < lines.size(); i++)
      painter.drawLine(lines[i]);

    /* OLD TESTCASE
    painter.drawImage(this->rect(), *this->lineImage);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(QPen(Qt::SolidPattern, 0));
    painter.drawLine(QPointF(qrand() % this->width(), qrand() % this->height()),
                     QPointF(qrand() % this->width(), qrand() % this->height()));*/
}

void NodeGroup::addNode()
{
  QAction * action = qobject_cast<QAction *>(sender());
  QString temp = action->text();

  if (temp == "Timer")
  {
    QFrame *timer = new BasicNode(this, QString("timer"), 5, 0);
    timer->show();
  }
  else if (temp == "Addition")
  {
    QFrame *timer = new BasicNode(this, QString("addition"), 4, 0);
    timer->show();
  }
}

/*
void NodeGroup::actionEvent(QActionEvent* event)
{
  if (event->action()->text() == QString("Timer"))
  {

  }
}
*/
