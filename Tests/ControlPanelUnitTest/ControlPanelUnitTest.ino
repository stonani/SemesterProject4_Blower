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
FakeInput myInput;
ControlPanel uut(&myOutput,&myInput);

void resetCounters();

class SetUp_SetUpCalledWith1111_OutputCalledTwice: public TestOnce {
  protected:
    void setup() override {
      resetCounters();    
    }
        
}; 

testF(SetUp_SetUpCalledWith1111_OutputCalledTwice, t1){
   uut.SetUp(1,1,1,1);
   assertEqual(myOutput.outputCounter,2);
  
}

class SetUp_SetUpCalledWith1114_OutputValueIs255AndPinOutValueIs4: public TestOnce {
  protected:
    void setup() override {
      resetCounters();    
    }
        
}; 

testF(SetUp_SetUpCalledWith1114_OutputValueIs255AndPinOutValueIs4, t1){
   uut.SetUp(1,1,1,4);
   assertEqual(myOutput.pinOutValue,4);
   assertEqual(myOutput.outputValue,255);
  
}

///
///IsStartButtonPressed test
///


class IsStartButtonPressed_MethodCalled_InputIsCalledOnce: public TestOnce {
  protected:
    void setup() override {
      resetCounters();       
      uut.SetUp(1,1,1,1);
    }
        
}; 

testF(IsStartButtonPressed_MethodCalled_InputIsCalledOnce, t1){
   uut.IsStartButtonPressed();

   assertEqual(myInput.inputCounter,1);
  
}


class IsStartButtonPressed_SetupCalledMethodCalled_pinValueIs3: public TestOnce {
  protected:
    void setup() override {
      resetCounters();       
      uut.SetUp(3,1,1,1);
    }
        
}; 

testF(IsStartButtonPressed_SetupCalledMethodCalled_pinValueIs3, t1){
   uut.IsStartButtonPressed();

   assertEqual(myInput.pinInValue,3);
  
}



class IsStartButtonPressed_ValueOver300_returnTrue: public TestOnce {
  protected:
    void setup() override {
      resetCounters();  
      myInput.inputValue = 300; 
      uut.SetUp(1,1,1,1);
    }
        
}; 

testF(IsStartButtonPressed_ValueOver300_returnTrue, t1){
   bool result = uut.IsStartButtonPressed();
   
   assertEqual(result,true);
  
}


class IsStartButtonPressed_ValueEqual255_returnFalse: public TestOnce {
  protected:
    void setup() override {
      resetCounters();  
      myInput.inputValue = 255; 
      uut.SetUp(1,1,1,1);
    }
        
}; 

testF(IsStartButtonPressed_ValueEqual255_returnFalse, t1){
   bool result = uut.IsStartButtonPressed();
   
   assertEqual(result,false);
  
}

class IsStartButtonPressed_Value200_returnFalse: public TestOnce {
  protected:
    void setup() override {
      resetCounters();  
      myInput.inputValue = 200; 
      uut.SetUp(1,1,1,1);
    }
        
}; 

testF(IsStartButtonPressed_Value200_returnFalse, t1){
   bool result = uut.IsStartButtonPressed();
   
   assertEqual(result,false);
  
}


///
/// StopButtonPressed test
///

class IsStopButtonPressed_MethodCalled_InputIsCalledOnce: public TestOnce {
  protected:
    void setup() override {
      resetCounters();       
      uut.SetUp(1,1,1,1);
    }
        
}; 

testF(IsStopButtonPressed_MethodCalled_InputIsCalledOnce, t1){
   uut.IsStopButtonPressed();

   assertEqual(myInput.inputCounter,1);
  
}


class IsStopButtonPressed_SetupCalledMethodCalled_pinValueIs3: public TestOnce {
  protected:
    void setup() override {
      resetCounters();       
      uut.SetUp(1,3,1,1);
    }
        
}; 

testF(IsStopButtonPressed_SetupCalledMethodCalled_pinValueIs3, t1){
   uut.IsStopButtonPressed();

   assertEqual(myInput.pinInValue,3);
  
}





class IsStopButtonPressed_ValueOver300_returnTrue: public TestOnce {
  protected:
    void setup() override {
      resetCounters();  
      myInput.inputValue = 300; 
      uut.SetUp(1,1,1,1);
    }
        
}; 

testF(IsStopButtonPressed_ValueOver300_returnTrue, t1){
   bool result = uut.IsStopButtonPressed();
   
   assertEqual(result,true);
  
}


class IsStopButtonPressed_ValueEqual255_returnFalse: public TestOnce {
  protected:
    void setup() override {
      resetCounters();  
      myInput.inputValue = 255; 
      uut.SetUp(1,1,1,1);
    }
        
}; 

testF(IsStopButtonPressed_ValueEqual255_returnFalse, t1){
   bool result = uut.IsStopButtonPressed();
   
   assertEqual(result,false);
  
}

class IsStopButtonPressed_Value200_returnFalse: public TestOnce {
  protected:
    void setup() override {
      resetCounters();  
      myInput.inputValue = 200; 
      uut.SetUp(1,1,1,1);
    }
        
}; 

testF(IsStopButtonPressed_Value200_returnFalse, t1){
   bool result = uut.IsStopButtonPressed();
   
   assertEqual(result,false);
  
}


void resetCounters()
{
 myOutput.pinOutValue=0;
 myOutput.outputValue=0;
 myOutput.outputCounter=0;
 myInput.inputCounter = 0;
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
