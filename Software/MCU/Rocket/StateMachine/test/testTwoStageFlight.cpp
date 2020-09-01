#include "StateMachine.hpp"
#include "Logger.hpp"
#include "Configuration.hpp"


int main() {
	//set configuration
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
	
	if(StateMachine::getCurrentState() != RESET) {
		Logger::Fatal("Did not properly handle a 2 stage flight");
		return 1;
	}
	else {
		Logger::Info("Successful Flight!");
	}
	
	
	
	return 0; //success
}
