#ifndef TIMER_HPP
#define TIMER_HPP

#include "supernode.hpp"

class Timer : public SuperNode
{
public:
  Timer(int aInputs, int aOutputs);

  //! Request data from the node.
  /*!
    \param slot The output slot from which data is requested.
    \return False if the given data would be old (or node is broken), true if data is new.
    */
  bool RequestData(int slot) { return 0; }
  //! Updates data according to node's functionality.
  /*!
    \return True if update succesful, false if not (from whatever reason).
    */
  bool Update();
};

#endif // TIMER_HPP
