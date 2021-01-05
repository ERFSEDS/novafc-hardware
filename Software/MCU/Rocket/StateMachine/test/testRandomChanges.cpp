#include "StateMachine.hpp"
#include "Logger.hpp"
#include "Configuration.hpp"


int main() {
	//illegal
	Configuration config;
	StateMachine stateMachine(config);
	stateMachine.changeState(STAGE1POWERED);
	stateMachine.changeState(STAGE1COAST);
	stateMachine.changeState(RESET);
	
	if(stateMachine.getCurrentState() != UNARMED) {
		Logger::Fatal("State Machine changed state when it shouldnt have");
		return 1;
	}
	else {
		Logger::Info("nothing happened, SUCCESS!!!!");
	}
	//change state
	stateMachine.changeState(READY);
	
	//illegal
	stateMachine.changeState(STAGE2POWERED);
	stateMachine.changeState(STAGE1COAST);
	stateMachine.changeState(RESET);
	
	if(stateMachine.getCurrentState() != READY) {
		Logger::Fatal("State Machine changed state when it shouldnt have");
		return 1;
	}
	else {
		Logger::Info("nothing happened, SUCCESS!!!!");
	}
	
	
	return 0; //success
}
