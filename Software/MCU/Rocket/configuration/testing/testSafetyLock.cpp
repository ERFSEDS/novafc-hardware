#include "Configuration.hpp"
#include <iostream>

int main() {

	//set false
	bool setValue = false;
	Configuration::setSafetyLock(setValue);
	bool success = Configuration::getSafetyLock() == setValue;
	if(!success) {
		std::cout << "Failed to set Tilt lock"  << std::endl;
		return 1;
	}

	//set true	
	setValue = true;
	Configuration::setSafetyLock(setValue);
	success = Configuration::getSafetyLock() == setValue;
	if(!success) {
		std::cout << "Failed to set Tilt lock"  << std::endl;
		return 1;
	}
	
	//set value to 5.25
	float value = 5.25;
	Configuration::setSafetyLockValue(value);
	success = Configuration::getSafetyLockValue() == value;
	if(!success) {
		std::cout << "Failed to set Tilt lock value"  << std::endl;
		return 1;
	}
	
	//set value to 4.0
	value = 4.0;
	Configuration::setSafetyLockValue(value);
	success = Configuration::getSafetyLockValue() == value;
	if(!success) {
		std::cout << "Failed to set Tilt lock value"  << std::endl;
		return 1;
	}
	
	return 0;
}
