/*
 * ProjectCerberus: Nova/RocketData
 * Description: This class is to process incoming sensor values
 * Author: Matthew Gasper
 */
#pragma once
#include "cartesian.h"

class RocketData{
    private:
        static RocketData * rocketD;

        cartesian acceleration[2], angularVelocity[2]; //Raw Sensor Data
        cartesian filteredGyroAngle[2], filteredAccAngle[2];
        float cPressure, sPressure, temperature; //Raw Sensor Data
        float cVelocity;
        cartesian displacement; //Processed Data

    protected:
        RocketData(){}
        ~RocketData(){}

    public:
        RocketData(RocketData &other) = delete;
        void operator =(const RocketData &) = delete;
        static RocketData *getInstance(){return rocketD;}

        void updateData();  //Updates data from Sensor Values
        void updateDisplacement(); //Processes pressure & temp into altitude
        float complementaryFilter(float acc, float gyro, int axis);
        float gyro_int(int axis);
        float accel_angle(int axis);

        cartesian getDisplacement();
        cartesian getAcceleration();
        cartesian getAngularVelocity();
        
        float getCPressure();
        float getSPressure();
        float getTemperature();
        float getCVelocity();
};