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


#define ACCEPTABLE_ALTITUDE_ERROR 		0.05
#define ACCEPTABLE_ALTITUDE_ERROR_ABS 	10
#define ACCEPTABLE_ANGLE_ERROR 			0.05
#define ACCEPTABLE_ANGLE_ERROR_ABS 		0.17 // about 10 degrees
#define ACCEPTABLE_TIME_PYRO_ERROR 		10 //seconds




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

class RocketLayerTester {
public:
  RocketLayerTester(std::string inputFile);
  
  bool runSimulation();//returns true if succeeds
private:
  void split(std::string const &str, std::vector<float> &out);
  void insertNoise(float *value, float mean, float stdDev);
  std::ifstream inputFile;
};
