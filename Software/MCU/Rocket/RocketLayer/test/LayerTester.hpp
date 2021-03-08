#pragma once
#include "RocketLayer.hpp"
#include <string>
#include <cinttypes>
#include <fstream>

//pyro 0 set to stage 1 burnout plus 5 seconds tilt locked
//pyro 2 set to apogee no tilt lock
//pyro 3 set to 200m and past apogee tilt lock
#define SET_PYROS_MSG
#define SET_MOTOR_THRESHOLDS_MSG
#define SET_ACCEL_ONLY_MSG






struct SensorData {
  float timeStep;
  float stepNum;
  float accelX;
  float accelY;
  float accelZ;
  float gyroX;
  float gyroZ;
  float pressure;
  float trueAltitude;
  float trueAngle;
};
struct Message {
  uint8_t * msg;
  int size;
};

class RocketLayerTester {
public:
  RocketLayerTester(std::string inputFile,
		    int (*checkPyros)(void*, SensorData),
		    void* pyroCheckerConetext,
		    Message * messages,
		    int numMessages);
  
  void runSimulation();
private:
  std::ifstream inputFile;
};
