class IBlower {  
  private:  
    int _fanPin;  
        
  public:
    virtual void SetUp(int fanPin)=0;

    virtual void StartBlower()=0;

    virtual void StopBlower()=0;
};


class Blower : public IBlower {  
  private:  
    int _fanPin;  
        
  public:
    virtual void SetUp(int fanPin) 
    {  
      TCCR0A = 0;           // undo the configuration done by...
      TCCR0B = 0;           // ...the Arduino core library
      TCNT0  = 0;           // reset timer
      TCCR0A = _BV(COM0B1)  // non-inverted PWM on ch. B
          | _BV(WGM00);  // mode 5: ph. correct PWM, TOP = OCR0A
      TCCR0B = _BV(WGM02)   // ditto
          | 2;   // prescaler = 1
      OCR0A  = 40;         // TOP = 160
    
      _fanPin=fanPin;
      pinMode(_fanPin,OUTPUT);
    }

    virtual void StartBlower() 
    {  
      analogWrite(_fanPin,255);
    }

    virtual void StopBlower() 
    {  
      analogWrite(_fanPin,0);
    }
};


class FakeBlower : public IBlower {  
  private:  
    int _fanPin;  
        
  public:
    int blowerCounter = 0;
    int startCounter = 0;
    int stopCounter = 0;
    
    virtual void SetUp(int fanPin) 
    {  
      blowerCounter++;
      _fanPin=fanPin;
    }

    virtual void StartBlower() 
    {  
      startCounter++;
    }

    virtual void StopBlower() 
    {  
      stopCounter++;
    }
};
