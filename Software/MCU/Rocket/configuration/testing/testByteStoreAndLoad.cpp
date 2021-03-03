#include "Configuration.hpp"
#include <iostream>

int main() {
  Configuration config;

  //values dont really matter just need them to be not the default
  config.setTwoStageRocket(false);
  config.setSafetyLockValue(102.0);
  config.setPyro(0, false, VELOCITY_ABOVE, 100, TIME_DELAY, 10);
  config.setPyro(1, true, ALTITUDE_ABOVE, 101, ACCELERATION_ABOVE, 11);
  config.setPyro(2, false, ALTITUDE_BELOW, 102, TIME_DELAY, 12);
  config.setIgnitionThreshold(5.0);
  config.setCutoffThreshold(9.5);
  config.setLoggingRates({100,10});
  config.setAltitudeDetermination(ACCELEROMETER_ONLY);
  config.setArmingAltitude(50.0);
  config.setUpperTimeStepms(156);


  uint8_t buffer[CONFIG_BUFFER_SIZE];
  config.generateConfig(buffer);
  Configuration configTwo;
  
  configTwo.updateFromConfig(buffer);

  bool success = true;

  if(configTwo.getTwoStageRocket() != config.getTwoStageRocket()) {
    success = false;
    std::cout << "Failed two stage rocket" <<std::endl;
  }

  if(configTwo.getSafetyLockValue() != config.getSafetyLockValue()) {
    success = false;
    std::cout << "Failed safety lock value" <<std::endl;
    std::cout << "expected: " << config.getSafetyLockValue() << std::endl;
    std::cout << "actual: " << configTwo.getSafetyLockValue() << std::endl;
  }

  if(!(*configTwo.getPyro(0) == *config.getPyro(0))) {
    success = false;
    std::cout << "Failed Pyro 0" << std::endl;
    Pyro pyro = *config.getPyro(0);
    Pyro pyroTwo = *configTwo.getPyro(0);
    std::cout << "expected configOne: " << pyro.configOne << std::endl;
    std::cout << "actual configOne: " << pyroTwo.configOne << std::endl;
    std::cout << "expected valueOne: " << pyro.valueOne << std::endl;
    std::cout << "actual valueOne: " << pyroTwo.valueOne << std::endl;
    
    std::cout << "expected configTwo: " << pyro.configTwo << std::endl;
    std::cout << "actual configTwo: " << pyroTwo.configTwo << std::endl;
    std::cout << "expected valueTwo: " << pyro.valueTwo << std::endl;
    std::cout << "actual valueTwo: " << pyroTwo.valueTwo << std::endl;

    std::cout << "expected tilt lock: " << pyro.tiltLock << std::endl;
    std::cout << "actual tilt lock: " << pyroTwo.tiltLock << std::endl;
  }
  
  if(!(*configTwo.getPyro(1) == *config.getPyro(1))) {
    success = false;
    std::cout << "Failed Pyro 1" << std::endl;
    Pyro pyro = *config.getPyro(1);
    Pyro pyroTwo = *configTwo.getPyro(1);
    std::cout << "expected configOne: " << pyro.configOne << std::endl;
    std::cout << "actual configOne: " << pyroTwo.configOne << std::endl;
    std::cout << "expected valueOne: " << pyro.valueOne << std::endl;
    std::cout << "actual valueOne: " << pyroTwo.valueOne << std::endl;
    
    std::cout << "expected configTwo: " << pyro.configTwo << std::endl;
    std::cout << "actual configTwo: " << pyroTwo.configTwo << std::endl;
    std::cout << "expected valueTwo: " << pyro.valueTwo << std::endl;
    std::cout << "actual valueTwo: " << pyroTwo.valueTwo << std::endl;

    std::cout << "expected tilt lock: " << pyro.tiltLock << std::endl;
    std::cout << "actual tilt lock: " << pyroTwo.tiltLock << std::endl;
  }
  
  if(!(*configTwo.getPyro(2) == *config.getPyro(2))) {
    success = false;
    std::cout << "Failed Pyro 2" << std::endl;
    Pyro pyro = *config.getPyro(2);
    Pyro pyroTwo = *configTwo.getPyro(2);
    std::cout << "expected configOne: " << pyro.configOne << std::endl;
    std::cout << "actual configOne: " << pyroTwo.configOne << std::endl;
    std::cout << "expected valueOne: " << pyro.valueOne << std::endl;
    std::cout << "actual valueOne: " << pyroTwo.valueOne << std::endl;
    
    std::cout << "expected configTwo: " << pyro.configTwo << std::endl;
    std::cout << "actual configTwo: " << pyroTwo.configTwo << std::endl;
    std::cout << "expected valueTwo: " << pyro.valueTwo << std::endl;
    std::cout << "actual valueTwo: " << pyroTwo.valueTwo << std::endl;

    std::cout << "expected tilt lock: " << pyro.tiltLock << std::endl;
    std::cout << "actual tilt lock: " << pyroTwo.tiltLock << std::endl;
  }

  if(configTwo.getIgnitionThreshold() != config.getIgnitionThreshold()) {
    success = false;
    std::cout << "failed ignition threshold" << std::endl;
  }

  if(configTwo.getCutoffThreshold() != config.getCutoffThreshold()) {
    success = false;
    std::cout << "Failed cutoff threshold" << std::endl;
  }

  if(configTwo.getLoggingRates() != config.getLoggingRates()) {
    success = false;
    std::cout << "failed logging rates" << std::endl;
  }

  if(configTwo.getAltitudeDetermination() != config.getAltitudeDetermination()) {
    success =false;
    std::cout << "failed altitude determination" << std::endl;
  }

  if(configTwo.getArmingAltitude() != config.getArmingAltitude()) {
    success = false;
    std::cout << "failed arming altitude" << std::endl;
  }

  if(config.getUpperTimeStepms() != configTwo.getUpperTimeStepms()) {
    success = false;
    std::cout << "failed upper time step" << std::endl;
  }

  if(configTwo.getTest() != false) {//always set this to false
    success = false;
    std::cout << "Failed to set test to false always on bootup" <<std::endl;
  }

  if(success) {
    std::cout << "Success" << std::endl;
  }
  else {
    std::cout << "Failure" << std::endl;
  }
  return success;
}
