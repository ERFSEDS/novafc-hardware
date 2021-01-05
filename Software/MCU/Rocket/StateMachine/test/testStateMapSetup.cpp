#include "StateMachine.hpp"
#include "Logger.hpp"
#include "Configuration.hpp"


int main() {
	//check to make sure 2 stage cannot go to 1 stage flight
	Configuration config;
	StateMachine stateMachine(config);
	config.setTwoStageRocket(true);
	
	stateMachine.refresh();
	stateMachine.changeState(READY);
	stateMachine.changeState(STAGE1POWERED);
	stateMachine.changeState(STAGE1COAST);
	stateMachine.changeState(DROGUEPAR);
	stateMachine.changeState(MAINPAR);
	stateMachine.changeState(LANDED);
	stateMachine.changeState(RESET);
	
	///should get stuck at stage1coast
	if(stateMachine.getCurrentState() != STAGE1COAST) {
		Logger::Fatal("Did not properly handle a 1 stage flight");
		return 1;
	}
	else {
		Logger::Info("Successful Flight!");
	}
	
	//check to make sure 1 stage cannot go to 2 stage flight
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
	
	//should get stuck at stage 1 coast
	if(stateMachine.getCurrentState() != RESET) {
		Logger::Fatal("Did not properly handle a 2 stage flight");
		return 1;
	}
	else {
		Logger::Info("Successful Flight!");
	}
	
	return 0; //success
}
