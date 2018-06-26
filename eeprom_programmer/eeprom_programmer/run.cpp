#include "run.h"
#include "led.h"
#include "control.h"

void run() {
  Serial.begin(57600);

  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT);

  if (!digitalRead(13)) selection ^= 1;
  if (!digitalRead(12)) selection |= 2;
  if (!digitalRead(11)) selection |= 4;

  printf("Selection: %d\n", selection);
  switch (selection) {
  	case 0:
  		runControl();
  		break;
  	case 7:
  		runLed();
  		break;
  }
}
