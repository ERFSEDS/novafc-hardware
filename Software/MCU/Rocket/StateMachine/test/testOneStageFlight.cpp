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
	config.setTwoStageRocket(false);
	
	stateMachine.refresh();
	stateMachine.changeState(READY);
	stateMachine.changeState(STAGE1POWERED);
	stateMachine.changeState(STAGE1COAST);
	stateMachine.changeState(DESCENT);
	stateMachine.changeState(LANDED);
	stateMachine.changeState(RESET);
	
	char msg[100];
	if(stateMachine.getCurrentState() != RESET) {
	  log.Fatal("Did not properly handle a 1 stage");
	  result = 1;
	}
	else {
	  log.Info("Successful Flight!");
	}
	
	
	
	return result;
}
