/*
 * ProjectCerberus: Nova/RocketData
 * Description: This class is to process incoming sensor values
 * Author: Matthew Gasper
 */

#pragma once
#include "cartesian.h"
#include "SensorValues.h"
#include "Quanternion.hpp"
class RocketData{
    private:
        static RocketData rocketData;

        Cartesian acceleration[2], angularVelocity[2]; //Raw Sensor Data
        float cPressure, sPressure, temperature; //Raw Sensor Data
        float cVelocity;
        Cartesian rocketDisplacement, rocketVelocity; //Processed Data
		Quanternion rocketAngle;
        SensorValues& sensors;
        float deltaTms;

    protected:
        RocketData();
        ~RocketData(){}

    public:
        RocketData(RocketData &other) = delete;
        void operator =(const RocketData &) = delete;
        static RocketData &getInstance(){return rocketData;}

        void updateData();  //Updates data from Sensor Values
        void updateDisplacement(); //Processes pressure & temp into altitude
        void update();
        void updateAngle();
        float getAltitudeFromPressure();
        float complementaryFilter(float acc, float gyro, int axis);
        float gyro_int(int axis);
        float accel_angle(int axis);

        Cartesian getDisplacement();
        Cartesian getAcceleration();
        Cartesian getAngularVelocity();
        Quanternion getAngle(); 
        
        float getCPressure();
        float getSPressure();
        float getTemperature();
        float getCVelocity();
};
