#include "FlightLoader.hpp"
#include "RocketData.h"
#include "SensorValues.h"
#include <string>
#include "Configuration.hpp"

int main() {
	std::string flightData = "resources/TestData.csv";
	std::string fileOut = "noNoise.csv";
	Configuration config;
	config.setUpperTimeStepms(10);
	config.setAltitudeDetermination(ACCELEROMETER_ONLY);
	
	SensorValues sensors;
	RocketData rocket(config, sensors);
	
	FlightSimulator simulator(rocket, sensors, flightData, fileOut);
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
