#include "addition.hpp"

Addition::Addition()
  : SuperNode(2, 1)
{
  object_name = "Addition";

  cout<<"Created object of type: "<<object_name<<"\n";
  cout<<"Which has: "<<inputs<<" inputs and "<<outputs<<" outputs.\n";
}

bool Addition::Update()
{
  cout<<"Update called!"<<"\n";
  int value = 0;

  for (int i = 0; i < input_slot.size(); i++)
  {
    if (input_slot[i].connected_output != NULL)
    {
      input_slot[i].connected_output->motherNode->Update();
      value += input_slot[0].connected_output->data[0];
    }
  }

  output_slot[0].data[0] = value;
}
