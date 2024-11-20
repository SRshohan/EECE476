#include "SmartHomeController.h"
#include <iostream>

SmartHomeController::SmartHomeController()
    : temperatureStack(10), humidityStack(10), airQualityStack(10) {}

void SmartHomeController::processSensorData(int temp, int humidity, int airQuality) {
    temperatureStack.push(temp);
    humidityStack.push(humidity);
    airQualityStack.push(airQuality);

    handleTemperature(temp);
    handleHumidity(humidity);
    handleAirQuality(airQuality);
}

void SmartHomeController::handleTemperature(int reading) {
    if (reading > 30) {
        alertQueue.push(3, "High temperature! Activate AC.");
    }
}

void SmartHomeController::handleHumidity(int reading) {
    if (reading < 30) {
        alertQueue.push(2, "Low humidity! Activate humidifier.");
    }
}

void SmartHomeController::handleAirQuality(int reading) {
    if (reading < 50) {
        alertQueue.push(1, "Poor air quality! Activate air purifier.");
    }
}

void SmartHomeController::handleAlerts() {
    while (!alertQueue.isEmpty()) {
        std::cout << "Alert: " << alertQueue.pop() << std::endl;
    }
}
