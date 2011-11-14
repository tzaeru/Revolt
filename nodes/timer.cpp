#include "timer.hpp"

Timer::Timer()
  : SuperNode(0, 1)
{
  object_name = "Timer";

  cout<<"Created object of type: "<<object_name<<"\n";
  cout<<"Which has: "<<inputs<<" inputs and "<<outputs<<" outputs.\n";
}

bool Timer::Update()
{
  double time = myTimer.elapsed();
  output_slot[0].data[0] = &time;
  return 1;
}

Timer::~Timer()
{

}
