class SystemControl { 
  private:
  //Pin configuration
  const int _startButtonIn = A3;
  const int _stopButtonIn = A5;
  const int _startButtonOut = A0;
  const int _stopButtonOut = A1;

  const int _fanSignalOut = 5;

  //const int _Sensor1In = 3; Ligger inde i humiditySensor
  //const int _Sensor2In = 4; Ligger inde i humiditySensor
  const int _Sensor1Out = A14;
  const int _Sensor2Out = A15;

  const int _LED2Out = 2;

  bool _buttonState; //True = fan is on
  
  //Objecter
  IBlower *_blower;
  IControlPanel *_controlPanel;
  IHumiditySensor *_humiditySensor;
  IIndicator *_indicator;

  public:
  void SetUp(IBlower *blower,    IControlPanel *controlPanel,    IHumiditySensor *humiditySensor,    IIndicator *indicator)
  {
    _blower = blower;
    _controlPanel = controlPanel;
    _humiditySensor = humiditySensor;
    _indicator = indicator;
    
     Serial.begin(9600); //Til testning
    
     _controlPanel -> SetUp(_startButtonIn,_stopButtonIn,_startButtonOut,_stopButtonOut);    
     _blower -> SetUp(_fanSignalOut);    
     _humiditySensor -> SetUp(_Sensor1Out,_Sensor2Out);
     _indicator -> SetUp(_LED2Out);
    
     _buttonState=false;
  }

  void Loop()
  {

      if(_controlPanel -> IsStartButtonPressed())//StartButton
      {
         _buttonState=true;
      }
    
      if(_controlPanel -> IsStopButtonPressed())//StopButton
      {
        _buttonState=false;
      }

      if (_humiditySensor -> GetSensor1Data() <=_humiditySensor -> GetSensor2Data())//HumiditySensor
      {
        _buttonState=false;
      }
   
      if(_buttonState)
      {
        _blower -> StartBlower();
        _indicator -> TurnOn();
      }
      else
      {
        _blower -> StopBlower();
        _indicator -> TurnOff();
      }
  }
};
