#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "WeatherSnapshot.h"
using namespace std;


//tar in filens namn som en string. T.ex "smhi.csv"

vector<WeatherSnapshot> parseFile(string fileName) {
    int i = 0;
    string date,time,temperature;
    fstream dataFile;
    vector<WeatherSnapshot> snapshots = {}; 
    
    dataFile.open(fileName, ios::in);
    string dataLine;
    while (getline(dataFile,dataLine)){
        i++;
        if (i>10) {
            date = dataLine.substr(0,10);
            time = dataLine.substr(11,8);
            temperature = dataLine.substr(20,4);
            auto snapshot = new WeatherSnapshot(date,time,stod(temperature));
            snapshots.push_back(*snapshot);
            
        }
    }

    dataFile.close();
    return snapshots;
}

/*
int main(){
    vector<WeatherSnapshot> snapshots = funk("smhi.csv");
    for (int j = 0; j<snapshots.size();j++){
        auto snapshot = snapshots.at(j);
        //You can access the objects components. You can remove these lines
        cout << snapshot.date << " " << snapshot.time << " " << snapshot.temperature << endl;
    }
    return 0;
}
*/