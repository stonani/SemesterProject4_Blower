
class ControlPanel {  
  public:  
    int _startButtonPin;    
    int _stopButtonPin;   

    void SetUp(int startpin, int stoppin)
    {
      _startButtonPin= startpin;
      _stopButtonPin= stoppin;
    }

    bool IsStartButtonPressed() 
    {  
      if(digitalRead(_startButtonPin)==HIGH)
      {
        return true;
      }
      else{
        return false;
      }
    }

    bool IsStopButtonPressed() 
    {  
      if(digitalRead(_stopButtonPin)==HIGH)
      {
         return true;
      }
      else{
        return false;
      }
    }
};

    ControlPanel ControlPanel;
