class IInput {      
  public:   
    virtual int Input(int pinIn)=0;
};

class AnalogInput : public IInput {      
  public:

    virtual int Input(int pinIn)
    {  
      return analogRead(pinIn);
    }
};

class FakeInput : public IInput {      
  public:   
    int inputCounter = 0;
    int pinInValue = 0;
    int inputValue = 0;
    
    virtual int Input(int pinIn)  
    {   
      inputCounter++;
      pinInValue = pinIn;
      return inputValue;
    }
};
