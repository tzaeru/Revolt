//! Contains all nodes, include when necessary.
#ifndef NODECONTAINER_HPP
#define NODECONTAINER_HPP

#include <vector>
#include <map>
#include <string>

class SuperNode;

extern std::vector< SuperNode* > node_container;
extern std::map < std::string*, SuperNode* > node_names;

class NodeHandler
{
public:
  void removeNode(int i)
  {
    node_container.erase(node_container.begin() + i);
  }
};

#endif // NODECONTAINER_HPP
