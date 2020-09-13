/*
 * ProjectCerberus: Nova/RocketData
 * Description: This class is to process incoming sensor values
 * Author: Matthew Gasper
 */
#pragma once
#include "cartesian.h"
#include "SensorValues.h"
#include <cmath>

class RocketData{
    private:
        cartesian acceleration, angularVelocity; //Raw Sensor Data
        float cPressure, sPressure, temperature; //Raw Sensor Data
        float cVelocity;
        cartesian displacement; //Processed Data

    public:
        void updateData();  //Updates data from Sensor Values
        void updateDisplacement(); //Processes pressure & temp into altitude
        float complementaryFilter(float acc, float gyro);

        cartesian getDisplacement();
};