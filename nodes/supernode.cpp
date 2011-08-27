#include "supernode.hpp"

SuperNode::SuperNode(int aInputs, int aOutputs)
{
  object_name = "SuperNode";

  inputs = aInputs;
  outputs = aOutputs;

  input_slot.resize(aInputs);
  output_slot.resize(aOutputs);

  for (int i = 0; i < aInputs; i++) {
    input_slot[i].identifier = i;
    input_slot[i].data.push_back(0);
    input_slot[i].connected_output = NULL;
    input_slot[i].motherNode = this;
  }

  for (int i = 0; i < aOutputs; i++) {
    output_slot[i].identifier = i;
    output_slot[i].data.push_back(0);
    output_slot[i].motherNode = this;
  }
}

bool SuperNode::Connect(int input, int output, SuperNode *ConnectTo)
{
  cout<<"Object "<<object_name<<" connects it's input "<<input<<" to output "<<output<<" of "<<ConnectTo->object_name<<"\n";
  input_slot[input].connected_output = &(ConnectTo->output_slot[output]);

  ConnectTo->output_slot[output].connected_inputs.push_back(&input_slot[input]);
}

void SuperNode::Disconnect(int input)
{
  input_slot[input].connected_output = NULL;
}


bool SuperNode::Update()
{
  for (int i = 0; i < input_slot.size(); i++)
  {
    if (input_slot[i].connected_output != NULL)
    {
      input_slot[i].connected_output->motherNode->Update();
    }
  }

  return 1;
}

SuperNode::~SuperNode()
{
  cout<<"Destructor for: "<<identifier<<" called.\n";
  for (int i = 0; i < output_slot.size(); i++)
  {
    for (int j = 0; j < output_slot[i].connected_inputs.size(); j++)
    {
      output_slot[i].connected_inputs[j]->DisconnectFromOutput();
    }
  }
  cout<<"All connected slots disconnected.\n\n";
}
