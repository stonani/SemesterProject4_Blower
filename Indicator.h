
class Indicator {  
  public:  
    int _ledtpin;   

    void SetUp(int ledtpin)
    {
      _ledtpin= ledtpin;
    }

    bool TurnOn() 
    {  
      analogWrite(_fanPin,255);
    }

    bool TurnOff() 
    {  
      analogWrite(_fanPin,0);
    }
};

    Indicator Indicator;
