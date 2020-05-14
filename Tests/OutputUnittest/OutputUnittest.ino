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

AnalogOutput uut;

class SetUp_PinModeForPin5SetToInput_PinmodeForPin5IsOutput: public TestOnce {
  protected:
    void setup() override {
      
      // Sætter pinmode til OUTPUT på ben 5.
      pinMode(5,OUTPUT);
      //Sætter output på pin 5 til LOW = 0
      PORTE |= 0 << 3 ;
     
    }
        
}; 

testF(SetUp_PinModeForPin5SetToInput_PinmodeForPin5IsOutput, t1){
  
  int outputValue = 255;
  uut.Output(5,outputValue);
//Checker i data direction register om bit 3 er 1 eller 0. Digital pin 5
//Er knyttet til data direction register E og bit 3 fortæller om mode er input = 0 eller 1 = output

      if ( PORTE & _BV(3) ) 
      {   // Check bit #3 of the data direction register for port E
          pass();
      } else 
      {
          fail();
      }
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
