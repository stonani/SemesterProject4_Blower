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

Blower uut(&myOutput);

void resetCounters();


class SetUp_PinModeForPin5SetToInput_PinmodeForPin5IsOutput: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      pinMode(5,INPUT);
     
    }
        
}; 

testF(SetUp_PinModeForPin5SetToInput_PinmodeForPin5IsOutput, t1){

  uut.SetUp(5);
//Checker i data direction register om bit 3 er 1 eller 0. Digital pin 5
//Er knyttet til data direction register E og bit 3 fortæller om mode er input = 0 eller 1 = output

      if ( DDRE & _BV(3) ) 
      {   // Check bit #4 of the data direction register for port D
          pass();
      } else 
      {
          fail();
      }
}

class StartBlower_StartBlowerCalled_outPutRecievedOneCall: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
           
    }
        
}; 

testF(StartBlower_StartBlowerCalled_outPutRecievedOneCall, t1){
  uut.StartBlower();

  assertEqual(myOutput.outputCounter,1);

}

class StartBlower_SetupSetsFanpin4StartBlowerCalled_pinValueIs4OutputvalueIs255: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
          uut.SetUp(4); 
    }
        
}; 

testF(StartBlower_SetupSetsFanpin4StartBlowerCalled_pinValueIs4OutputvalueIs255, t1){
  uut.StartBlower();

  assertEqual(myOutput.outputValue,255);
  assertEqual(myOutput.pinOutValue,4);

}



void resetCounters()
{
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
