#include "Configuration.hpp"
#include "StateMachine.hpp"
#include "MessageHandler.hpp"
#include "SensorValues.h"
#include "RocketData.h"
#include "Brain.hpp"
#include "StateMachine.hpp"
#include <iostream>


int main() {
	uint8_t messageOutput[22] = {1, 16, 0, 1, 1, 56, 2, 4, 0, 1, 7, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 2};// get RotationX	set altitude 0	arm Rocket
	
	uint8_t * responseBuffer = new uint8_t[BUFFER_SIZE * 2];
	Configuration config;
	SensorValues sensors(config);
	RocketData data();
	StateMachine state();
	Brain brain(config, state, data, sensors, ARM_CALLBACK, armContext, FIRE_CALLBACK, fireContext);
	MessageHandler handler(config, brain, sensors, data);
	handler.parseMessage(messageOutput, 22);
	
	std::cout << "Response: <";
	for(int i = 0; i < (int)(BUFFER_SIZE * 2); i++) {
		std::cout << (int)responseBuffer[i] << ", " ;
	}
	std::cout << ">" << std::endl;
	return 1;//I wanna see the output
	

}
