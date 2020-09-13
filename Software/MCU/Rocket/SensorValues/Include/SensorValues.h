/*
 * ProjectCerberus: Nova SensorValues
 * Description: This class is to act like a Storage class for sensor values
 * Author: Matthew Gasper
 */
#pragma once
#include "cartesian.h"

class SensorValues{
    private:
        static SensorValues * instance;

        cartesian  acceleration, angularVelocity;
        float sPressure, cPressure, temperature;
        bool pyro[2];

    protected:
        SensorValues(){}
        ~SensorValues(){}

    public:
        SensorValues(SensorValues &other) = delete;
        void operator =(const SensorValues &) = delete;
        static SensorValues *getInstance(){return instance;}

        void setAcceleration(cartesian data);
        void setAngularVelocity(cartesian data);
        void setSPressure(float pressure);
        void setCPressure(float pressure);
        void setTemperature(float temperature);

        cartesian   getAcceleration();
        cartesian   getAngularVelocity();
        float       getSPressure();
        float       getCPressure();
        float       getTemperature();
        
        bool checkPyro(int cmd);
        void firePyro(int cmd);
        void setPyro(int cmd, bool state);
};