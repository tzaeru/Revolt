#include "supernode.hpp"

SuperNode::SuperNode(int aInputs, int aOutputs)
{
  inputSlot.resize(aInputs);
  outputSlot.resize(aOutputs);

  for (int i = 0; i < aInputs; i++) {
    inputSlot[i].data.push_back(0);
    inputSlot[i].connectedOutput = NULL;
    inputSlot[i].motherNode = this;
  }

  for (int i = 0; i < aOutputs; i++) {
    outputSlot[i].data.push_back(0);
    outputSlot[i].motherNode = this;
  }
}

bool SuperNode::Connect(int input, int output, SuperNode *ConnectTo)
{
  cout<<"Object "<<object_name<<" connects it's input "<<input<<" to output "<<output<<" of "<<ConnectTo->object_name<<"\n";
  inputSlot[input].connectedOutput = &(ConnectTo->outputSlot[output]);
}
