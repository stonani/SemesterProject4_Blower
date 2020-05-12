#include <Blower.h>
#include <ControlPanel.h>
#include <HumiditySensor.h>
#include <Indicator.h>
#include <SystemControl.h>

FakeBlower myBlower;
FakeControlPanel myControlPanel;
FakeHumiditySensor myHumiditySensor;
FakeIndicator myIndicator;

SystemControl uut;

test(StartButtonNotPressed_StateFalse_CallStopBlowerTurnOff) {
  mySystemControl.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
  mySystemControl.loop();
  
  assertEqual(myBlower.stopCounter, 1);
  assertEqual(myIndicator.OFFcounter, 1);
}


test(StartButtonPressed_StateTrue_CallStopBlowerTurnOff) {
  mySystemControl.SetUp(&myBlower,&myControlPanel,&myHumiditySensor,&myIndicator);
  mySystemControl.loop();
  
  assertEqual(myBlower.stopCounter, 1);
  assertEqual(myIndicator.OFFcounter, 1);
}
