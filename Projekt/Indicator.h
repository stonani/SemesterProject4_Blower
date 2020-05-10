
class Indicator {  
  public:  
    int _ledtpin2;   

    void SetUp(int ledtpin2)
    {
      _ledtpin2 = ledtpin2;
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
