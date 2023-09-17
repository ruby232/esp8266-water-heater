#include "wifi.h"
#include "secrets.h"

void initWifi() {
  Serial.print("Connecting to: "); 
  Serial.print(ssid);
  WiFi.begin(ssid, password);  

  int timeout = 10 * 4; // 10 seconds
  while(WiFi.status() != WL_CONNECTED  && (timeout-- > 0)) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");

  if(WiFi.status() != WL_CONNECTED) {
     Serial.println("Failed to connect, going back to sleep");
  }

  Serial.print("WiFi connected in: "); 
  Serial.print(millis());
  Serial.print(", IP address: "); 
  Serial.println(WiFi.localIP());

 // Todo, esto no funciono
   if (!MDNS.begin(device_name)) {
    Serial.println("Erro configure mDNS!");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("mDNS configured success.");
  MDNS.addService("telnet", "tcp", 23);
  TelnetStream.begin();
}