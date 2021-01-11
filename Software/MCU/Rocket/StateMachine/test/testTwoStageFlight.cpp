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
	Configuration config;
	int result;
	char msg[100];
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
		result = 1;
		std::sprintf(msg, "Did not properly handle a 2 stage flight");
		Logger::Fatal(msg, 40);
		return 1;
	}
	else {
		std::sprintf(msg, "Successful flight");
		Logger::Info(msg, 19);
	}
	
	
	
	return 0; //success
}
