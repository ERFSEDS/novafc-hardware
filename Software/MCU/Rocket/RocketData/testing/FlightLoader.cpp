#include "FlightLoader.hpp"
#include "RocketData.h"
#include "SensorValues.h"
#include "cartesian.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

FlightSimulator::FlightSimulator(RocketData &data, SensorValues &sensors, std::string inputFile, std::string outputFile) : rocket(data), sensors(sensors) {
	
	this->fileIn.open(inputFile);
	this->fileOut.open(outputFile);
}

bool FlightSimulator::runSimulation() {
	//yes I know its not super efficent, it is more clear as a result and that is the goal in the test.
	std::cout << "Starting Simulation" << std::endl;
	bool success = true;
	std::string line;
	this->fileIn>>line;
	
	std::vector<float> arguements;
	//this->split(line, arguements);
	//TODO check these to ensure consistency
	float timeStep, stepNum, accelX, accelY, accelZ, gyroX, gyroY, gyroZ, pressure, trueAltitude, trueAngle;
	
	float altitude, angle;
	bool first = true;
	while(!fileIn.eof()) {
		fileIn>>line;
		arguements.clear();
		this->split(line, arguements);
		timeStep = arguements.at(0);
		stepNum = arguements.at(1);
		accelX = arguements.at(2);
		accelY = arguements.at(3);
		accelZ = arguements.at(4);
		gyroX = arguements.at(5);
		gyroY = arguements.at(6);
		gyroZ = arguements.at(7);
		pressure = arguements.at(8);
		trueAltitude = arguements.at(9);
		trueAngle = arguements.at(10);
		
		Cartesian acceleration = {accelX, accelY, accelZ};
		Cartesian gyro = {gyroX, gyroY, gyroZ};
		
		this->sensors.setAcceleration(acceleration);
		this->sensors.setAngularVelocity(gyro);
		
		this->sensors.setCPressure(pressure);
		if(first) {
			this->sensors.setSPressure(pressure);
		}
		
		this->rocket.update();
		altitude = rocket.getDisplacement().y; //need to confirm axis is correct, also shoould change to x, y, z
		angle = 0;// LOL whats an angle, TODO
		
		float altitudeError = std::abs(altitude - trueAltitude)/trueAltitude; 
		float angleError = std::abs(angle - trueAngle)/trueAngle;
		
		if(altitudeError > ACCEPTABLE_ALTITUDE_ERROR) {
			std::cout << "Altitude outside acceptable bounds" <<std::endl;
			std::cout << "True Altitude: " << trueAltitude << std::endl;
			std::cout << "Measured Altitude: " << altitude << std::endl;
			std::cout << std::endl;
			success = false;
		}
		if(angleError > ACCEPTABLE_ANGLE_ERROR) {
			std::cout << "Angle outside acceptable bounds" <<std::endl;
			std::cout << "True Angle: " << trueAngle << std::endl;
			std::cout << "Measured Angle: " << angle << std::endl;
			std::cout << std::endl;
			success = false;
		}
	}
	return success;
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
