/*
 * ProjectCerberus: Nova/RocketData
 * Description: This class is to process incoming sensor values
 * Author: Matthew Gasper
 */

#pragma once
#include "cartesian.h"
#include "SensorValues.h"

class RocketData{
    private:
        static RocketData rocketData;

        cartesian acceleration[2], angularVelocity[2]; //Raw Sensor Data
        float cPressure, sPressure, temperature; //Raw Sensor Data
        float cVelocity;
        cartesian globalPosition, globalAngle, globalVelocity; //Processed Data
        SensorValues& sensors;

    protected:
        RocketData();
        ~RocketData(){}

    public:
        RocketData(RocketData &other) = delete;
        void operator =(const RocketData &) = delete;
        static RocketData &getInstance(){return rocketData;}

        void updateData();  //Updates data from Sensor Values
        void updateDisplacement(); //Processes pressure & temp into altitude
        void update()
        
        float getAltitudeFromPressure();
        float getAltitudeFromPressure();
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
