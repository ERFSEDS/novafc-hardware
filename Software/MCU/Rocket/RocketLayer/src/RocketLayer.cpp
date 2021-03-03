#include "RocketLayer.hpp"
#include <string>

RocketLayer::RocketLayer(void (*arm_callback)(void*, bool), void *armContext,
			 void (*fire_callback)(void*, int), void *fireContext,
			 void (*flash_write_callback)(void*, std::string), void * writeContext,
			 void (*transmit_callback)(void*, std::string), void *transmitContext,
			 uint8_t * configurationBytes, float upperLevelFloat,
			 Cartesian startGravity, float groundPressure) :
  config{},
  logger{writeContext, flash_write_callback, transmitContext, transmit_callback},
  sensors{config},
  data{config, sensors, startGravity},
  stateMachine{config, logger},
  brain{config, stateMachine, data, sensors, logger, arm_callback, armContext, fire_callback, fireContext},
  parser{config, brain, sensors, data, logger, stateMachine, transmitContext, transmit_callback}
  
{
  sensors.setSPressure(groundPressure);
  config.updateFromConfig(configurationBytes);
  config.setUpperTimeStepms(upperLevelFloat);
}
RocketLayer::~RocketLayer() {
  
}
		
State RocketLayer::getState() {
  return stateMachine.getCurrentState();
}
void RocketLayer::handleMessage(uint8_t * msg, size_t size) {
  parser.parseMessage(msg, size);
}
void RocketLayer::updateAcceleration(Cartesian acceleration) {
  sensors.setAcceleration(acceleration);
}
void RocketLayer::updateRotation(Cartesian rotation) {
  sensors.setAngularVelocity(rotation);
}
void RocketLayer::updatePressure(float pressure) {
  sensors.setCPressure(pressure);;
}

void RocketLayer::update() {
  data.update();
  brain.check();
}
