#include <Ticker.h>

Ticker tickerObj;

void schedules_check() {
  JsonArray schedules_array = schedules.as<JsonArray>();
  for (JsonObject item : schedules_array) {
    int hour = item["hour"];
    int minute = item["minute"];
    int state = item["state"];

    int current_hour = timeClient.getHours();
    int diff_minute = timeClient.getMinutes() - minute;
    if (hour == current_hour && (diff_minute > -1 && diff_minute <= 2)) {
      Serial.print("Time:");
      Serial.print(hour);
      Serial.print(":");
      Serial.print(minute);
      Serial.print(", Set state:");
      Serial.println(state);
      relay_set_state(state);
      break;
    }
  }
}

void schedules_setup() {
  tickerObj.attach(60, schedules_check);
}
