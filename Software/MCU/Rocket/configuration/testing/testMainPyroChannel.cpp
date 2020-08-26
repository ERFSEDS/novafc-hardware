#include "Configuration.hpp"
#include <iostream>

int main() {
	int channel;
	bool success;
	
	//set main channel to 0
	channel = 0;
	Configuration::setMainPyroChannel(channel);
	success = channel == Configuration::getMainPyroChannel();
	if (!success) {
		std::cout << "Failed to set main pyro" << std::endl;
		return 1;
	}
	
	
	//set main channel to 1
	channel = 1;
	Configuration::setMainPyroChannel(channel);
	success = channel == Configuration::getMainPyroChannel();
	if (!success) {
		std::cout << "Failed to set main pyro" << std::endl;
		return 1;
	}
	
	//attempt to set main pyro to -1, should be set to 0
	channel = -1;
	Configuration::setMainPyroChannel(channel);
	success = 0 == Configuration::getMainPyroChannel();
	if (!success) {
		std::cout << "Failed to properly handle negative val main pyro" << std::endl;
		return 1;
	}
	
	//attempt to set main pyro to NUMBER_OF_PYROS, should be set to #NUMBER_OF_PYROS-1
	channel = NUMBER_OF_PYROS;
	Configuration::setMainPyroChannel(channel);
	success = NUMBER_OF_PYROS-1 == Configuration::getMainPyroChannel();
	if (!success) {
		std::cout << "Failed to properly handle to large val main pyro" << std::endl;
		return 1;
	}
	
	//success
	return 0;
}
