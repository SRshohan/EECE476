#include "AirQualitySensor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int AirQualitySensor::getReading(){
    srand(time(0));

    int min = 0;
    int max = 50;

    double random = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);

    int result = min + random * (max - min);

    return result;

}


int main(){
    AirQualitySensor air = AirQualitySensor();
    cout << air.getReading() << endl;

};