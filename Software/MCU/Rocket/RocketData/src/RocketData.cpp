/*
 * ProjectCerberus: Nova/RocketData
 * Description: This class is to process incoming sensor values
 * Author: Matthew Gasper
 */
#pragma once
#include "RocketData.h"
SensorValues *SensorValues::instance = 0;
SensorValues *sv = sv-> getInstance();

void RocketData::updateDisplacement(){
    //displacement.x = ;
    displacement.y = ((pow(sPressure/cPressure,1/5.257)-1)*(temperature+273.15))/0.0065;    //Hypsometric Formula
    //displacement.y = u + at;
    //displacement.z = ;
}

void RocketData::updateData(){
    acceleration = sv->getAcceleration();
    angularVelocity = sv->getAngularVelocity();
    cPressure = sv-> getCPressure();
    sPressure = sv-> getSPressure();
    temperature = sv-> getTemperature();
}

/*
##########[find integrate gyrpscope angle]##########  
float intGyroAngle(){
    float t1,t2;
    t1 = timeThingy;
    float sensitivity = ?;
    gyroAngle = gyroAngle? + (angularVelocity?-initial?)*(dt/1000000)/sensitivity;
    t2 = timeThingy;
    dt = t2-t1;
    return gyroAngle;
}
*/

//In its current state this will only be able to calculate x and y angles
float RocketData::complementaryFilter(float acc, float gyro){
    float compFilterAngle = 0.0;
    float filteredGyroAngle = 0.0;
    float filteredAccAngle = 0.0;
    float accAngle = 0.0;
    float gyroAngle = 0.0;
    float a = 0.0; //Smoothing Factor

    //gyroAngle = gyroAngle+angularVelocity*dt; dt is time constant
    //accAngle = acc*180/3.14159;

    //filteredAccAngle = a*accAngle+(1-a)*filteredAccAngle[n-1];           //<< Low-Pass Filter  (For accelerometer)
    //filteredGyroAngle = 1-(a*gyroAngle+(1-a)*filteredGyroAngle[n­-1]);    //<< High-Pass Filter (For gyroscope)

    compFilterAngle = filteredAccAngle + filteredGyroAngle; //Combining both filtered signals to get full signal
    return compFilterAngle;
}

cartesian RocketData::getDisplacement(){return displacement;};

// angle.x = α*gyro_angle_y+(1-­α)acc_angle_x; << Roll
// angle.y = α*gyro_angle_x+(1-­α)acc_angle_y; << Pitch