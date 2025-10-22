
#include "include/rapidjson/document.h"
// Credit: RapidJSON - Copyright (C) 2015 THL A29 Limited, a Tencent company, and Milo Yip.
// RapidJSON directory som gör att det blir lättare att hantera och läsa JSON-filer
// Jag har lagt till fil-directoryt i API-foldern under "include". 
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
using namespace rapidjson;    // Ska finnas med för att använda RapidJSON folder


// https://opendata-download-metfcst.smhi.se/api/category/snow1g/version/1/geotype/point/lon/15.58661/lat/56.16156/data.json    URL forecast data för Karlskrona



int main() {
  //https://www.geeksforgeeks.org/cpp/rapidjson-file-read-write-in-cpp/     Hjälp för att använda RapidJSON
  //https://rapidjson.org/md_doc_tutorial.html                              Dokumentation och tutorial för RapidJSON



  // Open the specified file
  ifstream file("forecast_test_data.json");

  // Read the entire file into a string
  string json((istreambuf_iterator<char>(file)),
              istreambuf_iterator<char>());

  // Create a documentument object to hold the JSON data
  Document document;

  // Parse the JSON data
  document.Parse(json.c_str());

  // Check for parse errors
  if (document.HasParseError()) {
      cerr << "Error parsing JSON: "
            << document.GetParseError() << endl;
      return 1;
  }

  // Close the file
  file.close();

  // Now you can use the document object to access the JSON data


  // Här använder jag dokumentet som RapidJSON sparat lästa datan till
  // I den letar jag efter en grupp som heter 'timeSeries'
  // timeSeries är en array, som har varje timme på varje plats i sin array
  // I arrayen ska jag sedan leta efter rätt timme och ta fram data för tid och data -> air_temperature
  // RapidJSON anväder GetString, GetFloat etc. beroende på vilken data du letar efter.
  std::cout << document["timeSeries"][0]["time"].GetString() << std::endl;
  std::cout << document["timeSeries"][0]["data"]["air_temperature"].GetFloat() << std::endl;

  std::cout << document["timeSeries"][1]["time"].GetString() << std::endl;
  std::cout << document["timeSeries"][1]["data"]["air_temperature"].GetFloat() << std::endl;

} 


/*
Plan:
ladda ner url filen lokalt, sparas som JSON
hämta JSON parsing library --> https://github.com/Tencent/rapidjson/tree/24b5e7a8b27f42fa16b96fc70aade9106cf7102f/include/rapidjson

NOTERA: Detta är ett tredjepartsrepository, ge credit
läsa igenom JSON filen

Vi söker:
timeSeries  -> hour nr  -> time ("2025-10-22T12:00:00Z")
            -> hour nr  -> data -> air_temperature (float)

All data i timeSeries sparas som en array, där varje plats i array är en timmes tid med sin data under den timmen.


leta efter kl. 12 -> loop räknar till 7 st. kl 12 mätningar

För varje tid (7 st), hitta korresponderande lufttemp
Spara värde i en egen definierad array

*/




