
class ControlPanel {  
  public:  
    int _startButtonIn;    
    int _stopButtonIn;   

    void SetUp(int startButtonIn, int stopButtonIn, int startButtonOut, int stopButtonOut)
    {
      _startButtonIn= startButtonIn;
      _stopButtonIn= stopButtonIn;
      analogWrite(startButtonOut,255);
      analogWrite(stopButtonOut,255);
    }

    bool IsStartButtonPressed() 
    {  
      Serial.println(analogRead(A1));
      if(analogRead(_startButtonIn)>500)
      {
        return true;
      }
      else{
        return false;
      }
    }

    bool IsStopButtonPressed() 
    {  
      if(digitalRead(_stopButtonIn)==HIGH)
      {
         return true;
      }
      else{
        return false;
      }
    }
};

    ControlPanel ControlPanel;
