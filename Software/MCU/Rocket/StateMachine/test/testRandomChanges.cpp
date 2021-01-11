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
	//illegal
	int result = 0;
	Configuration config;
	StateMachine stateMachine(config);
	stateMachine.changeState(STAGE1POWERED);
	stateMachine.changeState(STAGE1COAST);
	stateMachine.changeState(RESET);
	
	if(stateMachine.getCurrentState() != UNARMED) {
		std::cout << "Failed part 1" << std::endl;
		result = 1;
	}
	//change state
	stateMachine.changeState(READY);
	
	//illegal
	stateMachine.changeState(STAGE2POWERED);
	stateMachine.changeState(STAGE1COAST);
	stateMachine.changeState(RESET);
	
	if(stateMachine.getCurrentState() != READY) {
		std::cout << "Failed part 2" << std::endl;
		result = 1;
	}
	
	char msg[100];
	if(result == 1) {
		std::sprintf(msg, "State Machine did not handle prevent bad changes");
		Logger::Fatal(msg, 49);
	}
	else {
		std::sprintf(msg, "Successful Flight!");
		Logger::Info(msg, 19);
	}
	
	return result;
}
