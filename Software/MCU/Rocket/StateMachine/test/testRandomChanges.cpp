#include "StateMachine.hpp"
#include "Logger.hpp"
#include "Configuration.hpp"
#include <iostream>
#include "LowLevelSimulator.hpp"
int main() {
	LowLevelSimulator sim;

	Logger log( (void*)(&sim),
		    &(LowLevelSimulator::flash_write_callback),
		    (void*)(&sim),
		    &(LowLevelSimulator::transmit_callback));
	
	//illegal
	int result = 0;
	Configuration config;
	StateMachine stateMachine(config, log);
	stateMachine.changeState(STAGE1POWERED);
	stateMachine.changeState(STAGE1COAST);
	stateMachine.changeState(RESET);
	
	if(stateMachine.getCurrentState() != UNARMED) {
		std::cout << "Failed part 1" << std::endl;
		result = 1;
	}
	//change state
	stateMachine.changeState(READY);
	
	//illegal
	stateMachine.changeState(STAGE2POWERED);
	stateMachine.changeState(STAGE1COAST);
	stateMachine.changeState(RESET);
	
	if(stateMachine.getCurrentState() != READY) {
		std::cout << "Failed part 2" << std::endl;
		result = 1;
	}
	
	char msg[100];
	if(result == 1) {
		std::sprintf(msg, "State Machine did not handle prevent bad changes");
		log.Fatal(msg);
	}
	else {
		std::sprintf(msg, "Successful Flight!");
		log.Info(msg);
	}
	
	return result;
}
