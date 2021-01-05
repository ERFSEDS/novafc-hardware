#include "FlightLoader.hpp"
#include "RocketData.h"
#include "SensorValues.h"
#include <string>
#include "Configuration.hpp"

int main() {
	std::string flightData = "resources/TestData.csv";
	std::string fileOut = "noNoise.csv";
	Configuration::setUpperTimeStepms(10);
	Configuration::setAltitudeDetermination(ACCELEROMETER_ONLY);

	
	RocketData& rocket = RocketData::getInstance();
	SensorValues& sensors = SensorValues::getInstance();
	
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
