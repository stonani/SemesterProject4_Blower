#include "Blower.h"
#include "ControlPanel.h"
#include "HumiditySensor.h"


//Pin configuration
const int _startButtonIn = A3;
const int _stopButtonIn = A5;
const int _startButtonOut = 0;
const int _stopButtonOut = 0;

const int _fanSignalOut = 0;

const int _Sensor1In = 0;
const int _Sensor2In = 0;
const int _Sensor1Out = 0;
const int _Sensor2Out = 0;

const int _LED1Out = 0;
const int _LED2Out = 0;


bool _buttonState; //True = fan is on


void setup()
{
    Serial.begin(9600); //Til testning
    
    ControlPanel.SetUp(_startButtonIn,_stopButtonIn,_startButtonOut,_stopButtonOut);    
    Blower.SetUp(_fanSignalOut);    
    HumiditySensor.SetUp(_Sensor1In,_Sensor2In,_Sensor1Out,_Sensor2Out);
    Indicator.SetUp(_LED1Out,_LED2Out);
    
    _buttonState=false;
}

void loop()
{

  if(ControlPanel.IsStartButtonPressed())//StartButton
  {
    _buttonState=true;
  }
  
  if(ControlPanel.IsStopButtonPressed())//StopButton
  {
    _buttonState=false;
  }

  if (HumiditySensor.GetSensor1Data() <=HumiditySensor.GetSensor2Data())//HumiditySensor
  {
    _buttonState=false;
  }
   
  if(_buttonState)
  {
    Blower.StartBlower();
    Indicator.TurnOn();
  }
  else{
    Blower.StopBlower();
    Indicator.TurnOff();
  }
}
