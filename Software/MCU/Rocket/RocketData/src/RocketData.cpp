/*
 * ProjectCerberus: Nova/RocketData
 * Description: This class is to process incoming sensor values
 * Author: Matthew Gasper
 */
#include "RocketData.h"
#include "SensorValues.h"
#include <cmath>

RocketData::RocketData(Configuration& config, SensorValues& sensors, Cartesian startAverageAcceleration) : sensors(sensors), groundPressure(SEA_LEVEL_PRESSURE), config(config){
	rocketAngle = {1,0,0,0};
	//TODO determine initial data from accelerometer data
	rocketDisplacement = {0,0,0};
	rocketVelocity = {0,0,0};
}
void RocketData::update() {
	AltitudeDeterminination mode = config.getAltitudeDetermination();
	updateData();
	switch(mode) {
	case BOTH:
		updateBarometer();
	case ACCELEROMETER_ONLY:
		gyroUpdate();
		accelUpdate();
		break;
	case BAROMETER_ONLY:
		updateBarometer();
		break;
	}
	sensorFusion(mode);
}

Cartesian RocketData::gravityBias() {
	Cartesian gravityBias =rocketAngle.getOrientationVector();
	gravityBias = gravityBias * -9.81;
	return gravityBias;
}

void RocketData::accelUpdate(){
	Cartesian globalAcceleration = rocketAngle.getRotationMatrix() * acceleration;
	globalAcceleration = globalAcceleration + gravityBias();
	
	accelVelocity = rocketVelocity + (globalAcceleration * deltaT);
	accelDisplacement = rocketDisplacement + (accelVelocity * deltaT);
}

void RocketData::gyroUpdate() {
	Quanternion angularData;
	angularData.setCartesian(getAngularVelocity());
	Quanternion rocketAngleDot = rocketAngle * 0.5 * angularData * deltaT;
	rocketAngle = rocketAngle + rocketAngleDot;
	rocketAngle.normalize();
}

void RocketData::updateData() {
	acceleration = sensors.getAcceleration();
	angularVelocity[1] = angularVelocity[0];
	angularVelocity[0] = sensors.getAngularVelocity();
    currentPressure = sensors.getCPressure();
    groundPressure = sensors.getSPressure();
    temperature = sensors.getTemperature();
    deltaT = config.getUpperTimeStepms()/1000.0;
}

// Prettified equation(paste in latex parser)
// \Delta H = \frac {P_s^{\frac {1}{5.257}}(T*273.15)} {0.0065} (\frac {P_0^{\frac {1}{5.257}}-P_1^{\frac {1}{5.257}}} {P_0^{\frac {1}{5.257}}{P_1^{\frac {1}{5.257}}}})
void RocketData::updateBarometer() {
	float height;
	float magicNumber = 1/5.257;
	baroHeight = std::pow(SEA_LEVEL_PRESSURE, magicNumber) * (temperature + 273.15)/0.0065;
	baroHeight *= (std::pow(groundPressure, magicNumber) - std::pow(currentPressure, magicNumber))/(std::pow(groundPressure, magicNumber)*std::pow(currentPressure, magicNumber));
}
void RocketData::sensorFusion(AltitudeDeterminination mode) {
	Cartesian previousDisplacement = rocketDisplacement;
	switch(mode) {
	case ACCELEROMETER_ONLY:
		rocketDisplacement = accelDisplacement;
		rocketVelocity = accelVelocity;
		break;
	case BAROMETER_ONLY:
		rocketDisplacement.y = baroHeight;
		rocketVelocity.y = (rocketDisplacement.y - previousDisplacement.y);
		break;
	case BOTH:
		rocketDisplacement = accelDisplacement;
		rocketVelocity = accelVelocity;
		if(rocketVelocity.magnitude() <= MACH_LOCKOUT_BEGIN) {//baro lockout
			float fusedHeight = (accelDisplacement.y + baroHeight) / 2;
			float fusedVerticalVel = (fusedHeight - previousDisplacement.y) / deltaT;
			rocketDisplacement.y = fusedHeight;
			rocketVelocity.y = fusedVerticalVel;
		}
		break;	
	}
}

float RocketData::getAngleFromVertical() {
	Cartesian orientationAngle = rocketAngle.getOrientationVector();
	return acos(orientationAngle.y);
}

Cartesian RocketData::getDisplacement()     {return rocketDisplacement;}
Cartesian RocketData::getAcceleration()     {return  acceleration;}
Cartesian RocketData::getAngularVelocity()  {return (angularVelocity[0]+angularVelocity[1])*0.5;}
Quanternion RocketData::getAngle() {return rocketAngle;} 

float RocketData::getCPressure()    {return currentPressure;}
float RocketData::getSPressure()    {return groundPressure;}
float RocketData::getTemperature()  {return temperature;}
float RocketData::getAltitude() 	{return rocketDisplacement.y;}
Cartesian RocketData::getVelocity()    {return rocketVelocity;}
