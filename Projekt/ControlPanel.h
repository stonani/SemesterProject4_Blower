
class ControlPanel {  
  public:  
    int _startButtonPin;    
    int _stopButtonPin;   

    void SetUp(int startpin, int stoppin)
    {
      _startButtonPin= startpin;
      pinMode(_startButtonPin,INPUT_PULLUP);
      _stopButtonPin= stoppin;
    }

    bool IsStartButtonPressed() 
    {  
      Serial.println(analogRead(A1));
      if(analogRead(_startButtonPin)>500)
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
