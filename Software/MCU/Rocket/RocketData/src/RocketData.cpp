/*
 * ProjectCerberus: Nova/RocketData
 * Description: This class is to process incoming sensor values
 * Author: Matthew Gasper
 */
#include "RocketData.h"
#include "SensorValues.h"
#include <cmath>
RocketData RocketData::rocketData;

RocketData::RocketData() : sensors(SensorValues::getInstance()){
	rocketAngle = {1,0,0,0};
	rocketDisplacement = {0,0,0};
	rocketVelocity = {0,0,0};
}
void RocketData::update() {
	AltitudeDeterminination mode = Configuration::getAltitudeDetermination();
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

void RocketData::accelUpdate(){
	Cartesian globalAcceleration = rocketAngle.getRotationMatrix() * acceleration[0];
	accelVelocity = rocketVelocity + acceleration[0] * deltaT;
	accelDisplacement = rocketDisplacement + rocketVelocity *deltaT;
}
void RocketData::gyroUpdate() {
	Quanternion angularData;
	angularData.setCartesian(angularVelocity[0]);
	Quanternion rocketAngleDot = rocketAngle * 0.5 * angularData * deltaT;
	rocketAngle = rocketAngle + rocketAngleDot;
	rocketAngle.normalize();
}

void RocketData::updateData(){
	acceleration[1] = acceleration[0];
	angularVelocity[1] = angularVelocity[0];
	acceleration[0] = sensors.getAcceleration();
	angularVelocity[0] = sensors.getAngularVelocity();
    currentPressure = sensors.getCPressure();
    groundPressure = sensors.getSPressure();
    temperature = sensors.getTemperature();
    deltaT = Configuration::getUpperTimeStepms()/1000.0;
    
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
	float orientationAngle[3];
	rocketAngle.getOrientationVector(orientationAngle);
	return acos(orientationAngle[2]);
}

Cartesian RocketData::getDisplacement()     {return rocketDisplacement;}
Cartesian RocketData::getAcceleration()     {return acceleration[0];}
Cartesian RocketData::getAngularVelocity()  {return angularVelocity[0];}
Quanternion RocketData::getAngle() {return rocketAngle;} 

float RocketData::getCPressure()    {return currentPressure;}
float RocketData::getSPressure()    {return groundPressure;}
float RocketData::getTemperature()  {return temperature;}
Cartesian RocketData::getVelocity()    {return rocketVelocity;}
