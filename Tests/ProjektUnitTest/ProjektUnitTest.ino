#line 2 "advanced.ino"

#include <AUnit.h>
using namespace aunit;
//#include <AUnitVerbose.h>
#include "SystemControl.h"
FakeBlower myBlower;
FakeControlPanel myControlPanel;
FakeHumiditySensor myHumiditySensor;
FakeIndicator myIndicator;
      
  SystemControl uut;

int N=0;

<<<<<<< HEAD

class StartButtonNotPressed_stateFalse_IsStartButtonPressedOneCall: public TestOnce {
  protected:
    void setup() override {
      void resetCounters();                
      uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
    
 
     
                    
};

testF(StartButtonNotPressed_stateFalse_IsStartButtonPressedOneCall,simple1) {
  assertEqual(myControlPanel.startCounter,1); 
}

  
class StartButtonNotPressed_StateFalse_StopBlowerTurnOffIndicator: public TestOnce {
  protected:
    void setup() override {
      void resetCounters();                
      uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }   
     
 
     
 
};
testF(StartButtonNotPressed_StateFalse_StopBlowerTurnOffIndicator,t1) {

 
  assertEqual(myBlower.stopCounter,1); 
  assertEqual(myIndicator.OFFcounter,1);
 
}


class StopButtonNotPressed_StateFalse_OneCallRecieved: public TestOnce {
  protected:
    void setup() override {
      void resetCounters();                
      uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
    
     void resetCounters(); 
    
   
};
testF(StopButtonNotPressed_StateFalse_OneCallRecieved,t2) {
 
  assertEqual(myControlPanel.stopCounter,1); 
}

 
class StartbuttonPressed_StateTrue_StartBlowerTurnOnIndicator: public TestOnce {
  protected:
    void setup() override {

      void resetCounters();
      uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      myControlPanel.returnValueStart = true;
      uut.Loop();
    }
      
      
     

}; 

testF(StartbuttonPressed_StateTrue_StartBlowerTurnOnIndicator, simple2){

   assertEqual(myBlower.startCounter,1);
   assertEqual(myIndicator.ONcounter,1);
  
  }




class HumiditySensor1_FloatZero_OneCallRecieved: public TestOnce {
  protected:
    void setup() override {
      void resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
          

}; 
testF(HumiditySensor1_FloatZero_OneCallRecieved,simple4) {
 
  assertEqual(myHumiditySensor.sensor1Counter,1); 
 
}





class HumiditySensor2_FloatZero_OneCallRecieved: public TestOnce {
  protected:
    void setup() override {
     void resetCounters();
     uut.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
      uut.Loop();
    }
    
   

}; 
testF(HumiditySensor2_FloatZero_OneCallRecieved,simple5) {
 
  assertEqual(myHumiditySensor.sensor2Counter,1); 
 
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
}

void setup() {
  
  delay(1000); // wait for stability on some boards to prevent garbage Serial
  Serial.begin(9600); // ESP8266 default of 74880 not supported on Linux
  while(!Serial); // for the Arduino Leonardo/Micro only
}

void loop() {
   
    aunit::TestRunner::run();
    delay(50);
}
