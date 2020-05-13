class IIndicator { 
  private:
    int _pinOut; 
     
  public:   

    virtual void SetUp(int pinOut)=0;

    virtual void TurnOn()=0;

    virtual void TurnOff()=0;
};

class Indicator : public IIndicator { 
  private:
    int _pinOut; 
    IOutput * _output;
        
  public:
  Indicator(IOutput *output){
    _output = output;
    }   

    virtual void SetUp(int pinOut)
    {
      _pinOut = pinOut;
    }

    virtual void TurnOn() 
    {  
       _output->Output(_pinOut,255);
    }

    virtual void TurnOff() 
    {  
       _output->Output(_pinOut,0);
    }
};

class FakeIndicator : public IIndicator { 
  private:
    int _pinOut; 
         
  public:   
    int ONcounter = 0;
    int OFFcounter = 0;
    int indicatorCounter = 0;

    virtual void SetUp(int pinOut)
    {
      indicatorCounter++;
      _pinOut = pinOut;
    }

    virtual void TurnOn() 
    {  
      ONcounter++;
    }

    virtual void TurnOff() 
    {  
      OFFcounter++;
    }
};
