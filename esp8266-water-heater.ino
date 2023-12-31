
#include <Arduino.h>
#include <ESP8266WebServer.h>

#include "relay.hpp"
#include "wifi.hpp"
#include "ntp.h"
#include "storage.hpp"
#include "webserver.hpp"
#include "schedules.hpp"

void setup() {
  Serial.begin(9600);
  initWifi();
  timeClient.begin();
  webserver_setup();
  relay_setup();
  storage_setup();
  schedules_setup();
}

void loop() {
  timeClient.update();
  MDNS.update();
  webserver_loop();
}