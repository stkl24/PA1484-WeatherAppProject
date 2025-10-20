#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "list.hpp"
#include <HTTPClient.h>
#include <FS.h>
#include <SPIFFS.h>
using namespace std;


#define SMHI_URL "https://opendata-download-metobs.smhi.se/api/version/latest/parameter/1/station/65090/period/latest-months/data.csv"
#define WEATHER_FILE "/weather_data.csv"


void funk(List* historicalData) {
   
    int i = 0;
    string date,time,temperature;
    fstream dataFile;
   
    
    dataFile.open("smhi.csv", ios::in);
    string dataLine;
    while (getline(dataFile,dataLine)){
        i++;
        if (i>10) {
            date = dataLine.substr(0,10);
            time = dataLine.substr(11,8);
            temperature = dataLine.substr(20,4);

            historicalData->addData(date, time, temperature);
            
        }
    }
    dataFile.close();
}

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

List getData(){
  List historicalData;
   fetchWeatherData();
   funk(&historicalData);
    return historicalData;
}
