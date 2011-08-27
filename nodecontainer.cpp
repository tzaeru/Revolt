#include "nodecontainer.hpp"

#include "nodes/addition.hpp"
#include "nodes/timer.hpp"

NodeHandler *NodeHandler::instance = 0;

NodeHandler *NodeHandler::Instance()
{
  if (!instance)
  {
    instance = new NodeHandler();
  }

  return instance;
}

NodeHandler::NodeHandler()
{
  cout<<"Created instance of NodeHandler\n";

  objects_created = 0;

  /***** Modify this when adding new nodes done in C++  ******/
  node_classes.insert(std::pair<string, SuperNode*>("Addition", new node::Addition));
  node_classes.insert(std::pair<string, SuperNode*>("Timer", new node::Timer));
  /******/
}

node::SuperNode* NodeHandler::create_node(string class_name)
{
  if (node_classes.count(class_name))
  {
    SuperNode* new_node = node_classes.find(class_name)->second->create_new();

    stringstream ss;
    ss << class_name << objects_created;

    new_node->identifier = ss.str();

    node_objects.insert(std::pair<string, SuperNode*>(new_node->identifier, new_node));
    cout<<"Inserted a new node with unique identifier: "<<new_node->identifier<<"\n";

    objects_created++;

    return new_node;
  }

  return NULL;
}

void NodeHandler::delete_node(string node_name)
{
  if (node_objects.count(node_name))
  {
    delete node_objects.find(node_name)->second;
    node_objects.erase(node_name);
  }
}

void NodeHandler::delete_node(node::SuperNode* node)
{
  node_objects.erase(node->identifier);
  delete node;
}
