#ifndef TIMER_HPP
#define TIMER_HPP

#include "supernode.hpp"

namespace node
{

//! A basic timer.
class Timer : public SuperNode
{
public:
  Timer();

  ~Timer();

  //! Updates data according to node's functionality.
  /*!
    \return True if update succesful, false if not (from whatever reason).
    */
  bool Update();

  SuperNode* create_new() { return new Timer(); }
};

}
#endif // TIMER_HPP
