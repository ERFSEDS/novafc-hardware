#include "Configuration.hpp"
#include <iostream>

int main() {
	Configuration config;

	//set value to 5.25
	bool success;
	float value = 5.25;
	config.setSafetyLockValue(value);
	success = config.getSafetyLockValue() == value;
	if(!success) {
		std::cout << "Failed to set Tilt lock value"  << std::endl;
		return 1;
	}
	
	//set value to 4.0
	value = 4.0;
	config.setSafetyLockValue(value);
	success = config.getSafetyLockValue() == value;
	if(!success) {
		std::cout << "Failed to set Tilt lock value"  << std::endl;
		return 1;
	}
	
	return 0;
}
