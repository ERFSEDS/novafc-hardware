#include "StateMachine.hpp"
#include "Logger.hpp"
#include "Configuration.hpp"
#include <iostream>
#include "LowLevelSimulator.hpp"

int main() {

  LowLevelSimulator sim;
  Logger log((void*)(&sim),
	     &(LowLevelSimulator::transmit_callback),
	     (void*)(&sim),
	     &(LowLevelSimulator::flash_write_callback));
	//check to make sure 2 stage cannot go to 1 stage flight
	Configuration config;
	StateMachine stateMachine(config, log);
	config.setTwoStageRocket(true);
	char msg[100];
	int result = 0;
	
	stateMachine.refresh();
	stateMachine.changeState(READY);
	stateMachine.changeState(STAGE1POWERED);
	stateMachine.changeState(STAGE1COAST);
	stateMachine.changeState(DESCENT);
	stateMachine.changeState(LANDED);
	stateMachine.changeState(RESET);
	
	///should get stuck at stage1coast
	if(stateMachine.getCurrentState() != STAGE1COAST) {
		std::sprintf(msg, "Did not properly handle a 1 stage flight");
		log.Fatal(msg);
		result = 1;
	}
	else {
		result = 0;
	}
	
	//check to make sure 1 stage cannot go to 2 stage flight
	config.setTwoStageRocket(true);
	
	stateMachine.refresh();
	stateMachine.changeState(READY);
	stateMachine.changeState(STAGE1POWERED);
	stateMachine.changeState(STAGE1COAST);
	stateMachine.changeState(STAGE2POWERED);
	stateMachine.changeState(STAGE2COAST);
	stateMachine.changeState(DESCENT);
	stateMachine.changeState(LANDED);
	stateMachine.changeState(RESET);
	
	
	//should get stuck all the way throguh
	if(stateMachine.getCurrentState() != RESET) {
		std::sprintf(msg, "Did not properly handle a 2 stage flight");
		log.Fatal(msg);
		result = 1;
	}
	else {
		result = 0;
	}
	
	if(result == 1) {
		std::sprintf(msg, "State Machine did not handle prevent bad changes");
		log.Fatal(msg);
	}
	else {
		std::sprintf(msg, "Successful Flight!");
		log.Info(msg);
	}
	return 0; //success
}
