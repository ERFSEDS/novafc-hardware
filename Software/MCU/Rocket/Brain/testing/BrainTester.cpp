#include "FlightLoader.hpp"
#include "RocketData.h"
#include "SensorValues.h"
#include <string>
#include "Configuration.hpp"
#include "Brain.hpp"
#include "Logger.hpp"

void flash_write_callback(const char * msg, const size_t size) {
	std::string message(msg, size);
	std::cout << "[Store]: " << message << std::endl;	
}
void transmit_callback(const char * msg, const size_t size) {
	std::string message(msg, size);
	std::cout << "[Transmit]: "  << message << std::endl;
}
int main() {
	
	Logger::setTransmitCallback(&transmit_callback);
	Logger::setFlashWriteCallback(&flash_write_callback);
	std::string flightData = "resources/TestData.csv";
	std::string fileOut = "BrainTest.csv";
	Configuration config;
	config.setAltitudeDetermination(ACCELEROMETER_ONLY);
	SensorValues sensors;
	Cartesian gravityAcceleration = {0,9.81,0};
	RocketData rocket(config, sensors, gravityAcceleration);
	
	float gyroNoiseMean = 0.2;
	float gyroNoiseSTD = 0.1;
	float accelNoiseMean = 0;
	float accelNoiseSTD = 3;

	FlightSimulator simulator(config, rocket, sensors, flightData, fileOut);
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
