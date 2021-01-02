/*
 * ProjectCerberus: Nova SensorValues
 * Description: This class is to act like a Storage class for sensor values
 * Author: Matthew Gasper
 */
#pragma once
#include "cartesian.h"

class SensorValues {
    private:
        static SensorValues instance;

        Cartesian  acceleration[2], angularVelocity[2];
        float sPressure, cPressure[2], temperature;
        bool pyro[2];
        float deltaT;

    protected:
        SensorValues();
        ~SensorValues(){}

    public:
        SensorValues(SensorValues &other) = delete;
        void operator =(const SensorValues &) = delete;
        static SensorValues& getInstance(){return instance;}

        void setAcceleration(Cartesian data);
        void setAngularVelocity(Cartesian data);
        void setSPressure(float pressure);
        void setCPressure(float pressure);
        void setTemperature(float temperature);

        Cartesian   getAcceleration();
        Cartesian   getAngularVelocity();
        float       getSPressure();
        float       getCPressure();
        float       getTemperature();
        
        bool checkPyro(int cmd);
        void firePyro(int cmd);
        void setPyro(int cmd, bool state);
};
