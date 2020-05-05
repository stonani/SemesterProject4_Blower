class Blower {  
  public:  
    int _fanPin;      

    void SetUp(int fanPin) 
    {  
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
