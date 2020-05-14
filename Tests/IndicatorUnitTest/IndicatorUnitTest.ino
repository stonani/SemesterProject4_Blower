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

void resetCounters();

FakeOutput myOutput;
Indicator uut(&myOutput);

class SetUpAndTurnOn_SetUpMethodcalledPinOutSetTo5TurnOnCalled_OutPutPinValueIs5AndOutputvalueIs255: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      uut.SetUp(5);         
    }
        
}; 

testF(SetUpAndTurnOn_SetUpMethodcalledPinOutSetTo5TurnOnCalled_OutPutPinValueIs5AndOutputvalueIs255, t1){

  uut.TurnOn();

  assertEqual(myOutput.pinOutValue,5);
  assertEqual(myOutput.outputValue,255);
  
}


class SetUpAndTurnOn_SetUpMethodcalledPinOutSetTo5TurnOnCalled_OutPutRecievedOneCall: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      uut.SetUp(7);         
    }
        
}; 

testF(SetUpAndTurnOn_SetUpMethodcalledPinOutSetTo5TurnOnCalled_OutPutRecievedOneCall, t1){

  uut.TurnOn();

  assertEqual(myOutput.outputCounter,1);

 
}



///
/// TurnOff test
///




class TurnOff_Methodcalled_OutPutRecievedOneCall: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      uut.SetUp(6);         
    }
        
}; 



testF(TurnOff_Methodcalled_OutPutRecievedOneCall, t1){

  uut.TurnOff();

  assertEqual(myOutput.outputCounter,1);
  
  
}


class TurnOff_MethodcalledPinOutSetTo6_OutPutPinoutValueIs6AndOutputValueIs0: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      uut.SetUp(6);         
    }
        
}; 



testF(TurnOff_MethodcalledPinOutSetTo6_OutPutPinoutValueIs6AndOutputValueIs0, t1){

  uut.TurnOff();

  assertEqual(myOutput.pinOutValue,6);
  assertEqual(myOutput.outputValue,0);
  
}




void resetCounters(){
  myOutput.pinOutValue=0;
  myOutput.outputValue =0;
  myOutput.outputCounter=0;
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
