
#pragma once
#include "RocketData.h"
#include "SensorValues.h"
#include <fstream>
#include <vector>
#include <string>
#include <random> 

#define ACCEPTABLE_ALTITUDE_ERROR 0.05
#define ACCEPTABLE_ALTITUDE_ERROR_ABS 2
#define ACCEPTABLE_ANGLE_ERROR 0.05
#define ACCEPTABLE_ANGLE_ERROR_ABS 2
class FlightSimulator {
	public:	
		FlightSimulator(RocketData& rocket, SensorValues &sensors, std::string inputFile, std::string outputFile);
		
	
		bool runSimulation(); //returns whether or not it passed
		void split(std::string const &str, std::vector<float> &out);
		void insertNoise(float * value, float mean, float stdDev);
	private:
		std::ifstream fileIn;
		std::ofstream fileOut;
		RocketData& rocket;
		SensorValues& sensors;

};
