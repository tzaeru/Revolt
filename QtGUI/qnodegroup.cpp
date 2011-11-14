#include "../nodecontainer.hpp"

#include <QtGui>

#include "qnodegroup.hpp"
#include "qbasicnode.hpp"
#include "qcounter.hpp"
#include "qslot.hpp"
#include "qopenglnode.hpp"

#include "../nodes/supernode.hpp"

/* REMEMBER TO REMOVE, TEST CASE ONLY! */
#include "../nodes/sound/preset_data.hpp"
#include "../nodes/sound/sdl_sound_hardware.hpp"
#include "../nodes/sound/synth.hpp"
#include "../nodes/sound/mixer.hpp"
/* */

QNodeGroup::QNodeGroup(QWidget *parent)
  : QFrame(parent)
{
  this->setObjectName("NodeGroup");

  setMinimumSize(200, 200);
  setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);

  setAcceptDrops(true);

  node_handler = new NodeHandler;

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

  act = new QAction(QString("OpenGL window"), this);
  act->setStatusTip(tr("New OpenGL window"));
  connect(act, SIGNAL(triggered()), this, SLOT(addNode()));
  menu.addAction(act);

  act = new QAction(QString("Synth"), this);
  act->setStatusTip(tr("Synth"));
  connect(act, SIGNAL(triggered()), this, SLOT(addNode()));
  menu.addAction(act);

  act = new QAction(QString("Audio Device (SDL)"), this);
  act->setStatusTip(tr("Audio Device"));
  connect(act, SIGNAL(triggered()), this, SLOT(addNode()));
  menu.addAction(act);

  moving = false;
  moving_line = 0;

  this->setMouseTracking(true);
}

void QNodeGroup::mousePressEvent(QMouseEvent *event)
{
  this->update();

  /* If moving a window, we'll stop moving it now with the second click. */
  if (moving)
    moving = NULL;
  if (event->button() == Qt::LeftButton)
  {
    QWidget *child = childAt(mapFromGlobal(QCursor::pos()));

    /* Let's see if the user is attempting to move a node. */
    if (child && child->objectName() == QString("BasicNode"))
      moving = child;
    /* As above, except that the user pressed on the name tag or subwidget of a node. */
    else if (child && child->parentWidget()->objectName() == QString("BasicNode") && child->objectName() != QString("Slot"))
      moving = child->parentWidget();
    /* If we're not moving a node nor creating a new connection, let's start creating a new node connection now. */
    else if (!moving && !moving_line && child && child->objectName() == QString("Slot"))
    {

      QSlot* child_slot = qobject_cast<QSlot *>(child);

      /*
      if (child_slot->accessibleName() == QString ("input"))
      {
        cout<<"Crashes1!\n";
        QBasicNode *input_node = qobject_cast<QBasicNode *>(temp_line_start->parentWidget());
        cout<<"Crashes2!\n";
        if (input_node->node->input_slot[child_slot->getID()].connected_output)
        {
          cout<<"Crashes!\n";
          input_node->node->Disconnect(child_slot->getID());
          cout<<"Works?\n";
        }
      }
      */
      moving_line = true;
      temp_line_start = child_slot;
      temp_line_end = mapFromGlobal(QCursor::pos());
    }
    /* Already trying to create a node connection so let's continue to that.*/
    else if (moving_line)
    {

      /* If user has clicked the connection from Slot to Slot, let's do the connection. */
      if (child && child->objectName() == QString("Slot"))
      {
        QSlot* child_slot = qobject_cast<QSlot *>(child);

        child_slot->addConnection(temp_line_start);
      }
/*
      if (child && child->objectName() == QString("Slot"))
      {

        QSlot* child_slot = qobject_cast<QSlot *>(child);

        if (child_slot->accessibleName() == QString("output") && temp_line_start->accessibleName() == QString("input"))
        {
          child_slot->connected_slots.push_back(temp_line_start);
          temp_line_start->connected_slot = temp_line_start;

          QBasicNode *input_node = qobject_cast<QBasicNode *>(temp_line_start->parentWidget());
          QBasicNode *output_node = qobject_cast<QBasicNode *>(child_slot->parentWidget());

          QObject::connect(input_node, SIGNAL(updateLocation()), this, SLOT(updateLine()));
          QObject::connect(output_node, SIGNAL(updateLocation()), this, SLOT(updateLine()));

          input_node->node->Connect(temp_line_start->getID(), child_slot->getID(), output_node->node);
        }
        else if (child_slot->accessibleName() == QString("input") && temp_line_start->accessibleName() == QString("output"))
        {
          temp_line_start->connected_slots.push_back(child_slot);
          child_slot->connected_slot = temp_line_start;

          QBasicNode *input_node = qobject_cast<QBasicNode *>(child_slot->parentWidget());
          QBasicNode *output_node = qobject_cast<QBasicNode *>(temp_line_start->parentWidget());
          QObject::connect(input_node, SIGNAL(updateLocation()), this, SLOT(updateLine()));
          QObject::connect(output_node, SIGNAL(updateLocation()), this, SLOT(updateLine()));

          input_node->node->Connect(child_slot->getID(), temp_line_start->getID(), output_node->node);
        }
      }
      */
      /* Whatever the case, stop having a line moving. */
      moving_line = false;
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
  cout<<"Qt: Paint event called.\n";

  QFrame::paintEvent(pEvent);

  QPainter painter(this);

  painter.setRenderHint(QPainter::Antialiasing, false);
  painter.setPen(QPen(Qt::SolidPattern, 0));

  if (moving_line)
  {
    painter.drawLine(temp_line_start->parentWidget()->mapTo(this, QPoint(temp_line_start->x() + temp_line_start->width()/2, temp_line_start->y() + temp_line_start->height()/2)), temp_line_end);
  }
  for (unsigned int node_count = 0; node_count < nodes.size(); node_count++)
  {
    for (unsigned int slot_count = 0; slot_count < nodes[node_count]->inputs.size(); slot_count++)
    {
      if (nodes[node_count]->inputs[slot_count]->connected_output_slot != NULL)
      {
        QSlot *line_start = nodes[node_count]->inputs[slot_count];
        QSlot *line_end = line_start->connected_output_slot;
        painter.drawLine(line_end->parentWidget()->mapTo(this, QPoint(line_end->x() + line_end->width()/2, line_end->y() + line_end->height()/2)),
                         line_start->parentWidget()->mapTo(this,  QPoint(line_start->x() + line_start->width()/2, line_start->y() + line_start->height()/2)));
      }
      /*
      for (unsigned int connection_count = 0; connection_count < line_start->connected_slots.size(); connection_count++)
      {
        cout<<"Qt: Loop 3.\n";
        QSlot *line_end = line_start->connected_slots[connection_count];
cout<<"Qt: Loop 4.\n";
        painter.drawLine(line_end->parentWidget()->mapTo(this, QPoint(line_end->x() + line_end->width()/2, line_end->y() + line_end->height()/2)),
                         line_start->parentWidget()->mapTo(this,  QPoint(line_start->x() + line_start->width()/2, line_start->y() + line_start->height()/2)));
      }
      */
    }
  }

  cout<<"Qt: Paint event finished.\n";
}

void QNodeGroup::addNode()
{
  QAction * action = qobject_cast<QAction *>(sender());
  QString temp = action->text();

  QBasicNode *new_node;

  if (temp == "Timer")
  {
    new_node = new QBasicNode(this, node_handler, QString("Timer"), 0, 1);
    nodes.push_back(new_node);
    new_node->show();
  }
  else if (temp == "Addition")
  {
    new_node = new QBasicNode(this, node_handler, QString("Addition"), 2, 1);
    nodes.push_back(new_node);
    new_node->show();
  }
  else if (temp == "Counter")
  {
    new_node = new QCounter(this, node_handler, QString("Counter"), 1, 0);
    nodes.push_back(new_node);
    new_node->show();
  }
  else if (temp == "OpenGL window")
  {
    new_node = new QOpenGLNode(this, node_handler, QString("OpenGL window"), 1, 0);
    nodes.push_back(new_node);
    new_node->show();
  }

  else if (temp == "Audio Device (SDL)")
  {
    new_node = new QBasicNode(this, node_handler, QString("Audio Device (SDL)"), 1, 0);
    nodes.push_back(new_node);
    new_node->show();

    /* REMEMBER TO REMOVE; TEST CASE STUFF ONLY!! */

    int max_amp = 32767;
    int sample_length = 4096;
    int channels = 2;

    PresetData *preset_data;
    preset_data = new PresetData();
    preset_data->Init();

    //synth = new Synth(440, max_amp/2, 48000, &preset_data);
    //Synth *synth2 = new Synth(440, max_amp/4, 48000, &preset_data);
    Mixer *mixer;
    SDLSoundHardware *sound_hardware;
    mixer = new Mixer(max_amp);

    mixer->SetSampleLength(sample_length*channels);
    //mixer->AddSynth(synth);

    sound_hardware = new SDLSoundHardware(48000, sample_length);

    sound_hardware->AddMixer(mixer);

    sound_hardware->Init();

    float *wave;
    int wave_length = preset_data->GetPreset(wave);
    Synth *synth;

    synth = new Synth(48000);
    synth->SetAmplitude(4095);
    synth->SetFrequency(220);
    synth->SetWaveform(wave, wave_length);

    mixer->AddSource(synth);
    /*/
      */
  }

  else if (temp == "Synth")
  {
    new_node = new QBasicNode(this, node_handler, QString("Synth"), 0, 1);
    nodes.push_back(new_node);
    new_node->show();
  }

  QObject::connect(new_node, SIGNAL(updateLocation()), this, SLOT(updateLine()));
}

void QNodeGroup::removeNode(QBasicNode *removal)
{
  cout<<"QtDEL: QNodeGroup removing node.\n";
  for (unsigned int i = 0; i < nodes.size(); i++)
  {
    cout<<removal<<" "<<nodes[i]<<"\n";
    if (removal == nodes[i])
    {
      removeConnections(nodes[i]);
      nodes[i]->deleteLater();
      nodes.erase(nodes.begin() + i);
    }
  }
  cout<<"QtDEL: QNodeGroup done removing node.\n";
}

void QNodeGroup::removeConnections(QBasicNode *removal)
{
  for (unsigned int i = 0; i < removal->inputs.size(); i++)
  {
    removal->inputs[i]->removeConnections();
  }

  for (unsigned int i = 0; i < removal->outputs.size(); i++)
  {
    removal->outputs[i]->removeConnections();
  }
}

QNodeGroup::~QNodeGroup()
{
  cout<<"QtDEL: QNodeGroup deleting NodeHandler..\n";

  for (unsigned int i = 0; i < nodes.size(); i++)
  {
    delete nodes[i];
  }

  delete node_handler;
}
