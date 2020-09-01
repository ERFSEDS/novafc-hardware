#include "StateMachine.hpp"
#include "Logger.hpp"
#include "Configuration.hpp"


int main() {
	//illegal
	StateMachine::changeState(STAGE1POWERED);
	StateMachine::changeState(STAGE1COAST);
	StateMachine::changeState(RESET);
	
	if(StateMachine::getCurrentState() != UNARMED) {
		Logger::Fatal("State Machine changed state when it shouldnt have");
		return 1;
	}
	else {
		Logger::Info("nothing happened, SUCCESS!!!!");
	}
	//change state
	StateMachine::changeState(READY);
	
	//illegal
	StateMachine::changeState(STAGE2POWERED);
	StateMachine::changeState(STAGE1COAST);
	StateMachine::changeState(RESET);
	
	if(StateMachine::getCurrentState() != READY) {
		Logger::Fatal("State Machine changed state when it shouldnt have");
		return 1;
	}
	else {
		Logger::Info("nothing happened, SUCCESS!!!!");
	}
	
	
	return 0; //success
}
