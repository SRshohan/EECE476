#include "SmartHomeController.h"

int main() {
    SmartHomeController controller;

    // Simulate sensor data
    controller.processSensorData(32, 25, 45); // High temp, low humidity, poor air quality
    controller.processSensorData(22, 50, 90); // Normal conditions

    // Handle alerts
    controller.handleAlerts();

    return 0;
}
