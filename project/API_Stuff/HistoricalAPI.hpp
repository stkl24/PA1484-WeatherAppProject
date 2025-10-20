#ifndef HistoricalAPI_HPP
#define HistoricalAPI_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "list.hpp"
#include <HTTPClient.h>
#include <FS.h>
#include <SPIFFS.h>

class HistoricalAPI {
public:
   List getData();

private:
    List historicalData;
};

#endif // HistoricalAPI_HPP