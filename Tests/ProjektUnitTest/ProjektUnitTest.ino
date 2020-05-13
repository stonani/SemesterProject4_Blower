#line 2 "basic.ino"
#include <AUnit.h>
//#include <AUnitVerbose.h>
#include "SystemControl.h"

FakeBlower myBlower;
FakeControlPanel myControlPanel;
FakeHumiditySensor myHumiditySensor;
FakeIndicator myIndicator;

SystemControl uut;

test(StartButtonNotPressed_StateFalse_StopBlowerTurnOffIdicator) {
 
  assertEqual(myBlower.stopCounter,1); 
  assertEqual(myIndicator.OFFcounter,1);
 
}

test(StopButtonNotPressed_StateFalse_OneCallRecieved) {
 
  assertEqual(myControlPanel.stopCounter,1); 
}

test(HumiditySensor1_FloatZero_OneCallRecieved) {
 
  assertEqual(myHumiditySensor.sensor1Counter,1); 
 
}

test(HumiditySensor2_FloatZero_OneCallRecieved) {
 
  assertEqual(myHumiditySensor.sensor2Counter,1); 
 
}



void setup() {
  uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
  uut.Loop();
  delay(1000);
  Serial.begin(9600); 
  while(!Serial); 
}

void loop() {
    aunit::TestRunner::run();
    delay(50);
}
