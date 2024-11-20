# Smart Home Environmental Monitoring System

## Introduction

The objective of this project is to develop a smart home environmental monitoring system that uses linked stack and priority queue data structures to manage sensor data and handle urgent alerts. The system continuously monitors temperature, humidity, and air quality levels, storing recent data for trend analysis and prioritizing alerts based on urgency. These structures help make timely decisions to control environmental systems such as the AC, humidifier, or air purifier.

- **Linked Stack**: This data structure is used to store recent sensor readings. It provides quick access to the most recent data, which is essential for monitoring the current environmental status.
- **Linked Priority Queue**: This is used to store alerts based on their urgency. Higher-priority alerts, such as critical temperature or air quality levels, are handled first.

## System Design

### Components and Their Roles

1. **Sensors**:
   - **Temperature Sensor**: Monitors the room temperature and generates temperature data.
   - **Humidity Sensor**: Monitors the humidity levels in the environment.
   - **Air Quality Sensor**: Monitors the air quality, detecting levels of pollutants.

2. **Linked Stack**:
   - **Role**: Stores recent sensor readings for temperature, humidity, and air quality.
   - **Usage**: The stack is used to maintain a record of the most recent data from each sensor. The stack allows easy access to the latest reading for decision-making. If the system detects a critical condition, such as an unusually high temperature, it can act on the most recent reading stored in the stack.

3. **Linked Priority Queue**:
   - **Role**: Manages alerts that are generated based on sensor data, with priorities assigned to the severity of the issue.
   - **Usage**: When a sensor detects a critical condition, an alert is generated and pushed into the priority queue. Alerts with higher priority will be processed first. For instance, an alert for a high temperature might have a higher priority than an alert for a minor change in humidity.

4. **Smart Home Controller**:
   - **Role**: This component processes sensor data, makes decisions based on the readings, and handles alerts from the priority queue.
   - **Usage**: The controller uses the linked stack to make decisions based on recent data, activating devices like the AC, humidifier, or air purifier. It also processes alerts from the linked priority queue to handle urgent issues efficiently.

### Data Flow and Interaction

1. **Sensor Data Storage**: 
   - Sensor readings are generated continuously by the Temperature, Humidity, and Air Quality sensors.
   - These readings are pushed into the corresponding linked stack to keep track of the most recent values.

2. **Alert Generation and Handling**:
   - When a sensor reading exceeds predefined thresholds (e.g., temperature > 30°C), an alert is generated with a specified priority (e.g., high priority for critical temperature readings).
   - The alert is added to the linked priority queue. Alerts with higher priorities will be processed first by the smart home controller.

3. **Decision Making**:
   - The smart home controller checks the top readings from the stack and evaluates if any action (e.g., turning on the AC, humidifier, etc.) is required based on the data.
   - Alerts in the priority queue are processed and acted upon in order of urgency.

### Graph/Diagram

Below is a diagram illustrating the relationships between the system components:

![System Diagram](/Project_4/Screenshot%202024-11-19%20at%208.52.05 PM.png)

**Data Flow**:
- Sensor data (temperature, humidity, and air quality) moves into the corresponding linked stack.
- Alerts are generated based on threshold conditions and are pushed into the linked priority queue.
- The smart home controller processes the top alerts from the queue in order of priority and makes decisions (e.g., turning on AC, air purifier).

## Embedded Systems Testing

### Testing on the Embedded Platform

The system was tested on an embedded platform designed for real-time environmental monitoring. Key tests included:
1. **Sensor Data Collection**: Simulated readings from the temperature, humidity, and air quality sensors were collected and verified against predefined thresholds.
2. **Push and Pop Operations**: The linked stack and priority queue operations were tested by pushing mock sensor readings and alerts and ensuring they were correctly stored and retrieved.
3. **Decision Making**: The smart home controller’s decision-making process was tested by feeding in various sensor readings and ensuring the controller responded with the appropriate actions (e.g., activating cooling or purification systems).
4. **Alert Handling**: The system was tested to ensure that the priority queue correctly handled alerts, prioritizing the most urgent alerts.

## Conclusion

The linked stack and priority queue data structures proved to be effective in handling real-time sensor data and alerts within the smart home system. The stack allowed for easy storage and retrieval of the most recent sensor readings, while the priority queue enabled efficient processing of urgent alerts. The system demonstrated its ability to respond to environmental changes promptly, activating devices like the AC and air purifier as needed.

### Limitations and Areas for Improvement:
- **Real-time Constraints**: While the current implementation performs well in non-real-time scenarios, the system could benefit from optimization for real-time operations, such as faster data retrieval and processing.
- **Alert Prioritization**: Further refinement of alert prioritization could improve the system’s ability to handle complex, multiple alerts simultaneously.
- **Sensor Accuracy**: The accuracy of sensor readings and the responsiveness of the system to small fluctuations could be improved by implementing more advanced filtering techniques.

---

