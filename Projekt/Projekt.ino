#include "Blower.h"
#include "ControlPanel.h"
#include "HumiditySensor.h"
#include "Indicator.h"

//Pin configuration
const int _startButtonIn = A3;
const int _stopButtonIn = A5;
const int _startButtonOut = A0;
const int _stopButtonOut = A1;

const int _fanSignalOut = 0;

//const int _Sensor1In = 3; Ligger inde i humiditySensor
//const int _Sensor2In = 4; Ligger inde i humiditySensor
const int _Sensor1Out = A14;
const int _Sensor2Out = A15;

const int _LED2Out = 2;


bool _buttonState; //True = fan is on


void setup()
{
    Serial.begin(9600); //Til testning
    
    ControlPanel.SetUp(_startButtonIn,_stopButtonIn,_startButtonOut,_stopButtonOut);    
    Blower.SetUp(_fanSignalOut);    
    HumiditySensor.SetUp(_Sensor1Out,_Sensor2Out);
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
  else
  {
    Blower.StopBlower();
    Indicator.TurnOff();
  }
}
