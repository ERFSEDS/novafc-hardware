#include "Configuration.hpp"
#include <iostream>

int main() {
	Configuration config;
	float armingAltitude;
	bool success;
	
	//set arming altitude to 10
	armingAltitude = 10;
	config.setArmingAltitude(armingAltitude);
	success = armingAltitude == config.getArmingAltitude();
	if (!success) {
		std::cout << "Failed to set arming altitude" << std::endl;
		return 1;
	}
	
	
	//set arming altitude to 65.3
	armingAltitude = 65.3;
	config.setArmingAltitude(armingAltitude);
	success = armingAltitude == config.getArmingAltitude();
	if (!success) {
		std::cout << "Failed to set arming altitude" << std::endl;
		return 1;
	}
	
	//success
	return 0;
}
