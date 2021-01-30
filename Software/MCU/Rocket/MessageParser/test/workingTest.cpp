#include "Configuration.hpp"
#include "StateMachine.hpp"
#include "MessageHandler.hpp"
#include "SensorValues.hpp"
#include "RocketData.hpp"
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
	MessageHandler handler(config, brain, sensors, data, log, state,(void*)(&snoops), &(TransmitSnooper::snoopCallback));

	//yuck all that above is stetup

	//get orientation, get altitude, arm rocket
	uint8_t message[20] = {1,2, 12, 1,1, 1,2, 56, 2, 4, 1,1, 3, 1,1, 1,2, 2, 1,0};

	uint8_t expectedResponse[56] = {1,2, 31, 1,2, 56, 1,2, 2, 4, 63,128,1,1,1,1,
					1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
					3, 1,1,1,1,1,1,1,1, 1,2, 2, 1,2, 1,0};
	snoops.snoop(true);
	snoops.setExpectedResponse(expectedResponse, 56);
	//test timeo
	handler.parseMessage(message, 20);
	
	
	if(snoops.matchedExpected()) {
	  return 0;
	}
	else {
	  return 1;
	}
	

}
