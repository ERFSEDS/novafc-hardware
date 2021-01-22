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
	int result = 0;
	//set configuration
	config.setTwoStageRocket(true);
	
	stateMachine.refresh();
	stateMachine.changeState(READY);
	stateMachine.changeState(STAGE1POWERED);
	stateMachine.changeState(STAGE1COAST);
	stateMachine.changeState(STAGE2POWERED);
	stateMachine.changeState(STAGE2COAST);
	stateMachine.changeState(DROGUEPAR);
	stateMachine.changeState(MAINPAR);
	stateMachine.changeState(LANDED);
	stateMachine.changeState(RESET);
	
	if(stateMachine.getCurrentState() != RESET) {
		result = 1;
		log.Fatal("Did not properly handle a 2 stage flight");
	}
	else {
	  log.Info("Successful flight");
	}
	
	
	
	return result;
}
