
class ControlPanel {  
  public:  
    int _startButtonPin;    
    int _stopButtonPin;   

    void ControlPanel::SetUp(int startpin, int stoppin)
    {
      _startButtonPin= startpin;
      _stopButtonPin= stoppin;
    }

    bool ControlPanel::IsStartButtonPressed() 
    {  
      if(digitalRead(_startButtonPin)==HIGH)
      {
        return true;
      }
      else{
        return false;
      }
    }


    bool ControlPanel::IsStopButtonPressed() 
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
