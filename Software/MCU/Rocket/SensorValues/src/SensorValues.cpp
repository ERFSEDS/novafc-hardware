/* ProjectCerberus: Nova/SensorValues
 * Description: This class is to act like a Storage class for sensor values
 * Author: Matthew Gasper
 */
#pragma once
#include "SensorValues.h"

void SensorValues::setAcceleration(cartesian data){     acceleration = data;}
void SensorValues::setAngularVelocity(cartesian data){  angularVelocity = data;}
void SensorValues::setSPressure(float pressure){        sPressure = pressure;}
void SensorValues::setCPressure(float pressure){        cPressure = pressure;}
void SensorValues::setTemperature(float temp){          temperature = temp;}

cartesian   SensorValues::getAcceleration(){      return acceleration;}
cartesian   SensorValues::getAngularVelocity(){   return angularVelocity;}
float       SensorValues::getSPressure(){         return sPressure;}
float       SensorValues::getCPressure(){         return cPressure;}
float       SensorValues::getTemperature(){       return temperature;}

bool SensorValues::checkPyro(int cmd){
    enum pyros{one = 1, two = 2};
    switch(cmd){
        case one: return pyro[0]; break;
        case two: return pyro[1]; break;
    }
    return false;
}

void SensorValues::firePyro(int cmd){
    enum pyros{one = 1, two = 2};
    switch(cmd){
        case one: //Insert command to fire pyro one
            break;
        case two: //Insert command to fire pyro two
            break;
    }
    return;
}

void SensorValues::setPyro(int cmd, bool state){    //FOR TESTING!!!
    pyro[cmd] = state;
}
