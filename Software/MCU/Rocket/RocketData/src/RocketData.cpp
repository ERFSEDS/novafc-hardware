/*
 * ProjectCerberus: Nova/RocketData
 * Description: This class is to process incoming sensor values
 * Author: Matthew Gasper
 */
#include "RocketData.h"
#include "Configuration.hpp"
#include "SensorValues.h"
#include <cmath>
RocketData RocketData::rocketData;

RocketData::RocketData() : sensors(SensorValues::getInstance()){
	rocketDisplacement = {0,0,0};
	rocketAngle = {0,0,0};
}
void RocketData::update() {
	updateData();
	updateDisplacement();
}

void RocketData::updateDisplacement(){
	deltaAngle = angularVelocity[0] * deltaTmS;
	globalAngle = globalAngle + 
}

void RocketData::updateData(){
	acceleration[1] = acceleration[0];
	angularVelocity[1] = angularVelocity[0];
	acceleration[0] = sensors.getAcceleration();
	angularVelocity[0] = sensors.getAngularVelocity();
    cPressure = sensors.getCPressure();
    sPressure = sensors.getSPressure();
    temperature = sensors.getTemperature();
    deltaTms = Configuration::getUpperTimeStepms();
}

float RocketData::gyro_int(int axis){
    float t1,t2;
    float sensitivity = 14.375; //magic number untill data sheet is checked for gyro
    float dt = 0.0;
    float gyroAngle = 0.0;

    t1 = Configuration::getUpperTimeStepms()*1000;  //The 1000 is to convert ms to us
    gyroAngle = gyroAngle + (angularVelocity[0].dimension[axis] - angularVelocity[1].dimension[axis]) * (dt/1000000)/sensitivity; //Assuming angularVelocity is in degrees a seocnd
    t2 = Configuration::getUpperTimeStepms()*1000;  //The 1000 is to convert ms to us
    dt = t2-t1;

    return gyroAngle;
}

float RocketData::accel_angle(int axis){
    float accelAngle = 0.0;
    accelAngle = accelAngle*180/3.14159;//assuming acc is in g's
    return accelAngle;
}

//In its current state this will only be able to calculate x and y angles
float RocketData::complementaryFilter(float acc, float gyro, int axis){
    float compFilterAngle = 0.0;
    float a = 0.0; //Smoothing Factor

    filteredAccAngle[0].dimension[axis]  = a*accel_angle(axis)+(1-a)*filteredAccAngle[1].dimension[axis];            //Low-Pass Filter  (For accelerometer)
    filteredGyroAngle[0].dimension[axis] = 1-(a*gyro_int(axis)+(1-a)*filteredGyroAngle[1].dimension[axis]);      //High-Pass Filter (For gyroscope)

    compFilterAngle = filteredAccAngle[0].dimension[axis] + filteredGyroAngle[0].dimension[axis];           //Combining both filtered signals to get full signal

    return compFilterAngle;
}
// angle.x = α*gyro_angle_y+(1-­α)acc_angle_x; << Roll
// angle.y = α*gyro_angle_x+(1-­α)acc_angle_y; << Pitch

cartesian RocketData::getDisplacement()     {return displacement;}
cartesian RocketData::getAcceleration()     {return acceleration[0];}
cartesian RocketData::getAngularVelocity()  {return angularVelocity[0];}

float RocketData::getCPressure()    {return cPressure;}
float RocketData::getSPressure()    {return sPressure;}
float RocketData::getTemperature()  {return temperature;}
float RocketData::getCVelocity()    {return cVelocity;}
