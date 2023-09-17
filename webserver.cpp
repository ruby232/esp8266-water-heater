#include "webserver.h"
#include "relay.hpp"

ESP8266WebServer server(80);

void webserver_setup() {
  server.on("/", handleRoot);

  server.on("/get-state", []() {
    uint8_t value = relay_get_state();
    char stringNum[1];
    sprintf(stringNum,"%d",value);
    server.send(200, "text/plain", stringNum);
  });

  server.on("/state-on", []() {
    relay_set_state(HIGH);
    server.send(204);
  });

  server.on("/state-off", []() {
    relay_set_state(LOW);
    server.send(204);
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void handleRoot() {
  StreamString temp;
  temp.reserve(500);  // Preallocate a large chunk to avoid memory fragmentation
  temp.printf("\
<html>\
  <head>\
    <meta http-equiv='refresh' content='5'/>\
    <title>Water heater</title>\
  </head>\
  <body>\
    <h1>Water heater</h1>\
  </body>\
</html>");
  server.send(200, "text/html", temp.c_str());
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) { message += " " + server.argName(i) + ": " + server.arg(i) + "\n"; }
  server.send(404, "text/plain", message);
}

void webserver_loop() {
  server.handleClient();
}