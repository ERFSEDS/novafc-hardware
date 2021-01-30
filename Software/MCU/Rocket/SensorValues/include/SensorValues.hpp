/*
 * ProjectCerberus: Nova SensorValues
 * Description: This class is to act like a Storage class for sensor values
 * Author: Matthew Gasper
 */
#pragma once
#include "Cartesian.hpp"
#include "Configuration.hpp"

class SensorValues {
    private:

        Cartesian  acceleration[2], angularVelocity[2];
        float sPressure, cPressure[2], temperature;
        bool pyro[2];
        float deltaT;
  Configuration &config;
    public:
  SensorValues(Configuration &config);
        ~SensorValues(){}

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

  void setTest(bool test); //DO NOT USE THIS IF YOU ARE NOT RUNNING A TEST WITH SIMULATED VALUES
        void setAcceleration_test(Cartesian data);
        void setAngularVelocity_test(Cartesian data);
        void setSPressure_test(float pressure);
        void setCPressure_test(float pressure);
        void setTemperature_test(float temperature);
  
};
