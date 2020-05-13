class IOutput {      
  public:
    virtual void Output(int pinOut, int value)=0;
    virtual ~IOutput() = default;
};

class AnalogOutput : public IOutput {      
  public:   

    virtual void Output(int pinOut, int value) 
    {  
      analogWrite(pinOut,value);
    }
};

class FakeOutput : public IOutput {      
  public:   
    int outputCounter = 0;
    int pinOutValue = 0;
    int outputValue = 0;
    
    virtual void Output(int pinOut, int value) 
    {  
      outputCounter++;
      pinOutValue = pinOut;
      outputValue = value;
    };
};
