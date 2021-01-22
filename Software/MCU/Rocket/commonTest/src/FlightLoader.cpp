#include "FlightLoader.hpp"
#include "RocketData.h"
#include "SensorValues.h"
#include "cartesian.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include "Configuration.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>

namespace fs = std::filesystem;

//BURN THIS IN HELL, its so bad I just need to start over and just grab parts of this and ditch the rest
FlightSimulator::FlightSimulator(Configuration& config, RocketData &data, SensorValues &sensors, Logger& logger, std::string inputFile, std::string outputFile) : 
		config(config),
		rocket(data), 
		sensors(sensors),
		gyroNoiseMean(0), 
		gyroNoiseSTD(0), 
		accelNoiseMean(0), 
		accelNoiseSTD(0),
		state{config, logger},
		brain{config, this->state, data, sensors, logger, &armCallback, this, &fireCallback, this},
		armed(false)
 {
	
	this->fileIn.open(inputFile);
	this->fileOut.open(outputFile);
	this->fileOut << "timeStep, altitude, trueAltitude, altitudeError, angle, angleError, event(s)" << std::endl;
	
	for(int i = 0; i < NUMBER_OF_PYROS; i++) {
		pyros[i] = false;
	}
	this->arm(armCallback);
}

void FlightSimulator::insertNoise(float gyroMean, float gyroSTD, float accelMean, float accelSTD) {
	gyroNoiseMean = gyroMean * M_PI / 180.0;
	gyroNoiseSTD = gyroSTD * M_PI / 180.0;
	accelNoiseMean = accelMean;
	accelNoiseSTD = accelSTD;
}
void FlightSimulator::armCallback(void * context, bool armS) {
	std::cout << "got into the initial callback" <<std::endl;
	reinterpret_cast<FlightSimulator*>(context)->arm(armS);
}
void FlightSimulator::fireCallback(void * context, int channel) {
	reinterpret_cast<FlightSimulator*>(context)->fire(channel);

}
void FlightSimulator::arm(bool arm) {
	if(arm) {
		std::cout << "ARMED" << std::endl;
	}
	else {
		std::cout << "DISARMED" << std::endl;
	}
	armed = arm;
}
void FlightSimulator::fire(int channel) {
	std::cout << "Pyro " << channel << " fired" << std::endl;
	pyros[channel] = true;
}
//sets pyro 0 to fire at apogee, pyro 1 to fire at 200m and past apogee
//this was copied for now set subSampleRate so that the frequency is 100Hz
bool FlightSimulator::runSimulation(int subSampleRate) {
	try {
		//If I dont fix this terrible code when youre seeing this send me a message - Nathan R
		std::cout << "Setting up simulation" << std::endl;
		config.setPyro(0, false, PAST_APOGEE, 0, NONE, 0);
		config.setPyro(1, false, PAST_APOGEE, 0, ALTITUDE_BELOW, 200);
		config.setPyro(2, true, NO_FIRE, 0, NONE, 0);
		config.setUpperTimeStepms(10);
		config.setTwoStageRocket(false);
		brain.updateConfigValues();
		state.refresh();
		std::cout << "About to arm" <<std::endl;
		brain.arm();
		
		std::cout << "Starting Simulation" << std::endl;
		bool success = true;
		std::string line;
		fileIn>>line;
		
		std::vector<float> arguements;
		//this->split(line, arguements);
		//TODO check these to ensure consistency
		float timeStep, stepNum, accelX, accelY, accelZ, gyroX, gyroY, gyroZ, pressure, trueAltitude, trueAngle;
		
		float altitude, angle;
		bool first = true;
		int i = 0;
		float lastAltitude = -1;
		float trueTimeApogee = -1;
		float timeApogee = -1;
		
		
		float truePyroTime[NUMBER_OF_PYROS];
		float pyroTime[NUMBER_OF_PYROS];
		for(int i = 0; i < NUMBER_OF_PYROS; i++) {
			pyroTime[i] = -1;
		}
		for(int i = 0; i < NUMBER_OF_PYROS; i++) {
			truePyroTime[i] = -1;
		}
		
		while(!fileIn.eof()) {
			fileIn>>line;
			arguements.clear();
			this->split(line, arguements);
			timeStep = arguements.at(0);
			stepNum = arguements.at(1);
			accelX = arguements.at(2);
			accelY = arguements.at(3) + 9.81;
			accelZ = arguements.at(4);
			gyroX = arguements.at(5);
			gyroY = arguements.at(6);
			gyroZ = arguements.at(7);
			pressure = arguements.at(8);
			trueAltitude = arguements.at(9);
			trueAngle = arguements.at(10);
			
			insertNoise(&accelX, accelNoiseMean, accelNoiseSTD);
			insertNoise(&accelY, accelNoiseMean, accelNoiseSTD);
			insertNoise(&accelZ, accelNoiseMean, accelNoiseSTD);
			

			insertNoise(&gyroX, gyroNoiseMean, gyroNoiseSTD);
			insertNoise(&gyroY, gyroNoiseMean, gyroNoiseSTD);
			insertNoise(&gyroZ, gyroNoiseMean, gyroNoiseSTD);
			Cartesian acceleration = {accelX, accelY, accelZ};
			Cartesian gyro = {gyroX, gyroY, gyroZ};
			
			if (i >= subSampleRate) {
				if((int)(timeStep*10) == 10*timeStep) {
					std::cout << "time step: " << timeStep <<std::endl;
				}
				this->sensors.setAcceleration(acceleration);
				this->sensors.setAngularVelocity(gyro);
				
				this->sensors.setCPressure(pressure);
				Cartesian val = sensors.getAcceleration();
				if(first) {
					this->sensors.setSPressure(pressure);
					first = false;
				}
				
				this->rocket.update();
				altitude = rocket.getAltitude(); 
				angle = rocket.getAngleFromVertical();
				
				Cartesian vec = rocket.getAcceleration();
				//This is stuff so you can see where the rocket state module is at when its passing data, does not fail the test(unless there is a math error resulting in no altitude
				float altitudeError = std::abs(altitude - trueAltitude)/trueAltitude; 
				float angleError = std::abs(angle - trueAngle)/trueAngle;
				float altitudeDifference = std::abs(altitude - trueAltitude);
				float angleDifference = std::abs(angle - trueAngle);
				if(altitude != altitude) { //checks for NAN
					std::cout << "ALtitude is NAN" << std::endl;
					success = false;
				}
				
				if( (altitudeError > ACCEPTABLE_ALTITUDE_ERROR) && (altitudeDifference > ACCEPTABLE_ALTITUDE_ERROR_ABS) ) {
					std::cout << "Time is: " << timeStep << std::endl;
					std::cout << "Altitude outside acceptable bounds" <<std::endl;
					std::cout << "True Altitude: " << trueAltitude << std::endl;
					std::cout << "Measured Altitude: " << altitude << std::endl;
					std::cout << std::endl;
				}
				if( (angleError > ACCEPTABLE_ANGLE_ERROR) && (angleDifference > ACCEPTABLE_ANGLE_ERROR_ABS)) {
					std::cout << "Time is: " << timeStep << std::endl;
					std::cout << "Angle outside acceptable bounds" <<std::endl;
					std::cout << "True Angle: " << trueAngle << std::endl;
					std::cout << "Measured Angle: " << (angle * (180/M_PI)) << " degrees" << std::endl;
					std::cout << std::endl;
				}
				i=1;
				
				
				//BRAIN STUFF
				
				this->brain.check();
				//check each pyro
				std::stringstream events("");
				for(int i = 0; i < NUMBER_OF_PYROS; i++) {
					if(pyros[i] && (pyroTime[i] == -1)) {
						pyroTime[i] = timeStep;
						events <<"Pyro " << i << " fired--"; 
						std::cout << "Pyro " << i << " fired at " << timeStep << std::endl;
					}
				} 
				
				//determine the true times it should run
				//sets pyro 0 to fire at apogee,
				if( (lastAltitude > trueAltitude) && (truePyroTime[0] == -1) ) {
					truePyroTime[0] = timeStep;
					events << "Pyro 0 should have fired--";
					std::cout << "Pyro 0 should fire at " << timeStep << std::endl;
				} 
				//pyro 1 to fire at 200m and past apogee, 
				if( (trueAltitude < 200) && (lastAltitude > trueAltitude) && (truePyroTime[1] == -1) ) {
					truePyroTime[1] = timeStep;
					events << "Pyro 1 should have fired--";
					std::cout << "Pyro 1 should fire at " << timeStep << std::endl;
				} 
				
				this->fileOut << timeStep << ", " << altitude << ", " << trueAltitude << ", " <<  altitudeError << ", " << angle << ", " << angleError << events.str() << std::endl;
			}
			else {
				i++;
			}
			lastAltitude=trueAltitude;
		}
		this->fileOut.close();
		
		for(int i = 0; i < NUMBER_OF_PYROS; i++) {
			if(std::abs(truePyroTime[i] - pyroTime[i]) > ACCEPTABLE_TIME_PYRO_ERROR) {
				success =false;
			}
			std::cout << "Pyro " << i << " outside of acceptable range:" << std::endl;
			std::cout << "Desired: " << truePyroTime[i] << std::endl;
			std::cout << "Actual: " << pyroTime[i] << std::endl;
		}
		return success;
	}
	catch(std::out_of_range) {
		std::cout << "out of range error" << std::endl;
		return false;
	}
}
void FlightSimulator::split(std::string const &str, std::vector<float> &out)
{
	size_t start;
	size_t end = 0;
	std::string valueString = "";
	float value;
	while ((start = str.find_first_not_of(',', end)) != std::string::npos)
	{
		end = str.find(',', start);
		valueString = str.substr(start, end - start);
		try { 
			value = std::stof(valueString);
		}
		catch(const std::out_of_range e) {
			value = 0.0;
		}
		out.push_back(value);
	}
}

void FlightSimulator::insertNoise(float * value, float mean, float stdDev) {
    std::random_device rd;
	std::default_random_engine numberGenerator (rd());
    std::normal_distribution<float> distN(mean, stdDev); 
    *value += distN(numberGenerator);
}
