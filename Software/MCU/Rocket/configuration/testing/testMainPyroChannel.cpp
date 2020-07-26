#include "Configuration.hpp"
#include <iostream>

int main() {
	Configuration config;
	int channel;
	bool success;
	
	//set main channel to 0
	channel = 0;
	config.setMainPyroChannel(channel);
	success = channel == config.getMainPyroChannel();
	if (!success) {
		std::cout << "Failed to set main pyro" << std::endl;
		return 1;
	}
	
	
	//set main channel to 1
	channel = 1;
	config.setMainPyroChannel(channel);
	success = channel == config.getMainPyroChannel();
	if (!success) {
		std::cout << "Failed to set main pyro" << std::endl;
		return 1;
	}
	
	//attempt to set main pyro to -1, should be set to 0
	channel = -1;
	config.setMainPyroChannel(channel);
	success = 0 == config.getMainPyroChannel();
	if (!success) {
		std::cout << "Failed to properly handle negative val main pyro" << std::endl;
		return 1;
	}
	
	//attempt to set main pyro to NUMBER_OF_PYROS, should be set to #NUMBER_OF_PYROS-1
	channel = NUMBER_OF_PYROS;
	config.setMainPyroChannel(channel);
	success = NUMBER_OF_PYROS-1 == config.getMainPyroChannel();
	if (!success) {
		std::cout << "Failed to properly handle to large val main pyro" << std::endl;
		return 1;
	}
	
	//success
	return 0;
}
