#include "Configuration.hpp"
#include "StateMachine.hpp"
#include "MessageHandler.hpp"
#include "SensorValues.h"
#include "RocketData.h"
#include "Brain.hpp"
#include "StateMachine.hpp"
#include <iostream>
#include "LowLevelSimulator.hpp"
#include "TransmitSnooper.hpp"
int main() {	
	LowLevelSimulator sim;
	TransmitSnooper snoops(false, (void*)(&sim),
			       &(LowLevelSimulator::transmit_callback));
	Logger log((void*)(&sim),
		   &(LowLevelSimulator::flash_write_callback),
		   (void*)(&sim),
		   &(LowLevelSimulator::transmit_callback));
	Cartesian gravity = {0,9.81,0};
	uint8_t * responseBuffer = new uint8_t[BUFFER_SIZE * 2];
	Configuration config;
	SensorValues sensors(config);
	RocketData data(config, sensors, gravity);
	StateMachine state(config, log);
	Brain brain(config, state, data, sensors, log, &(LowLevelSimulator::arm_callback), (void*)(&sim), &(LowLevelSimulator::fire_callback), (void*)(&sim));
	MessageHandler handler(config, brain, sensors, data, log, (void*)(&snoops), &(TransmitSnooper::snoopCallback));

	//yuck all that above is stetup
	uint8_t messageOutput[28] = {1, 2, 13, 1, 1, 1, 2, 56, 2, 4, 1, 1, 7, 1, 1, 1, 2, 2, 2, 1, 0};// get RotationX get altitude arm Rocket
	uint8_t expectedResponse[34] = {1, 2, 19, 1, 2, 56, 1, 2, 2, 4, 1,1,1,1,1,1,1,1, 7, 1,1,1,1,1,1,1,1, 1, 2, 2, 1, 2, 1, 0}; 
	snoops.snoop(true);
	snoops.setExpectedResponse(expectedResponse, 34);
	//test timeo
	handler.parseMessage(messageOutput, 28);
	
	
	if(snoops.matchedExpected()) {
	  return 0;
	}
	else {
	  return 1;
	}
	

}
