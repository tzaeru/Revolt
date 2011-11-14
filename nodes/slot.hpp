#ifndef NODEDATA_HPP
#define NODEDATA_HPP

#include "../info.hpp"

#include <vector>
#include <iostream>

namespace node
{

enum { INT, DOUBLE, VERTEX_ARRAY, SHADER, OBJECT };

class SuperNode;

//! A generic slot holding the input/output data or the pointer to slot with the data.
/*! Slot itself does not care whether it's output or input, using it is fully up to the
  * node that created it.
  */
class Slot
{
public:
  Slot();

  //! Identifier for the slot inside SuperNode.
  int identifier;

  //! Data type of the slot.
  int type;

  //! Amount of dimensions the datatype has.
  int dimensions;
  //! Size of an individual dimension.
  std::vector < int > dimension_size;

  //! The actual data.
  std::vector < double* > data;

  //! The output from which the data has been read.
  Slot *connected_output;

  //! Array of inputs this slot is connected to, used when motherNode is deleted.
  vector < Slot* > connected_inputs;

  //! Whether has updated data or not.
  int lastUpdated;
  bool HasUpdated() { return lastUpdated == currentFrame; }

  //! Whether has requested an update (in case this is an input slot)
  int lastRequested;
  bool hasRequested() { return lastRequested == currentFrame; }

  //! The node to which this slot belongs to.
  SuperNode *motherNode;

  bool ConnectToOutput(Slot *tempOutput);
  //! Disconnected from output, called when the output slot or it's node is deleted.
  void DisconnectFromOutput() { cout<<"Disconnecting slot: "<<identifier<<"\n";
                               connected_output = NULL; };
};
}

#endif // NODEDATA_HPP
