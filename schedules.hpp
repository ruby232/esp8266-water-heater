#include <Ticker.h>

Ticker tickerObj;

void schedules_check() {
      Serial.println("Entre");

  // JsonArray arr = schedules.as<JsonArray>();

  // for (JsonVariant item : arr) {
  //   Serial.println(value.as<const char*>());
  // }


  // for (const auto& item : schedules.as<JsonObject>()) {
  //   Serial.print(item.hour);
  //   Serial.print(":");
  //   Serial.print(item.minute);
  //   Serial.println("----");
  // }

  // for (JsonPair kv : schedules.as<JsonObject>()) {
  //   Serial.print(kv.key().c_str());
  //   Serial.println(":");
  //   for (JsonObject obj : kv.value().as<JsonArray>()) {
  //     Serial.print(" - ");
  //     // Serial.println(obj["hour"].as<char*>());
  //   }
  // }

JsonArray schedules_array = schedules.as<JsonArray>();
for (JsonObject item : schedules_array) {
    int hour = item["hour"];
    int minute = item["minute"];
    int state = item["state"];

    int current_hour = timeClient.getHours();
    int diff_minute = timeClient.getMinutes() - minute;
    if(hour == current_hour && (diff_minute > -1 && diff_minute <= 2 )){
        Serial.print("Time:");
        Serial.print(hour);
        Serial.print(":");
        Serial.print(minute);
        Serial.print(", Set state:");
        Serial.println(state);
        relay_set_state(state);
        break;
    }
    // for (JsonPair kv : a) {
    //     if(kv.key().c_str() === "hour"){
    //       hour = kv.value().as<int>();
    //     }
    //     if(kv.key().c_str() === "minute"){
    //       hour = kv.value().as<int>();
    //     }
    //     // if (kv.value().is<int>()) {
    //         Serial.println();
    //     // }
    //     // else {
    //     //     Serial.println(kv.value().as<bool>());
    //     // }
    // }
}

}

void schedules_setup() {
  tickerObj.attach(60, schedules_check);
}
