
bool _systemState;

class ControlPanel {  
  public:  
    int StartButtonPin;    
    int StopButtonPin;   

    void ControlPanel::SetUp(int startpin, int stoppin)
    {
      StartButtonPin= startpin;
      StopButtonPin= stoppin;
    }

    bool ControlPanel::IsStartButtonPressed() 
    {  
      if(digitalRead(StartButtonPin)==HIGH)
      {
        _systemState=true;
      } 
      return _systemState;
    }


    bool ControlPanel::IsStopButtonPressed() 
    {  
      if(digitalRead(StopButtonPin)==HIGH)
      {
        _systemState=false;
      }
      return _systemState;
    }
};

    ControlPanel ControlPanel;
