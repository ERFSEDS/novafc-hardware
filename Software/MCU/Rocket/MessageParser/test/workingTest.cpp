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
		   (void*)(&snoops),
		   &(TransmitSnooper::snoopCallback));
	Cartesian gravity = {0,9.81,0};
	uint8_t * responseBuffer = new uint8_t[BUFFER_SIZE * 2];
	Configuration config;
	SensorValues sensors(config);
	RocketData data(config, sensors, gravity);
	StateMachine state(config, log);
	Brain brain(config, state, data, sensors, log, &(LowLevelSimulator::arm_callback), (void*)(&sim), &(LowLevelSimulator::fire_callback), (void*)(&sim));
	MessageHandler handler(config, brain, sensors, data, log, (void*)(&sim), &(LowLevelSimulator::transmit_callback));

	//yuck all that above is stetup
	uint8_t messageOutput[22] = {1, 16, 0, 1, 1, 56, 2, 4, 0, 1, 7, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 2};// get RotationX	set altitude 0	arm Rocket

	snoops.snoop(true);
	//test time
	handler.parseMessage(messageOutput, 22);
	
	return snoops.matchedExpected();
	

}
