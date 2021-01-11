#include "StateMachine.hpp"
#include "Logger.hpp"
#include "Configuration.hpp"
#include <cstdio>
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
	//set configuration
	Configuration config;
	StateMachine stateMachine(config);
	config.setTwoStageRocket(false);
	
	stateMachine.refresh();
	stateMachine.changeState(READY);
	stateMachine.changeState(STAGE1POWERED);
	stateMachine.changeState(STAGE1COAST);
	stateMachine.changeState(DROGUEPAR);
	stateMachine.changeState(MAINPAR);
	stateMachine.changeState(LANDED);
	stateMachine.changeState(RESET);
	
	char msg[100];
	if(stateMachine.getCurrentState() != RESET) {
		std::sprintf(msg, "Did not properly handle a 1 stage flight");
		Logger::Fatal(msg, 41);
		return 1;
	}
	else {
		std::sprintf(msg,  "Successful Flight!");
		Logger::Info(msg, 19);
	}
	
	
	
	return 0; //success
}
