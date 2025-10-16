#include "weather_api.h"
#include <HTTPClient.h>
#include <FS.h>
#include <SPIFFS.h>

#define SMHI_URL "https://opendata-download-metobs.smhi.se/api/version/latest/parameter/1/station/65090/period/latest-months/data.json"
#define WEATHER_FILE "/weather_data.json"

void fetchWeatherData() {
  SPIFFS.begin(true);

  HTTPClient http;
  http.begin(SMHI_URL);
  http.GET();

  String payload = http.getString();
  http.end();

  File file = SPIFFS.open(WEATHER_FILE, FILE_WRITE);
  file.print(payload);
  file.close();
}
