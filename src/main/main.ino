// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

//Nao altere a ordem dos includes
#include "src/include/includes.ino"
#include "src/include/constants.ino"
#include "src/include/variables.ino"
#include "src/include/functions.ino"
#include "src/include/wifi.ino"
#include "src/include/webserver.ino"
#include "src/include/ultrassonic.ino"

void setup() {
  Serial.begin(115200); // Serial Communication must always be 115200 on esp32 controller
  setup_ultrassonic();
  setup_wifi();
  setup_web_server();
}
void loop() {
  WiFiClient client = sv.available();
  print_volume_litros();
  delay(1000);
}
