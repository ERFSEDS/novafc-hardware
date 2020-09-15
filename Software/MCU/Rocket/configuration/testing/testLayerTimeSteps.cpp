#include "Configuration.hpp"
#include <iostream>

int main() {
	
	int newTimeStep;
	
	newTimeStep = 50;
	Configuration::setUpperTimeStepms(newTimeStep);
	if(Configuration::getUpperTimeStepms() != newTimeStep) {
		std::cout << "Could not set Upper Time step" << std::endl;
		return 1;
	}
	
	newTimeStep = 20;
	Configuration::setUpperTimeStepms(newTimeStep);
	if(Configuration::getUpperTimeStepms() != newTimeStep) {
		std::cout << "Could not set Upper Time step" << std::endl;
		return 1;
	}
	
	newTimeStep = 30;
	Configuration::setLowerTimeStepms(newTimeStep);
	if(Configuration::getLowerTimeStepms() != newTimeStep) {
		std::cout << "Could not set Lower Time step" << std::endl;
		return 1;
	}
	
	newTimeStep = 10;
	Configuration::setLowerTimeStepms(newTimeStep);
	if(Configuration::getLowerTimeStepms() != newTimeStep) {
		std::cout << "Could not set Lower Time step" << std::endl;
		return 1;
	}
	
	return 0;//success
}
