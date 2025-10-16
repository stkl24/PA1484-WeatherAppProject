#ifndef WEATHERSNAPSHOT_H
#define WEATHERSNAPSHOT_H
using namespace std;
#include <string>

class WeatherSnapshot{
    public:
    string date;
    string time;
    double temperature;
    WeatherSnapshot(string date, string time, double temperature);
};


#endif

