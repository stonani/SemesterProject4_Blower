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

FakeBlower myBlower;
FakeControlPanel myControlPanel;
FakeHumiditySensor myHumiditySensor;
FakeIndicator myIndicator;
SystemControl uut;
void resetCounters();


///
/// StartButtonTest
///
class Loop_StartbuttonPressedStateTrue_StartBlowerTurnOnIndicator: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      myControlPanel.returnValueStart = true;
      uut.Loop();
    }
          
}; 

testF(Loop_StartbuttonPressedStateTrue_StartBlowerTurnOnIndicator, 1){
        
   assertEqual(myControlPanel.IsStartButtonPressed(),true);
   assertEqual(myBlower.startCounter,1);
   assertEqual(myIndicator.ONcounter,1);
  
  }

class Loop_StartButtonNotPressedstateFalse_IsStartButtonPressedOneCall: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
                             
};

testF(Loop_StartButtonNotPressedstateFalse_IsStartButtonPressedOneCall,s) {
  
  assertEqual(myControlPanel.startCounter,1); 
}

  
class Loop_StartButtonNotPressedStateFalse_StopBlowerTurnOffIndicator: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }   
     
 
     
 
};
testF(Loop_StartButtonNotPressedStateFalse_StopBlowerTurnOffIndicator,s) {

  assertEqual(myControlPanel.IsStartButtonPressed(),false);
  assertEqual(myBlower.stopCounter,1); 
  assertEqual(myIndicator.OFFcounter,1);
 
}

//////////////////////////////////////////




///
/// StopButtonTest
///
class Loop_StopButtonNotPressedStateFalse_IsStopButtonPressedOneCallRecieved: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
    
      
    
   
};
testF(Loop_StopButtonNotPressedStateFalse_IsStopButtonPressedOneCallRecieved,s) {
 
  assertEqual(myControlPanel.stopCounter,1); 
}


class Loop_StopButtonPressedstateFalse_StopBlowerTurnOffIndicator: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
    
   

}; 
testF(Loop_StopButtonPressedstateFalse_StopBlowerTurnOffIndicator,s) {
  assertEqual(myControlPanel.IsStopButtonPressed(),false);
  assertEqual(myBlower.stopCounter,1);
  assertEqual(myIndicator.OFFcounter,1); 

}


////////////////////////////




///
///HumiditySensorTest
///
class Loop_GetSensor1DataFloatZero_GetSensor1DataOneCallRecieved: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
          

}; 
testF(Loop_GetSensor1DataFloatZero_GetSensor1DataOneCallRecieved,1) {
  
  assertEqual(myHumiditySensor.sensor1Counter,1); 
  assertEqual(myHumiditySensor.GetSensor1Data(),1.0);
}





class Loop_GetSensor2DataFloatZero_GetSensor2DataOneCallRecieved: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
    
   

}; 
testF(Loop_GetSensor2DataFloatZero_GetSensor2DataOneCallRecieved,s) {
 
  assertEqual(myHumiditySensor.sensor2Counter,1);
    assertEqual(myHumiditySensor.GetSensor2Data(),0.0);
 

}



class Loop_ButtonStateTrueSensor1ValueLargerThanSensor2Value_ButtonStateTrueStartBlowerRecievedOneCall: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
     myControlPanel.returnValueStart = true;
     myHumiditySensor.returnValueSensor1 = 1;
     myHumiditySensor.returnValueSensor2 = 0;
      uut.Loop();
    }
    
   

}; 
testF(Loop_ButtonStateTrueSensor1ValueLargerThanSensor2Value_ButtonStateTrueStartBlowerRecievedOneCall,s1) {
 
  assertEqual(myBlower.startCounter,1);
 

}


class Loop_ButtonStateTrueSensor1EqualSensor2_ButtonStateFalseStopBlowerRecievedOneCall: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
     
     myControlPanel.returnValueStart = true;
     myHumiditySensor.returnValueSensor1 = 1;
     myHumiditySensor.returnValueSensor2 = 1;

     
      uut.Loop();
    }
    
   

}; 
testF(Loop_ButtonStateTrueSensor1EqualSensor2_ButtonStateFalseStopBlowerRecievedOneCall,s1) {
 
  assertEqual(myBlower.stopCounter,1);

}


class Loop_ButtonStateTrueSensor1SmallerThanSensor2_ButtonStateFalseStopBlowerRecievedOneCall: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      myHumiditySensor.returnValueSensor1 = 0;
     myHumiditySensor.returnValueSensor2 = 1;
     myControlPanel.returnValueStart = true;
      uut.Loop();
    }
    
   

}; 
testF(Loop_ButtonStateTrueSensor1SmallerThanSensor2_ButtonStateFalseStopBlowerRecievedOneCall,s1) {
 
  assertEqual(myBlower.stopCounter,1);  

}



///
/// Test af setupfunktionerne
///

class SetupCalled: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);  
    }
       

}; 
testF(SetupCalled,_controlpannelSetupCalled) {
 
  assertEqual(myControlPanel.controlPanelCounter,1);
  assertEqual(myBlower.blowerCounter,1);
  assertEqual(myIndicator.indicatorCounter,1);
  assertEqual(myHumiditySensor.humidityCouner,1);
  
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

void resetCounters()
{
  
      myBlower.blowerCounter=0;
      myBlower.startCounter=0;
      myBlower.stopCounter=0;
      myControlPanel.controlPanelCounter=0;
      myControlPanel.startCounter=0;
      myControlPanel.stopCounter=0;
      myControlPanel.returnValueStart = false;
      myControlPanel.returnValueStop = false;
      myHumiditySensor.humidityCouner=0;
      myHumiditySensor.sensor1Counter=0;
      myHumiditySensor.sensor2Counter=0;
      myHumiditySensor.returnValueSensor1=1;
      myHumiditySensor.returnValueSensor2=0;
      myIndicator.ONcounter=0;
      myIndicator.OFFcounter=0;
      myIndicator.indicatorCounter = 0;
}
