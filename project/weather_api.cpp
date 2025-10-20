#include "weather_api.h"
#include <HTTPClient.h>
#include <FS.h>
#include <SPIFFS.h>

#define SMHI_URL "https://opendata-download-metobs.smhi.se/api/version/latest/parameter/1/station/65090/period/latest-months/data.csv"
#define WEATHER_FILE "/weather_data.csv"

void fetchWeatherData() {
  SPIFFS.begin(true);

  HTTPClient http;
  http.begin(SMHI_URL);

  int httpCode = http.GET();
  if (httpCode != HTTP_CODE_OK) {
    Serial.println("Error: HTTP request failed!");
    http.end();
    return;
  }

  String payload = http.getString();
  http.end();

  File file = SPIFFS.open(WEATHER_FILE, FILE_WRITE);
  if (!file) {
    Serial.println("Error: Could not create weather file!");
    return;
  }

  file.print(payload);
  file.close();
}
