//! Contains all nodes, include when necessary.
#ifndef NODECONTAINER_HPP
#define NODECONTAINER_HPP

#include <vector>
#include <map>
#include <string>

#include "info.hpp"

namespace node
{
  class SuperNode;
}

//! Contains all nodes, handles all insertions, renamings, deletions, and is a singleton.
/*! Every software making use of the nodes should include this. Inserting, deleting,
  renaming nodes has undefined behavior if done outside the scope of NodeHandler.
  Program with multiple windows should use one NodeHandler. Programs sharing node
  connections over sockets (either locally or over the internet) should each use
  one instance of NodeHandler.
  */
class NodeHandler
{
public:
  NodeHandler();

  ~NodeHandler();

  //! Holds a pointer to all existing classes, this is used as a template when creating new objects with class name.
  std::map< string, node::SuperNode*> node_classes;

  //! Holds a pointer to all existing node objects by their unique identifiers created with create_node().
  std::map< string, node::SuperNode*> node_objects;

  //! Holds the amount of total node objects created.
  int objects_created;

  //! Use to create a new object of a class.
  /*!
    \param class_name Name of the class for the object.
    \return Pointer to the newly created object.
    */
  node::SuperNode* create_node(string class_name);

  //! Use this to delete a node by unique name.
  /*!
    \param node_name Name of the object to be destroyed.
    */
  void delete_node(string node_name);

  //! Use this to delete a node by pointer.
  /*!
    \param object Pointer to the object to be destroyed.
    */
  void delete_node(node::SuperNode* node);

private:

};

#endif // NODECONTAINER_HPP
