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
class StartbuttonPressed_StateTrue_StartBlowerTurnOnIndicator: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      myControlPanel.returnValueStart = true;
      uut.Loop();
    }
      
      
     

}; 

testF(StartbuttonPressed_StateTrue_StartBlowerTurnOnIndicator, 1){

   assertEqual(myBlower.startCounter,1);
   assertEqual(myIndicator.ONcounter,1);
  
  }

class StartButtonNotPressed_stateFalse_IsStartButtonPressedOneCall: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
                             
};

testF(StartButtonNotPressed_stateFalse_IsStartButtonPressedOneCall,s) {
  
  assertEqual(myControlPanel.startCounter,1); 
}

  
class StartButtonNotPressed_StateFalse_StopBlowerTurnOffIndicator: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }   
     
 
     
 
};
testF(StartButtonNotPressed_StateFalse_StopBlowerTurnOffIndicator,s) {

 
  assertEqual(myBlower.stopCounter,1); 
  assertEqual(myIndicator.OFFcounter,1);
 
}

//////////////////////////////////////////




///
/// StopButtonTest
///
class StopButtonNotPressed_StateFalse_OneCallRecieved: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
      uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
    
      
    
   
};
testF(StopButtonNotPressed_StateFalse_OneCallRecieved,s) {
 
  assertEqual(myControlPanel.stopCounter,1); 
}


class StopButtonPressed_stateFalse_StopBlowerTurnOffIndicator: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
    
   

}; 
testF(StopButtonPressed_stateFalse_StopBlowerTurnOffIndicator,s) {
 
  assertEqual(myBlower.stopCounter,1);
  assertEqual(myIndicator.OFFcounter,1); 

}


////////////////////////////




///
///HumiditySensorTest
///
class HumiditySensor1_FloatZero_OneCallRecieved: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
          

}; 
testF(HumiditySensor1_FloatZero_OneCallRecieved,1) {
 
  assertEqual(myHumiditySensor.sensor1Counter,1); 
 
}





class HumiditySensor2_FloatZero_OneCallRecieved: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
    
   

}; 
testF(HumiditySensor2_FloatZero_OneCallRecieved,s) {
 
  assertEqual(myHumiditySensor.sensor2Counter,1); 

}



class HumiditySensor2_ButtonStateTrueSensor1LargerThanSensor2_ButtonStateTrueStartBlowerRecievedOneCall: public TestOnce {
  protected:
    void setup() override {
      resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
     myControlPanel.returnValueStart = true;

      uut.Loop();
    }
    
   

}; 
testF(HumiditySensor2_ButtonStateTrueSensor1LargerThanSensor2_ButtonStateTrueStartBlowerRecievedOneCall,s1) {
 
  assertEqual(myBlower.startCounter,1);
 

}


class HumiditySensor2_ButtonStateTrueSensor1EqualSensor2_ButtonStateFalseStopBlowerRecievedOneCall: public TestOnce {
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
testF(HumiditySensor2_ButtonStateTrueSensor1EqualSensor2_ButtonStateFalseStopBlowerRecievedOneCall,s1) {
 
  assertEqual(myBlower.stopCounter,1);

}


class HumiditySensor2_ButtonStateTrueSensor1SmallerThanSensor2_ButtonStateFalseStopBlowerRecievedOneCall: public TestOnce {
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
testF(HumiditySensor2_ButtonStateTrueSensor1SmallerThanSensor2_ButtonStateFalseStopBlowerRecievedOneCall,s1) {
 
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