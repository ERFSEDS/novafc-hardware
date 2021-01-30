#include "FlightLoader.hpp"
#include "RocketData.hpp"
#include "SensorValues.hpp"
#include <string>
#include "Configuration.hpp"
#include "Brain.hpp"
#include "Logger.hpp"
#include "LowLevelSimulator.hpp"
#include <iostream>

int main() {
  LowLevelSimulator sim;
  Logger logger( (void*)(&sim),
		 &(LowLevelSimulator::flash_write_callback),
		 (void*)(&sim),
		 &(LowLevelSimulator::transmit_callback));
  std::string flightData = "resources/TestData.csv";
	std::string fileOut = "BrainTest.csv";
	Configuration config;
	config.setAltitudeDetermination(ACCELEROMETER_ONLY);
	SensorValues sensors(config);
	Cartesian gravityAcceleration = {0,9.81,0};
	RocketData rocket(config, sensors, gravityAcceleration);
	
	float gyroNoiseMean = 0.2;
	float gyroNoiseSTD = 0.1;
	float accelNoiseMean = 0;
	float accelNoiseSTD = 3;

	FlightSimulator simulator(config, rocket, sensors, logger, flightData, fileOut);
	simulator.insertNoise(gyroNoiseMean, gyroNoiseSTD, accelNoiseMean, accelNoiseSTD);
	bool success = simulator.runSimulation(100);
	if(!success) {
		std::cout <<"fail" << std::endl;
		int exitCode = 1;
		std::cout << "Exit Code: " << exitCode << std::endl;
		return exitCode;
	}
	std::cout << "Success" <<std::endl;
	return 0;
}
