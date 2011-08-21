#ifndef ADDITION_HPP
#define ADDITION_HPP

#include "supernode.hpp"

//! A generic node for addition, variable amount of inputs.
class Addition : public SuperNode
{
public:
    Addition(int aInputs, int aOutputs);

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

#endif // ADDITION_HPP
