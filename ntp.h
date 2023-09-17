#ifndef NTP_H
  #define NTP_H
  #include <Arduino.h>
  #include <NTPClient.h>
  #include <WiFiUdp.h>

  const long utcOffsetInSeconds = -10800;
  char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

  // Define NTP Client to get time
  WiFiUDP ntpUDP;
  NTPClient timeClient(ntpUDP, utcOffsetInSeconds);

#endif