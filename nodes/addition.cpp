#include "addition.hpp"

Addition::Addition(int aInputs, int aOutputs)
  : SuperNode(aInputs, aOutputs)
{
  object_name = "Addition";

  cout<<"Created object of type: "<<object_name<<"\n";
  cout<<"Which has: "<<aInputs<<" inputs and "<<aOutputs<<" outputs.\n";
}

bool Addition::Update()
{
  cout<<"Update called!"<<"\n";
  int value = 0;

  for (int i = 0; i < inputSlot.size(); i++)
  {
    if (inputSlot[i].connectedOutput != NULL)
    {
      inputSlot[i].connectedOutput->motherNode->Update();
      value += inputSlot[0].connectedOutput->data[0];
    }
  }

  outputSlot[0].data[0] = value;

  cout<<value<<"\n";
}
