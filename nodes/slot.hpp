#ifndef NODEDATA_HPP
#define NODEDATA_HPP

#include "../info.hpp"

class SuperNode;

//! A generic slot holding the input/output data or the pointer to slot with the data.
/*! Slot itself does not care whether it's output or input, using it is fully up to the
  * node that created it.
  */
class Slot
{
public:
  Slot();

  //! Amount of dimensions the datatype has.
  int dimensions;
  //! Size of an individual dimension.
  std::vector < int > dimension_size;

  //! The actual data.
  std::vector < float > data;

  //! The output from which the data is read.
  Slot *connectedOutput;

  //! Whether has updated data or not.
  int lastUpdated;
  bool HasUpdated() { return lastUpdated == currentFrame; }

  //! Whether has requested an update (in case this is an input slot)
  int lastRequested;
  bool hasRequested() { return lastRequested == currentFrame; }

  //! The node to which this slot belongs to.
  SuperNode *motherNode;

  bool ConnectToOutput(Slot *tempOutput);
  bool DisconnectFromOutput();
};

#endif // NODEDATA_HPP
