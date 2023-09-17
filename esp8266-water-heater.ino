
#include <Arduino.h>
#include "relay.hpp"
#include "wifi.h"
#include "ntp.h"
// Todo, no working
// #include "ota.h"
#include "webserver.h"

void setup() {
  Serial.begin(115200);
  initWifi();
  timeClient.begin();
  webserver_setup();
  relay_setup();
}

void loop() {
  timeClient.update();
  MDNS.update();
  webserver_loop();
}
