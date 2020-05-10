#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
  #define DHTTYPE DHT22
  #define DHTPIN1 3 
  #define DHTPIN2 4 
  DHT HumiditySensor1(DHTPIN1, DHTTYPE);
  DHT HumiditySensor2(DHTPIN2, DHTTYPE);

class HumiditySensor {  
  public: 

  void SetUp(int sensor1Out, int sensor2Out)
  {
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
