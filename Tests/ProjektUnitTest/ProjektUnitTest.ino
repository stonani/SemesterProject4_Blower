#line 2 "basic.ino"
#include <AUnit.h>
#include "SystemControlUnitTest.h"

void setup() {
  delay(1000); // wait for stability on some boards to prevent garbage Serial
  Serial.begin(115200); // ESP8266 default of 74880 not supported on Linux
  while(!Serial); // for the Arduino Leonardo/Micro only
}

void loop() {
    aunit::TestRunner::run();
}
