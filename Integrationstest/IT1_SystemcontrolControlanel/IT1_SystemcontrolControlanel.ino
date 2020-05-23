#line 2 "advanced.ino"
#include <AUnit.h>
using namespace aunit;

#include "Output.h"
#include "Input.h"
#include "Blower.h"
#include "ControlPanel.h"
#include "HumiditySensor.h"
#include "Indicator.h"
#include "SystemControl.h"


FakeOutput _output;
FakeInput _input;
FakeBlower _blower;
ControlPanel _controlPanel(&_output, &_input);
FakeHumiditySensor _humiditySensor;
FakeIndicator _indicator;
SystemControl _systemControl;
void resetCounters();
int N=0;

///
/// SetUp test - Output 
///
class ControlPanelSetUp_PowerTo2Pins: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      _systemControl.SetUp(&_blower,&_controlPanel,&_humiditySensor,&_indicator);
      _systemControl.Loop();
    }                             
};

testF(ControlPanelSetUp_PowerTo2Pins,s) {  
  assertEqual(_output.outputCounter,2);
  assertEqual(_output.outputValue,255); 
}
//////////////////////////////////////////


///
/// Button test -Input
///
class ControlPanalNoButtonPress_2InputCallsValueLow_StateFalse_LedBlowerOff: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      _systemControl.SetUp(&_blower,&_controlPanel,&_humiditySensor,&_indicator);
      _systemControl.Loop();
    }                             
};

testF(ControlPanalNoButtonPress_2InputCallsValueLow_StateFalse_LedBlowerOff,s) {  
  assertEqual(_input.inputCounter,2);
  assertEqual(_input.inputValue,0);

  assertEqual(_blower.blowerCounter,0); 
  assertEqual( _indicator.indicatorCounter,0); 
}

class ControlPanalBothButtonPress_2InputCallsValueHigh_StateFalse_LedBlowerOff: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      _input.inputValue =300;
      _systemControl.SetUp(&_blower,&_controlPanel,&_humiditySensor,&_indicator);
      _systemControl.Loop();
    }                             
};

testF(ControlPanalBothButtonPress_2InputCallsValueHigh_StateFalse_LedBlowerOff,s) {  
  assertEqual(_input.inputCounter,2);
  assertEqual(_input.inputValue,300); 

  assertEqual(_blower.blowerCounter,0); 
  assertEqual( _indicator.indicatorCounter,0); 
}
//////////////////////////////////////////


void setup() {
  _systemControl.SetUp(&_blower,&_controlPanel,&_humiditySensor,&_indicator);
  _systemControl.Loop();
  delay(1000);
  Serial.begin(9600); 
  while(!Serial); 
}

void loop() {   
    aunit::TestRunner::run();
    delay(50);
}

void resetCounters()
{
  N=5;
      _blower.blowerCounter=0;
      _blower.startCounter=0;
      _blower.stopCounter=0;
      _humiditySensor.humidityCouner=0;
      _humiditySensor.sensor1Counter=0;
      _humiditySensor.sensor2Counter=0;
      _humiditySensor.returnValueSensor1=1;
      _humiditySensor.returnValueSensor2=0;
      _indicator.ONcounter=0;
      _indicator.OFFcounter=0;
      _indicator.indicatorCounter = 0;
      _output.outputCounter=0;
      _output.pinOutValue=0;
      _output.outputValue=0;
      _input.inputCounter=0;
      _input.pinInValue=0; 
      _input.inputValue=0; 
}
