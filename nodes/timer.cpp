#include "timer.hpp"

Timer::Timer(int aInputs, int aOutputs)
  : SuperNode(aInputs, aOutputs)
{
  object_name = "Timer";

  cout<<"Created object of type: "<<object_name<<"\n";
  cout<<"Which has: "<<aInputs<<" inputs and "<<aOutputs<<" outputs.\n";
}

bool Timer::Update()
{
  outputSlot[0].data[0] = myTimer.elapsed();
  return 1;
}
