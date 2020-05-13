#line 2 "advanced.ino"

#include <AUnit.h>
using namespace aunit;
//#include <AUnitVerbose.h>
#include "SystemControl.h"
void resetCounters();

FakeHumiditySensor myHumiditySensor;



class SetUp_Sensor1OutSensor2OutValuesSet_sensor1OutAndsensor2OutSetTo2and3: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      myHumiditySensor.SetUp(3,4);
    }
        
}; 

testF(SetUp_Sensor1OutSensor2OutValuesSet_sensor1OutAndsensor2OutSetTo2and3, t1){

   assertEqual(myHumiditySensor.sensor1Out,3);
   assertEqual(myHumiditySensor.sensor2Out,4);
  
  }


void resetCounters()
{
  myHumiditySensor.sensor1Out = 0;
  myHumiditySensor.sensor2Out = 0;
}


void setup() {
  // put your setup code here, to run once:
  delay(1000); // wait for stability on some boards to prevent garbage Serial
  Serial.begin(9600); // ESP8266 default of 74880 not supported on Linux
  while(!Serial); // for the Arduino Leonardo/Micro only
}

void loop() {
  // put your main code here, to run repeatedly:
  aunit::TestRunner::run();
  delay(50);
}
