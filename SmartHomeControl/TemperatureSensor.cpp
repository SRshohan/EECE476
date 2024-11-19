#include "TemperatureSensor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


double temperature::getReading(){
        srand(time(0));

        double min = 15.000;
        double max = 30.000;

        double random = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);

        double result = min + random * (max - min);

        return result;
};

