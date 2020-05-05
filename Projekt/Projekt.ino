#include "Blower.h"
#include "ControlPanel.h"

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE    DHT22
#define DHTPIN1 3 
#define DHTPIN2 4 
DHT HumiditySensor1(DHTPIN1, DHTTYPE);
DHT HumiditySensor2(DHTPIN2, DHTTYPE);
uint32_t delayMS;

const int _startButtonIn = A3;
const int _stopButtonIn = A5;
const int _fanSignalOut = 0;
const int _LED2Supply = 0;

bool _buttonState; //True = fan is on

//Mini kommentar


void setup()
{
    Serial.begin(9600);
    ControlPanel.SetUp(_startButtonIn,_stopButtonIn);
    Blower.SetUp(_fanSignalOut);
    _buttonState=false;

    HumiditySensor1.begin();
    HumiditySensor2.begin();
    sensor_t sensor;
    delayMS = sensor.min_delay / 1000;
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

  //delay(delayMS); 
  if (HumiditySensor1.readHumidity() <= HumiditySensor2.readHumidity())//HumiditySensor
    {
        _buttonState=false;
    }
   
  FanSetting();
}

void FanSetting()
{   
  if(_buttonState)
  {
    Blower.StartBlower();
  }
  else{
    Blower.StopBlower();
  }
}
