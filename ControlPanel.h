
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
        return true;
      }
      else{
        return false;
      }
    }


    bool ControlPanel::IsStopButtonPressed() 
    {  
      if(digitalRead(StopButtonPin)==HIGH)
      {
         return true;
      }
      else{
        return false;
      }
    }
};

    ControlPanel ControlPanel;
