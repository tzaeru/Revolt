#include "nodecontainer.hpp"

#include "nodes/addition.hpp"
#include "nodes/timer.hpp"

NodeHandler::NodeHandler()
{
  cout<<"Created instance of NodeHandler\n\n";

  objects_created = 0;

  /***** Modify this when adding new nodes done in C++  ******/
  node_classes.insert(std::pair<string, SuperNode*>("Addition", new node::Addition));
  node_classes.insert(std::pair<string, SuperNode*>("Timer", new node::Timer));
  node_classes.insert(std::pair<string, SuperNode*>("Node", new node::SuperNode(1, 1)));
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
    cout<<"Inserted a new node with unique identifier: "<<new_node->identifier<<"\n\n";

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
  if (node_objects.count(node->identifier))
  {
    cout<<"DEL: NodeHandler received call to delete node: ";
    cout<<node->identifier<<" at: "<<node<<"\n";
    cout<<"DEL: Size: ";
    cout<<node_objects.size()<<", delete now:\n";

    // Name of the object to be deleted.
    string name = node->identifier;

    delete node_objects.find(name)->second;
    node_objects.erase(name);

    cout<<"DEL: Size: "<<node_objects.size()<<", NodeHandler done deleting.\n";
  }
  else
    cout<<"ERR: Not in container: "<<node->identifier<<"\n";

}

NodeHandler::~NodeHandler()
{
  cout<<"DEL Deleting NodeHandler.."<<"\n";
  map<string, SuperNode*>::iterator it;
  it = node_objects.begin();
/*
  while (it == node_objects.begin())
  {
    delete_node((*it).second);

    it++;
  }
*/
  cout<<"DEL: NodeHandler deleted!"<<"\n\n";
}
