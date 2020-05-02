#include "Blower.h"
#include "ControlPanel.h"

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE    DHT22
#define DHTPIN1 12 
#define DHTPIN2 13 
DHT_Unified HumiditySensor1(DHTPIN1, DHTTYPE);
DHT_Unified HumiditySensor2(DHTPIN2, DHTTYPE);
uint32_t delayMS;

const int _startButtonIn = A3;
const int _stopButtonIn = A5;
const int _fanSignalOut = 8;
const int _LED2Supply = 0;
const int _humiditySupply = 0;

bool buttonState; //True = blæseren er tændt



void setup()
{
    ControlPanel.SetUp(_startButtonIn,_stopButtonIn);
    Blower.SetUp(_fanSignalOut);
    buttonState=false;

    HumiditySensor1.begin();
    HumiditySensor2.begin();
    sensor_t sensor;
    delayMS = sensor.min_delay / 1000;
}

void loop()
{

  if(ControlPanel.IsStartButtonPressed())//Startknap
  {
    buttonState=true;
  }
  
  if(ControlPanel.IsStopButtonPressed())//Stopknap
  {
    buttonState=false;
  }

  delay(delayMS); //Tempratursensorer
  sensors_event_t event;
  HumiditySensor1.humidity().getEvent(&event);
  HumiditySensor1.humidity().getEvent(&event);
  if (event.relative_humidity <= event.relative_humidity)
    {
        buttonState=false;
    }


   
  if(buttonState)
  {
    Blower.StartBlower();
  }
  else{
    Blower.StopBlower();
  }
}
