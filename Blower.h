class Blower {  
  public:  
    int FanPin;      

    void Blower::SetUp(int fanpin) 
    {  
      FanPin=fanpin;
    }

    void Blower::StartBlower() 
    {  
      analogWrite(FanPin,255);
    }
};

    Blower Blower;
