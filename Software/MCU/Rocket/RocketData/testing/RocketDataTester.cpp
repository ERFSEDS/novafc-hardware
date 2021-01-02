#include "FlightLoader.hpp"
#include "RocketData.h"
#include "SensorValues.h"
#include <string>
#include "Configuration.hpp"

int main() {
	std::string flightData = "resources/TestData.csv";
	std::string fileOut = "results.csv";
	Configuration::setUpperTimeStepms(10);
	float gyroNoiseMean = 1;
	float gyroNoiseSTD = 2;
	float accelNoiseMean = 0;
	float accelNoiseSTD = 3;


	
	RocketData& rocket = RocketData::getInstance();
	SensorValues& sensors = SensorValues::getInstance();
	
	FlightSimulator simulator(rocket, sensors, flightData, fileOut);
	simulator.insertNoise(gyroNoiseMean, gyroNoiseSTD, accelNoiseMean, accelNoiseSTD);
	bool success = simulator.runSimulation(100);
	if(!success) {
		return 1;
	}
	return 0;
	
}
