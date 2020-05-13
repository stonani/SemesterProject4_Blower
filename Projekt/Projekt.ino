#include "Output.h"
#include "Input.h"
#include "Blower.h"
#include "ControlPanel.h"
#include "HumiditySensor.h"
#include "Indicator.h"
#include "SystemControl.h"

AnalogOutput myOutput;
AnalogInput myInput;
Blower myBlower(&myOutput);
ControlPanel myControlPanel(&myOutput, &myInput);
HumiditySensor myHumiditySensor(&myOutput);
Indicator myIndicator(&myOutput);

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
