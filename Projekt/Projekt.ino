#include "SystemControl.h"

Blower myBlower;
ControlPanel myControlPanel;
HumiditySensor myHumiditySensor;
Indicator myIndicator;

SystemControl mySystemControl;

void setup()
{
  mySystemControl.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
}

void loop()
{
  mySystemControl.Loop();
  delay(100);
}
