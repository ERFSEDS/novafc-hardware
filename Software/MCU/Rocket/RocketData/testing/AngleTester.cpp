#include "RocketData.h"
#include "Configuration.hpp"
#include "SensorValues.h"
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#define ACCEPTABLE_ERROR_MARGIN 1//%
float checkErrorRate(Quanternion calcAngle, Quanternion expectedAngle);
int main() {
	Configuration::setUpperTimeStepms(1);
	SensorValues& sensors = SensorValues::getInstance();
	RocketData& rocket = RocketData::getInstance();	
	sensors.setAngularVelocity({0,0,M_PI/2});
	for(int i = 0; i < 1000; i++) {
		rocket.update();
	}	
	Quanternion calcAngle = rocket.getAngle();
	Quanternion expectedAngle = {sqrt(0.5),0,0,sqrt(0.5)};
	
	float errorRate = checkErrorRate(calcAngle, expectedAngle);
	
	if(errorRate >= ACCEPTABLE_ERROR_MARGIN) {
		std::cout << "Rotation Failed" <<std::endl;
	}
}

float checkErrorRate(Quanternion calcAngle, Quanternion expectedAngle) {
	float errorA = abs( (calcAngle.a - expectedAngle.a) / expectedAngle.a) * 100;
	float errorI = abs( (calcAngle.i - expectedAngle.i) / expectedAngle.i) * 100;
	float errorJ = abs( (calcAngle.j - expectedAngle.j) / expectedAngle.j) * 100;
	float errorK = abs( (calcAngle.k - expectedAngle.k) / expectedAngle.k) * 100;
	return errorA + errorI + errorJ + errorK;
}
