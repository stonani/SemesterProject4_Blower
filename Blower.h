class Blower {  
  public:  
    int _fanPin;      

    void Blower::SetUp(int _fanPin) 
    {  
      _fanPin=_fanPin;
    }

    void Blower::StartBlower() 
    {  
      analogWrite(_fanPin,255);
    }

    void Blower::StopBlower() 
    {  
      analogWrite(_fanPin,0);
    }
};

    Blower Blower;
