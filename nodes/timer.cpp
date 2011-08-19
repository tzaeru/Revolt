#include "timer.hpp"

Timer::Timer(int aInputs, int aOutputs)
  : SuperNode(aInputs, aOutputs)
{

}

bool Timer::Update()
{
  outputSlot[0].data[0] = myTimer.elapsed();
  return 1;
}
