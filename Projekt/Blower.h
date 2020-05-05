class Blower {  
  public:  
    int _fanPin;      

    void SetUp(int fanPin) 
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

    void StartBlower() 
    {  
      analogWrite(_fanPin,255);
    }

    void StopBlower() 
    {  
      analogWrite(_fanPin,0);
    }
};

    Blower Blower;
