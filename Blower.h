class Blower {  
  public:  
    int _fanPin;      

    void SetUp(int _fanPin) 
    {  
      _fanPin=_fanPin;
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
