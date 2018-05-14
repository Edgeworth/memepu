#include "run.h"
#include "led.h"
#include "control.h"

void run() {
  Serial.begin(57600);

  if (0) {
  	runLed();
  } else {
  	runControl();
  }
}
