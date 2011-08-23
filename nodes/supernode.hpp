#ifndef SUPERNODE_HPP
#define SUPERNODE_HPP

#include "../info.hpp"
#include "slot.hpp"

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
  //! Unique name of the node.
  string identifier;

  //! Non-unique name of the object that inherits from this.
  string object_name;

  /*!
    \param aInputs amount of inputs the node has.
    \param aOutputs amount of outputs the node has.
    */
  SuperNode(int aInputs, int aOutputs);

  //! Type of node: SOURCE, SINK, DUAL
  int type;

  //! Node's input data for each input slot.
  vector <Slot> inputSlot;
  //! Node's output data for each output slot.
  vector <Slot> outputSlot;

  //! Amount (and identifiers of data inputs
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

  //! Request data from the node.
  /*!
    \param slot The output slot from which data is requested.
    \return False if the given data would be old (or node is broken), true if data is new.
    */
  virtual bool RequestData(int slot) { return 0; }
  //! Updates data according to node's functionality.
  /*!
    \return True if update succesful, false if not (from whatever reason).
    */
  virtual bool Update() { return 0; }
};

#endif // SUPERNODE_HPP
