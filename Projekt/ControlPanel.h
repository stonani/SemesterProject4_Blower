class IControlPanel {
  private: 
    int _startButtonIn;    
    int _stopButtonIn;
     IOutput * _output;
     IInput *_input;  
    
  public:  
    virtual void SetUp(int startButtonIn, int stopButtonIn, int startButtonOut, int stopButtonOut)=0;

    virtual bool IsStartButtonPressed()=0;

    virtual bool IsStopButtonPressed()=0; 
};


class ControlPanel : public IControlPanel{  
  private: 
    int _startButtonIn;    
    int _stopButtonIn;
    IOutput * _output;
    IInput *_input; 
    
  public: 
  ControlPanel(IOutput *output, IInput *input){
    _output=output;
    _input=input;
  }
    virtual void SetUp(int startButtonIn, int stopButtonIn, int startButtonOut, int stopButtonOut)
    {
      _startButtonIn= startButtonIn;
      _stopButtonIn= stopButtonIn;
      _output -> Output(startButtonOut,255);
      _output -> Output(stopButtonOut,255);
    }

    virtual bool IsStartButtonPressed() 
    {  
      if(_input -> Input(_startButtonIn)>255)
      {
        return true;
 
     }
      else{
        return false;
      }
    }

    virtual bool IsStopButtonPressed() 
    {  
      if(_input -> Input(_stopButtonIn)>255)
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
    bool returnValueStart = false;
    bool returnValueStop = false;

  
    virtual void SetUp(int startButtonIn, int stopButtonIn, int startButtonOut, int stopButtonOut)
    {
      controlPanelCounter++;
      _startButtonIn= startButtonIn;
      _stopButtonIn= stopButtonIn;
    }

    virtual bool IsStartButtonPressed() 
    {  
      startCounter++;
      return returnValueStart;
    }

    virtual bool IsStopButtonPressed() 
    {  
      stopCounter++;
      return returnValueStop;
    }
};
