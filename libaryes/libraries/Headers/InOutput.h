class IInOutput {      
  public:   

    void Output(int pinOut, int value)=0;

    int Input(int pinIn, int value)=0;
};

class AnalogInOutput {      
  public:   

    void AnalogOutput(int pinOut, int value) 
    {  
      analogWrite(pinOut,value);
    }

    int AnalogInput(int pinIn, int value)  
    {  
      return analogRead(pinIn,value);
    }
};
