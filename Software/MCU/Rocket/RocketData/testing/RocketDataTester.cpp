#include "FlightLoader.hpp"
#include "RocketData.h"
#include "SensorValues.h"
#include <string>
#include "Configuration.hpp"

int main() {
	std::string flightData = "resources/TestData.csv";
	std::string fileOut = "results.csv";
	Configuration config;
	config.setUpperTimeStepms(10);
	config.setAltitudeDetermination(ACCELEROMETER_ONLY);
	float gyroNoiseMean = 0.2;
	float gyroNoiseSTD = 0.1;
	float accelNoiseMean = 0;
	float accelNoiseSTD = 3;

	SensorValues sensors;
	RocketData rocket(config, sensors);
		
	FlightSimulator simulator(rocket, sensors, flightData, fileOut);
	simulator.insertNoise(gyroNoiseMean, gyroNoiseSTD, accelNoiseMean, accelNoiseSTD);
	bool success = simulator.runSimulation(100);
	if(!success) {
		return 1;
	}
	return 0;
	
}
