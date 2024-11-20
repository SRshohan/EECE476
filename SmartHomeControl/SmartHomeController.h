#ifndef SMARTHOMECONTROLLER_H
#define SMARTHOMECONTROLLER_H

#include "LinkedStack.h"
#include "LinkedPriorityQueue.h"

class SmartHomeController {
private:
    LinkedStack temperatureStack;
    LinkedStack humidityStack;
    LinkedStack airQualityStack;
    LinkedPriorityQueue alertQueue;

    void handleTemperature(int reading);
    void handleHumidity(int reading);
    void handleAirQuality(int reading);

public:
    SmartHomeController();
    void processSensorData(int temp, int humidity, int airQuality);
    void handleAlerts();
};

#endif
