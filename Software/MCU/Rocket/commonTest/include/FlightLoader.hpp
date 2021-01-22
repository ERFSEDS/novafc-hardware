
#pragma once
#include "RocketData.h"
#include "SensorValues.h"
#include "Brain.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <random> 
#include "CommonDefines.hpp"
#define ACCEPTABLE_ALTITUDE_ERROR 		0.05
#define ACCEPTABLE_ALTITUDE_ERROR_ABS 	10
#define ACCEPTABLE_ANGLE_ERROR 			0.05
#define ACCEPTABLE_ANGLE_ERROR_ABS 		0.17 // about 10 degrees
#define ACCEPTABLE_TIME_PYRO_ERROR 		10 //seconds
class FlightSimulator {
	public:	
  FlightSimulator(Configuration& config, RocketData& rocket, SensorValues &sensors,Logger& logger, std::string inputFile, std::string outputFile);
		

		void insertNoise(float gyroMean, float gyroSTD, float accelMean, float accelSTD);
		bool runSimulation(int subSampleRate); //returns whether or not it passed
		
		static void armCallback(void * context, bool arm);
		static void fireCallback(void * context, int channel);
		
		void arm(bool arm);
		void fire(int channel);
	private:
		void split(std::string const &str, std::vector<float> &out);
		void insertNoise(float * value, float mean, float stdDev);

		std::ifstream fileIn;
		std::ofstream fileOut;
		Brain brain;
		StateMachine state;
		RocketData& rocket;
		SensorValues& sensors;
		Configuration& config;
		float gyroNoiseMean;
		float gyroNoiseSTD;
		float accelNoiseMean;
		float accelNoiseSTD;
		
		bool pyros[NUMBER_OF_PYROS];
		bool armed;
};
