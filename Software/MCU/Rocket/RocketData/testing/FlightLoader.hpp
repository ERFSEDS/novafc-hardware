
#pragma once
#include "RocketData.h"
#include "SensorValues.h"
#include <fstream>
#include <vector>
#include <string>
#include <random> 

#define ACCEPTABLE_ALTITUDE_ERROR 0.05
#define ACCEPTABLE_ALTITUDE_ERROR_ABS 10
#define ACCEPTABLE_ANGLE_ERROR 0.05
#define ACCEPTABLE_ANGLE_ERROR_ABS 0.17 // about 10 degrees
class FlightSimulator {
	public:	
		FlightSimulator(RocketData& rocket, SensorValues &sensors, std::string inputFile, std::string outputFile);
		

		void insertNoise(float gyroMean, float gyroSTD, float accelMean, float accelSTD);
		bool runSimulation(int subSampleRate); //returns whether or not it passed
	private:
		void split(std::string const &str, std::vector<float> &out);
		void insertNoise(float * value, float mean, float stdDev);

		std::ifstream fileIn;
		std::ofstream fileOut;
		RocketData& rocket;
		SensorValues& sensors;
		float gyroNoiseMean;
		float gyroNoiseSTD;
		float accelNoiseMean;
		float accelNoiseSTD;

};
