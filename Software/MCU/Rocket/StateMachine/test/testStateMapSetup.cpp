#include "StateMachine.hpp"
#include "Logger.hpp"
#include "Configuration.hpp"
#include <iostream>
void flash_write_callback(const char * msg, const size_t size) {
	std::string message(msg, size);
	std::cout << "[Store]: " << message << std::endl;	
}
void transmit_callback(const char * msg, const size_t size) {
	std::string message(msg, size);
	std::cout << "[Transmit]: "  << message << std::endl;
}
int main() {
	Logger::setTransmitCallback(&transmit_callback);
	Logger::setFlashWriteCallback(&flash_write_callback);
	//check to make sure 2 stage cannot go to 1 stage flight
	Configuration config;
	StateMachine stateMachine(config);
	config.setTwoStageRocket(true);
	char msg[100];
	int result = 0;
	
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
		std::sprintf(msg, "Did not properly handle a 1 stage flight");
		Logger::Fatal(msg, 42);
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
	stateMachine.changeState(DROGUEPAR);
	stateMachine.changeState(MAINPAR);
	stateMachine.changeState(LANDED);
	stateMachine.changeState(RESET);
	
	
	//should get stuck all the way throguh
	if(stateMachine.getCurrentState() != RESET) {
		std::sprintf(msg, "Did not properly handle a 2 stage flight");
		Logger::Fatal(msg, 42);
		result = 1;
	}
	else {
		result = 0;
	}
	
	if(result == 1) {
		std::sprintf(msg, "State Machine did not handle prevent bad changes");
		Logger::Fatal(msg, 49);
	}
	else {
		std::sprintf(msg, "Successful Flight!");
		Logger::Info(msg, 19);
	}
	return 0; //success
}
