#ifndef ADDITION_HPP
#define ADDITION_HPP

#include "supernode.hpp"

namespace node
{

//! A generic node for addition, variable amount of inputs.
class Addition : public SuperNode
{
public:
  Addition();

  //! Updates data according to node's functionality.
  /*!
      \return True if update succesful, false if not (from whatever reason).
      */
  bool Update();

  SuperNode* create_new() { return new Addition(); }
};

}

#endif // ADDITION_HPP
