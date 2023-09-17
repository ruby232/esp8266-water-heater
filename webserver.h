#ifndef WEBSERVER_H
  #define WEBSERVER_H
  #include <Arduino.h>
  #include <ESP8266WebServer.h>

  void webserver_setup();
  void webserver_loop();
  void handleRoot();
  void handleNotFound();
#endif

