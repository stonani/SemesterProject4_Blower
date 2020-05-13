#line 2 "advanced.ino"

#include <AUnit.h>
using namespace aunit;
//#include <AUnitVerbose.h>
#include "Output.h"
#include "Input.h"
#include "Blower.h"
#include "ControlPanel.h"
#include "HumiditySensor.h"
#include "Indicator.h"
#include "SystemControl.h"

FakeOutput myOutput;
FakeHumiditySensor myHumiditySensor;
HumiditySensor uut(&myOutput);

void resetCounters();


class SetUp_Sensor1OutSensor2OutValuesSet_OutPutCalledTwice: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      
    }
        
}; 

testF(SetUp_Sensor1OutSensor2OutValuesSet_OutPutCalledTwice, t1){
  uut.SetUp(3,4);
  assertEqual(myOutput.outputCounter,2);
  }


class SetUp_Sensor2OutValuesSet_PinOutValueAndOutputValueSet3And4: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
    }
        
}; 
testF(SetUp_Sensor2OutValuesSet_PinOutValueAndOutputValueSet3And4, t2){
      uut.SetUp(3,7);

  assertEqual(myOutput.pinOutValue,7);
  assertEqual(myOutput.outputValue,255);
  }



class SensorData_ReturnValuesSet5And8_GetSensorDataReturn5And8: public TestOnce {
  protected:
    void setup() override {
      
      resetCounters();
      myHumiditySensor.returnValueSensor1 = 5;
      myHumiditySensor.returnValueSensor2 = 8;
    }
        
}; 

testF(SensorData_ReturnValuesSet5And8_GetSensorDataReturn5And8, t2){
 
   assertEqual(myHumiditySensor.GetSensor1Data(),5.0);
   assertEqual(myHumiditySensor.GetSensor2Data(),8.0);
  
  }

void resetCounters()
{
  myHumiditySensor.sensor1Out = 0;
  myHumiditySensor.sensor2Out = 0;
  myOutput.outputCounter = 0;
  myOutput.pinOutValue = 0;
  myOutput.outputValue = 0;
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
