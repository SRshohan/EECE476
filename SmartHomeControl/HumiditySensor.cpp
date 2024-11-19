#include "HumiditySensor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


double HumiditySensor::getReading(){
    srand(time(0));

    double min = 40.000;
    double max = 70.000;

    double random = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);

    double result = min + random * (max - min);

    return result;

}


int main(){
    HumiditySensor hum = HumiditySensor();
    cout << hum.getReading() << endl;

};