#include "StateMachine.hpp"
#include "Logger.hpp"
#include "Configuration.hpp"


int main() {
	//check to make sure 2 stage cannot go to 1 stage flight
	Configuration::setTwoStageRocket(true);
	
	StateMachine::refresh();
	StateMachine::changeState(READY);
	StateMachine::changeState(STAGE1POWERED);
	StateMachine::changeState(STAGE1COAST);
	StateMachine::changeState(DROGUEPAR);
	StateMachine::changeState(MAINPAR);
	StateMachine::changeState(LANDED);
	StateMachine::changeState(RESET);
	
	///should get stuck at stage1coast
	if(StateMachine::getCurrentState() != STAGE1COAST) {
		Logger::Fatal("Did not properly handle a 1 stage flight");
		return 1;
	}
	else {
		Logger::Info("Successful Flight!");
	}
	
	//check to make sure 1 stage cannot go to 2 stage flight
	Configuration::setTwoStageRocket(true);
	
	StateMachine::refresh();
	StateMachine::changeState(READY);
	StateMachine::changeState(STAGE1POWERED);
	StateMachine::changeState(STAGE1COAST);
	StateMachine::changeState(STAGE2POWERED);
	StateMachine::changeState(STAGE2COAST);
	StateMachine::changeState(DROGUEPAR);
	StateMachine::changeState(MAINPAR);
	StateMachine::changeState(LANDED);
	StateMachine::changeState(RESET);
	
	//should get stuck at stage 1 coast
	if(StateMachine::getCurrentState() != RESET) {
		Logger::Fatal("Did not properly handle a 2 stage flight");
		return 1;
	}
	else {
		Logger::Info("Successful Flight!");
	}
	
	return 0; //success
}
