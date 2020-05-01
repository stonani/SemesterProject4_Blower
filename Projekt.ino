#include "Blower.h"
#include "ControlPanel.h"

const int StartButtonIn = A3;
const int StopButtonIn = A5;
const int FanOut = 8;

bool IsTheBlowerOn;



void setup()
{
    ControlPanel.SetUp(StartButtonIn,StopButtonIn);
    Blower.SetUp(FanOut);

    IsTheBlowerOn=false;
}

void loop()
{

  if(ControlPanel.IsStartButtonPressed())
  {
    IsTheBlowerOn=true;
  }
  
  if(ControlPanel.IsStopButtonPressed())
  {
    IsTheBlowerOn=false;
  }
  
  if(IsTheBlowerOn)
  {
    Blower.StartBlower();
  }
}
