#include "FlightLoader.hpp"
#include "RocketData.h"
#include "SensorValues.h"
#include <string>

int main() {
	std::string flightData = "resources/TestData.csv";
	std::string fileOut = "results.txt";
	
	RocketData& rocket = RocketData::getInstance();
	SensorValues& sensors = SensorValues::getInstance();
	FlightSimulator simulator(rocket, sensors, flightData, fileOut);
	bool success = simulator.runSimulation();
	if(!success) {
		return 1;
	}
	return 0;
	
}
