/* ProjectCerberus: Nova/SensorValues
 * Description: This class is to act like a Storage class for sensor values
 * Author: Matthew Gasper
 */
#include "SensorValues.hpp"

SensorValues::SensorValues(Configuration& config) : acceleration{0,0,0},
						    angularVelocity{0,0,0},
						    sPressure(0),
						    cPressure{0},
						    temperature(0),
						    deltaT(0),
						    pyro({false, false}),
						    config(config) {
}
void SensorValues::setAcceleration(Cartesian data){
  if(!config.getTest()) {
    acceleration[1] = acceleration[0];
    acceleration[0] = data;
  }
}
void SensorValues::setAngularVelocity(Cartesian data){  
  if(!config.getTest()) {  
    angularVelocity[1] = angularVelocity[0];
    angularVelocity[0] = data;
  }
}
void SensorValues::setCPressure(float pressure){
  if(!config.getTest()) {
    cPressure[1] = cPressure[0];        
    cPressure[0] = pressure;
  }
}
void SensorValues::setSPressure(float pressure){
  if(!config.getTest()) {
    sPressure = pressure;
  }
}
void SensorValues::setTemperature(float temp){
  if(!config.getTest()) {
    temperature = temp;
  }
}

Cartesian   SensorValues::getAcceleration(){      return (acceleration[1] + acceleration[0])*0.5;}
Cartesian   SensorValues::getAngularVelocity(){   return (angularVelocity[1] + angularVelocity[0])*0.5;}
float       SensorValues::getSPressure(){         return sPressure;}
float       SensorValues::getCPressure(){         return (cPressure[1] + cPressure[0])*0.5;}
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

void SensorValues::setAcceleration_test(Cartesian data) {
  if(config.getTest()) {
    acceleration[1] = acceleration[0];
    acceleration[0] = data;
  }
}
void SensorValues::setAngularVelocity_test(Cartesian data) {
  if(config.getTest()) {  
    angularVelocity[1] = angularVelocity[0];
    angularVelocity[0] = data;
  }
}
void SensorValues::setSPressure_test(float pressure) {
  if(config.getTest()) {
    sPressure = pressure;
  }
}
void SensorValues::setCPressure_test(float pressure) {
  if(config.getTest()) {
    cPressure[1] = cPressure[0];        
    cPressure[0] = pressure;
  }
}
void SensorValues::setTemperature_test(float temperature) {
  if(config.getTest()) {
    this->temperature = temperature;
  }
}

