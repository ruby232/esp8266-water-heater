// #include <ESP8266HTTPClient.h>
// #include <WiFiClient.h>
// #include <EEPROM.h>
// #define EEPROM_SIZE 12

// void get_remote_schedule() {
//   //Init EEPROM
//   EEPROM.begin(EEPROM_SIZE);

//   int address = 0;
//   int readId;
//   EEPROM.get(address, readId);
//   EEPROM.end();


//     WiFiClient client;
//     HTTPClient http;

// //https://medium.com/@dfa_31434/doing-ssl-requests-on-esp8266-correctly-c1f60ad46f5e
//     Serial.print("[HTTP] begin...\n");
//     if (http.begin(client, "https://gist.githubusercontent.com/ruby232/832a9fece084b50aeeb26bdc68af6008/raw/8ffa6164ef21541814443a86774fa8256c389653/water-heater-schedules.json")) {  // HTTP

//       Serial.print("[HTTP] GET...\n");
//       // start connection and send HTTP header
//       int httpCode = http.GET();

//       // httpCode will be negative on error
//       if (httpCode > 0) {
//         // HTTP header has been send and Server response header has been handled
//         Serial.printf("[HTTP] GET... code: %d\n", httpCode);

//         // file found at server
//         if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
//           String payload = http.getString();
//           Serial.println(payload);
//         }
//       } else {
//         Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
//       }

//       http.end();
//     } else {
//       Serial.println("[HTTP] Unable to connect");
//     }
  
// }