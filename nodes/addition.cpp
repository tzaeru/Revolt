#include "addition.hpp"

Addition::Addition(int aInputs, int aOutputs)
  : SuperNode(aInputs, aOutputs)
{

}

bool Addition::Update()
{
  inputSlot[0].connectedOutput->motherNode->Update();
  outputSlot[0].data[0] = inputSlot[0].connectedOutput->data[0] + inputSlot[1].connectedOutput->data[0];
  cout<<outputSlot[0].data[0]<<"\n";
}
