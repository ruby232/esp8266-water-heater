#ifndef RELAY_PIN
#define RELAY_PIN 0  // GPIO 0 of ESP8266
#endif

void relay_setup() {
  pinMode(RELAY_PIN, OUTPUT);
}

uint8_t relay_get_state() {
  return digitalRead(RELAY_PIN);
}

void relay_set_state(uint8_t value) {
  digitalWrite(RELAY_PIN, value);
}