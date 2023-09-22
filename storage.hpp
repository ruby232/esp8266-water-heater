#include <EEPROM.h>
#include <ArduinoJson.h>

#define EEPROM_SIZE 512

DynamicJsonDocument schedules(EEPROM_SIZE);
int metaAddress = 0;
int metaLenght = 4;
int jsonAddress = 4;

String EEPROM_read(int index, int length) {
  String text = "";
  char ch = 1;

  for (int i = index; (i < (index + length)) && ch; ++i) {
    if (ch = EEPROM.read(i)) {
      text.concat(ch);
    }
  }
  return text;
}

int EEPROM_write(int index, String text) {
  for (int i = index; i < text.length() + index; ++i) {
    EEPROM.write(i, text[i - index]);
  }
  EEPROM.write(index + text.length(), 0);
  EEPROM.commit();

  return text.length() + 1;
}

DynamicJsonDocument getEEPROM_JSON() {
  String jsonRead = EEPROM_read(jsonAddress, EEPROM_read(metaAddress, metaLenght).toInt());
  DynamicJsonDocument jsonDoc(EEPROM_SIZE);
  deserializeJson(jsonDoc, jsonRead);
  return jsonDoc;
}

String setEEPROM_JSON(String data) {
  DeserializationError error = deserializeJson(schedules, data);

  // Test if parsing succeeds.
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return error.f_str();
  }

  String jsonWriteString;
  serializeJson(schedules, jsonWriteString);
  EEPROM_write(metaAddress, (String)EEPROM_write(jsonAddress, jsonWriteString));
  return "Saved OK";
}

void storage_setup() {
  delay(1000);
  EEPROM.begin(EEPROM_SIZE);
  schedules = getEEPROM_JSON();
}
