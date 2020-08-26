/*
 * ProjectCerberus: Nova/SensorValues
 * 
 * This class is to act like a Storage class for sensor values
 * 
 * Author: Matthew Gasper
 */
#include "SensorValues.h"

void SensorValues::setAcceleration(cartesian data){
    acceleration = data;
}

void SensorValues::setVelocity(cartesian data){
     velocity = data;
}
void SensorValues::setLocation(cartesian data){
    location = data;
}
void SensorValues::setAngularPos(cartesian data){
    angularPos = data;
}

cartesian SensorValues::getAcceleration(){
    return acceleration;
}
cartesian SensorValues::getVelocity(){
    return velocity;
}
cartesian SensorValues::getLocation(){
    return location;
}
cartesian SensorValues::getAngularPos(){
    return angularPos;
}

bool SensorValues::checkPyro(int cmd){
    enum pyros{one = 1, two = 2};
    switch(cmd){
        case one:
            return pyro[0];
            break;
        case two:
            return pyro[1];
            break;
    }
    return;
}

void SensorValues::firePyro(int cmd){
    enum pyros{one = 1, two = 2};
    switch(cmd){
        case one:
            //Insert command to fire pyro one
            break;
        case two:
            //Insert command to fire pyro two
            break;
    }
    return;
}

//FOR TESTING!!!
void SensorValues::setPyro(int cmd, bool state){
    pyro[cmd] = state;
}
