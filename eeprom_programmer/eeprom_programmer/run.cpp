#include "run.h"
#include "led.h"
#include "control.h"

void programEeprom() {
  switch (selection) {
    case 0:
    case 1:
    case 2:
      runControl();
      break;
    case 3:
      runTest();
      break;
    case 7:
      runLed(false);
      break;
  }
}

void run() {
  Serial.begin(57600);

  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT);

  selection = 0;
  if (digitalRead(13)) selection |= 1;
  if (!digitalRead(12)) selection |= 2;
  if (!digitalRead(11)) selection |= 4;

  printf("Selection: %d\n", selection);
  PROFILE(programEeprom());
}
