#include "StateMachine.hpp"
#include "Logger.hpp"
#include "Configuration.hpp"


int main() {	
	Configuration config;
	StateMachine stateMachine(config);
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
		Logger::Fatal("Did not properly handle a 2 stage flight");
		return 1;
	}
	else {
		Logger::Info("Successful Flight!");
	}
	
	
	
	return 0; //success
}
