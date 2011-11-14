#ifndef SUPERNODE_HPP
#define SUPERNODE_HPP

#include "../info.hpp"
#include "slot.hpp"

#include <sstream>

namespace node
{

//! Superclass for all nodes.
/*! SINK nodes' Update() is called from the main loop. Inside Update(),
  SINK does RequestData() to all the source nodes' outputs it's inputs
  are connected to.
  */
class SuperNode
{
private:

  //! Reads data to this node's input from the source node's output, unsure if used.
  bool ReadDataToInput();

public:
  /*!
    \param aInputs amount of inputs the node has.
    \param aOutputs amount of outputs the node has.
    */
  SuperNode(int aInputs, int aOutputs);

  virtual ~SuperNode();

  //! Unique name of the node.
  string identifier;

  //! Non-unique name of the object that inherits from this.
  string object_name;

  //! Type of node: SOURCE, SINK, DUAL
  int type;

  //! Node's input data for each input slot.
  vector <Slot> input_slot;
  //! Node's output data for each output slot.
  vector <Slot> output_slot;

  //! Amount (and identifiers) of data inputs
  int inputs;
  //! Amount (and identifiers) of data outputs
  int outputs;

  //! Connect an input slot of the node to an output slot of a node.
  /*!
    \param input Which input slot of this node is to be connected.
    \param output To which output slot of ConnectTo should the input be connected.
    \param ConnectTo The node requesting connection.
    \return Pointer to this node
    */
  bool Connect(int input, int outpout, SuperNode* ConnectTo);

  //! Disconnect an input slot of the node from an output slot of a node.
  /*!
    \param input The input slot to be disconnected.
    */
  void Disconnect(int input);

  //! Updates data according to node's functionality.
  /*!
    \return True if update succesful, false if not (from whatever reason).
    */
  virtual bool Update();

  virtual SuperNode* create_new() { return new SuperNode(1, 1); }
};

}

#endif // SUPERNODE_HPP
