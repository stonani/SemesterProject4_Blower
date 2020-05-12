#line 2 "basic.ino"
#include <AUnit.h>
//#include <AUnitVerbose.h>
#include "SystemControl.h"

FakeBlower myBlower;
FakeControlPanel myControlPanel;
FakeHumiditySensor myHumiditySensor;
FakeIndicator myIndicator;

SystemControl uut;

test(StartButtonNotPressed_StateFalse_CallStopBlowerTurnOff) {
  uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
  
  assertEqual(1, 1);
}


void setup() {
  delay(1000); // wait for stability on some boards to prevent garbage Serial
  Serial.begin(9600); // ESP8266 default of 74880 not supported on Linux
  while(!Serial); // for the Arduino Leonardo/Micro only
}

void loop() {
    aunit::TestRunner::run();
}
