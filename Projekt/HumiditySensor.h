#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

class HumiditySensor {  
  public: 
  int _sensor1In;
  int _sensor2In;
  #define DHTTYPE DHT22
  #define DHTPIN1 _pinSensor1 
  #define DHTPIN2 _pinSensor2 
  DHT HumiditySensor1(DHTPIN1, DHTTYPE);
  DHT HumiditySensor2(DHTPIN2, DHTTYPE);

  void SetUp(int sensor1In, int sensor2In, int sensor1Out, int sensor2Out)
  {
     _sensor1In = sensor1In;
     _sensor2In = sensor2In;

     analogWrite(sensor1Out,255);
     analogWrite(sensor2Out,255);
     
     HumiditySensor1.begin();
     HumiditySensor2.begin();
  }

  float GetSensor1Data()
  {
    return HumiditySensor1.readHumidity();
  }

  float GetSensor2Data()
  {
    return HumiditySensor2.readHumidity();
  }
};
  
HumiditySensor HumiditySensor;
