/*
 * ProjectCerberus: Nova/RocketData
 * Description: This class is to process incoming sensor values
 * Author: Matthew Gasper
 */

#pragma once
#include "cartesian.h"
#include "SensorValues.h"
#include "Quanternion.hpp"
#include "Configuration.hpp"
#define SEA_LEVEL_PRESSURE 101325
#define MACH_LOCKOUT_BEGIN 231.91 //MACH 0.7
class RocketData{
    private:
        static RocketData rocketData;


		//Raw sensor Data
        SensorValues& sensors;
		Configuration& config;
        Cartesian acceleration, angularVelocity[2];
        float currentPressure, groundPressure, temperature; // in Pa
        float deltaT;
        
         
        //Processed Data, in earth coordinate frame nor rocketFrame
     	Cartesian accelDisplacement, accelVelocity;
     	float baroHeight;
     	
     	//fused sensor data
     	Cartesian rocketDisplacement, rocketVelocity;
		Quanternion rocketAngle;

    protected:
        void accelUpdate();
        void gyroUpdate();
        void updateBarometer();
        void updateData();  //Updates data from Sensor Values
        Cartesian gravityBias();
        
        void calcAltitudeFromBarometer();
		void sensorFusion(AltitudeDeterminination mode);

    public:
        RocketData(Configuration& config, SensorValues& sensors, Cartesian startAverageAcceleration);
        ~RocketData(){}

        void update();
		

        Cartesian getDisplacement();
        Cartesian getVelocity();
        Cartesian getAcceleration();
        Cartesian getAngularVelocity();
        Quanternion getAngle();
        float getAngleFromVertical(); //radians
        
        float getCPressure();
        float getSPressure();
        float getTemperature();
};
