#include "qbasicnode.hpp"
#include "qslot.hpp"
#include "../nodes/supernode.hpp"
#include "info.hpp"

QSlot::QSlot(QWidget *parent, int id)
  : QToolButton(parent)
{
  ID = id;

  connected_output_slot = NULL;

  node_parent = static_cast<QBasicNode *>(parent);
}

QSlot::~QSlot()
{

}

void QSlot::mousePressEvent(QMouseEvent *event)
{
  QToolButton::mousePressEvent(event);

  QCoreApplication::sendEvent(this->parent()->parent(), (QEvent*)event);
}

void QSlot::addConnection(QSlot *slot)
{
  // TEST CASE!!! REMOVE!
  if (this->parentWidget()->accessibleName() == "Audio Device (SDL)" || this->parentWidget()->accessibleName() == "Synth")
    return;
  if (this->accessibleName() == "input" && slot->accessibleName() == "output")
  {
    /* Makes sure the connection isn't already established. */
    for(std::vector<QSlot*>::iterator it = slot->connected_input_slots.begin(); it != slot->connected_input_slots.end(); ++it)
    {
      if (*it == this)
      {
        cout<<"QSlot found duplicate connection, erasing..\n";
        slot->connected_input_slots.erase(it);
        break;
      }
    }

    if (node_parent->node->Connect(ID, slot->ID, slot->node_parent->node))
    {
      connected_output_slot = slot;
      slot->connected_input_slots.push_back(this);
    }
    else
    {
      cout<<"QSlot tried connecting nodes, but connecting failed.\n";
    }
  }
  else if (this->accessibleName() == "output" && slot->accessibleName() == "input")
  {
    /* Makes sure the connection isn't already established. */
    for(std::vector<QSlot*>::iterator it = connected_input_slots.begin(); it != connected_input_slots.end(); ++it)
    {
      if (*it == slot)
      {
        cout<<"QSlot found duplicate connection, erasing..\n";
        connected_input_slots.erase(it);
        break;
      }
    }

    if (slot->node_parent->node->Connect(slot->ID, ID, node_parent->node))
    {
      connected_input_slots.push_back(slot);
      slot->connected_output_slot = this;
    }
    else
    {
      cout<<"QSlot tried connecting nodes, but connecting failed.\n";
    }
  }

  cout<<"QSlot added a connection!\n";
}

void QSlot::removeConnection(QSlot *slot)
{

}

void QSlot::removeConnections()
{

}
