#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE DHT22
#define DHTPIN1 3 
#define DHTPIN2 4 
DHT HumiditySensor1(DHTPIN1, DHTTYPE);
DHT HumiditySensor2(DHTPIN2, DHTTYPE);

class IHumiditySensor {  
  public: 

  virtual void SetUp(int sensor1Out, int sensor2Out)=0;   

  virtual float GetSensor1Data()=0;

  virtual float GetSensor2Data()=0;
};


class HumiditySensor : public IHumiditySensor {  
  public: 

  virtual void SetUp(int sensor1Out, int sensor2Out)
  {
     analogWrite(sensor1Out,255);
     analogWrite(sensor2Out,255);
     
     HumiditySensor1.begin();
     HumiditySensor2.begin();
  }    

  virtual float GetSensor1Data()
  {
    return HumiditySensor1.readHumidity();
  }

  virtual float GetSensor2Data()
  {
    return HumiditySensor2.readHumidity();
  }
};


class FakeHumiditySensor : public IHumiditySensor {  
  public: 
    int humidityCouner = 0;
    int sensor1Counter = 0;
    int sensor2Counter = 0;
    int returnValue = 0;

  virtual void SetUp(int sensor1Out, int sensor2Out)
  {
    humidityCouner++;
  }    

  virtual float GetSensor1Data()
  {
    sensor1Counter++;
    return returnValue;
  }

  virtual float GetSensor2Data()
  {
    sensor2Counter++;
    return returnValue;
  }
};
