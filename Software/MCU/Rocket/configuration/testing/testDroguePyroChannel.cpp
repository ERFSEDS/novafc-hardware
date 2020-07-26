#include "Configuration.hpp"
#include <iostream>

int main() {
	Configuration config;
	int channel;
	bool success;
	
	//set drogue channel to 0
	channel = 0;
	config.setDroguePyroChannel(channel);
	success = channel == config.getDroguePyroChannel();
	if (!success) {
		std::cout << "Failed to set drogue pyro" << std::endl;
		return 1;
	}
	
	
	//set drogue channel to 1
	channel = 1;
	config.setDroguePyroChannel(channel);
	success = channel == config.getDroguePyroChannel();
	if (!success) {
		std::cout << "Failed to set drogue pyro" << std::endl;
		return 1;
	}
	
	//attempt to set drogue pyro to -1, should be set to 0
	channel = -1;
	config.setDroguePyroChannel(channel);
	success = 0 == config.getDroguePyroChannel();
	if (!success) {
		std::cout << "Failed to properly handle negative val drogue pyro" << std::endl;
		return 1;
	}
	
	//attempt to set drogue pyro to NUMBER_OF_PYROS, should be set to #NUMBER_OF_PYROS-1
	channel = NUMBER_OF_PYROS;
	config.setDroguePyroChannel(channel);
	success = NUMBER_OF_PYROS-1 == config.getDroguePyroChannel();
	if (!success) {
		std::cout << "Failed to properly handle to large val drogue pyro" << std::endl;
		return 1;
	}
	
	//success
	return 0;
}
