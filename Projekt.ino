#include "Blower.h"
#include "ControlPanel.h"

const int StartButtonIn = A3;
const int StopButtonIn = A5;
const int FanOut = 8;

bool buttonState;



void setup()
{
    ControlPanel.SetUp(StartButtonIn,StopButtonIn);
    Blower.SetUp(FanOut);

    buttonState=false;
}

void loop()
{

  if(ControlPanel.IsStartButtonPressed())
  {
    buttonState=true;
  }
  
  if(ControlPanel.IsStopButtonPressed())
  {
    buttonState=false;
  }
  
  if(buttonState)
  {
    Blower.StartBlower();
  }
}
