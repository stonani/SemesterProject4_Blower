
class Indicator {  
  public:  
    int _ledtpin2;   

    void SetUp(int ledtpin1, int ledtpin2)
    {
      _ledtpin2 = ledtpin2;

      analogWrite(ledtpin1,255); //Supply LED1 med 5V
    }

    bool TurnOn() 
    {  
      analogWrite(_ledtpin2,255);
    }

    bool TurnOff() 
    {  
      analogWrite(_ledtpin2,0);
    }
};

    Indicator Indicator;
