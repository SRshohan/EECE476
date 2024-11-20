# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS = 

# Project files
SRC = SmartHomeControl.cpp \
      TemperatureSensor.cpp \
      HumiditySensor.cpp \
      AirQualitySensor.cpp \
      LinkedStack.cpp \
      LinkedPriorityQueue.cpp \
      SmartHomeController.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = SmartHomeControl

# Default target
all: $(TARGET)

# Linking target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean
