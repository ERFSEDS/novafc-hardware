#include "Configuration.hpp"
#include <iostream>

int main() {
	
	Configuration config;
	int newTimeStep;
	
	newTimeStep = 50;
	config.setUpperTimeStepms(newTimeStep);
	if(config.getUpperTimeStepms() != newTimeStep) {
		std::cout << "Could not set Upper Time step" << std::endl;
		return 1;
	}
	
	newTimeStep = 20;
	config.setUpperTimeStepms(newTimeStep);
	if(config.getUpperTimeStepms() != newTimeStep) {
		std::cout << "Could not set Upper Time step" << std::endl;
		return 1;
	}
	
	newTimeStep = 30;
	config.setLowerTimeStepms(newTimeStep);
	if(config.getLowerTimeStepms() != newTimeStep) {
		std::cout << "Could not set Lower Time step" << std::endl;
		return 1;
	}
	
	newTimeStep = 10;
	config.setLowerTimeStepms(newTimeStep);
	if(config.getLowerTimeStepms() != newTimeStep) {
		std::cout << "Could not set Lower Time step" << std::endl;
		return 1;
	}
	
	return 0;//success
}
