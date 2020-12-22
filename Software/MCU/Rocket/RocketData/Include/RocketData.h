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


		//Raw sensor Data
        Cartesian acceleration[2], angularVelocity[2];
        float cPressure, sPressure, temperature; 
        float cVelocity;
        
        
        //Processed Data, in earth coordinate frame nor rocketFrame
        Cartesian rocketDisplacement, rocketVelocity; 
		Quanternion rocketAngle;
        SensorValues& sensors;
        float deltaT;

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
        float getAngleFromVertical(); 
        
        float getCPressure();
        float getSPressure();
        float getTemperature();
        float getCVelocity();
};
