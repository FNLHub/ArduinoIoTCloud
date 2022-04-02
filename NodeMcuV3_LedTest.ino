#include "thingProperties.h"
#define LEDpin D4   //set led pin

void setup() {
  pinMode(LEDpin, OUTPUT);
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here
  random_value = random(0, 500);
  delay(500);
}


void onLedSwitchChange() {
  // Do something
  if (led_switch) {
    digitalWrite(LEDpin, LOW);
  }
  else {
    digitalWrite(LEDpin, HIGH);
  }
}
