class IControlPanel {
  private: 
    int _startButtonIn;    
    int _stopButtonIn; 
    
  public:  
    virtual void SetUp(int startButtonIn, int stopButtonIn, int startButtonOut, int stopButtonOut)=0;

    virtual bool IsStartButtonPressed()=0;

    virtual bool IsStopButtonPressed()=0; 
};


class ControlPanel : public IControlPanel{  
  private: 
    int _startButtonIn;    
    int _stopButtonIn; 
    
  public: 
    virtual void SetUp(int startButtonIn, int stopButtonIn, int startButtonOut, int stopButtonOut)
    {
      _startButtonIn= startButtonIn;
      _stopButtonIn= stopButtonIn;
      analogWrite(startButtonOut,255);
      analogWrite(stopButtonOut,255);
    }

    virtual bool IsStartButtonPressed() 
    {  
      if(analogRead(_startButtonIn)>255)
      {
        return true;
 
     }
      else{
        return false;
      }
    }

    virtual bool IsStopButtonPressed() 
    {  
      if(analogRead(_stopButtonIn)>255)
      {
         return true;
      }
      else{
        return false;
      }
    }
};


class FakeControlPanel : public IControlPanel{  
  private: 
    int _startButtonIn;    
    int _stopButtonIn; 
    
  public: 
    int controlPanelCounter = 0;
    int startCounter = 0;
    int stopCounter = 0;
    int returnValue = 0;
  
    virtual void SetUp(int startButtonIn, int stopButtonIn, int startButtonOut, int stopButtonOut)
    {
      controlPanelCounter++;
      _startButtonIn= startButtonIn;
      _stopButtonIn= stopButtonIn;
    }

    virtual bool IsStartButtonPressed() 
    {  
      startCounter++;
      return returnValue;
    }

    virtual bool IsStopButtonPressed() 
    {  
      stopCounter++;
      return returnValue;
    }
};