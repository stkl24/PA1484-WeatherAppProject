
//#include "rapidjson/document.h" //måste spara ner repo
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
//using namespace rapidjson;


// This is a comment

// https://opendata-download-metfcst.smhi.se/api/category/snow1g/version/1/geotype/point/lon/15.58661/lat/56.16156/data.json    URL forecast data


int main() {

  cout << "Hello" << std::endl;

  // Open the specified file
  ifstream history_file("forecast_test_data.json");

  // Control if file is opened, else raise exception
  if (!history_file.is_open()) {
    std::cerr << "Error: Unable to open the file." << std::endl;
  return 1;
  }

  // Create variable storing line
  string line;

  // For every line in file, print boo
  while (getline(history_file, line)) {
    std::cout << "boo" << std::endl;
  }

  // Close the file
  history_file.close();
} 


/*
Plan:
ladda ner url filen lokalt, sparas som JSON
hämta JSON parsing library --> https://github.com/Tencent/rapidjson/tree/24b5e7a8b27f42fa16b96fc70aade9106cf7102f/include/rapidjson
läsa igenom JSON filen
leta efter kl. 12-13 intervallet
i intervallet, leta efter luft temp
räkna till 7 dagar, 7 st insamlade temp kl 12
*/




