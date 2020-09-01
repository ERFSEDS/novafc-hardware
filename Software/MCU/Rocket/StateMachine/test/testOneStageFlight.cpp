#include "StateMachine.hpp"
#include <iostream>


int main() {
	//set configuration
	
	
	StateMachine::changeState(READY);
	StateMachine::changeState(STAGE1POWERED);
	StateMachine::changeState(STAGE1COAST);
	StateMachine::changeState(DROGUEPAR);
	StateMachine::changeState(MAINPAR);
	StateMachine::changeState(LANDED);
	StateMachine::changeState(RESET);
	
	if(StateMachine::getCurrentState() != RESET) {
		return 1;
	}
	
	
	
	return 0; //success
}
