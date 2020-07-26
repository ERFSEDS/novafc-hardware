#include "Configuration.hpp"
#include <iostream>

int main() {
	Configuration config;
	AltitudeDeterminination determine;
	bool success;
	
	//Altitude Determination = ACCELEROMETER ONLY
	determine = ACCELEROMETER_ONLY;
	config.setAltitudeDetermination(determine);
	success = determine == config.getAltitudeDetermination();
	if( !success ) {
		std::cout << "Failed to set Altitude Determination" << std::endl;
		return 1;
	}
	
	//Altitude Determination = BOTH
	determine = BOTH;
	config.setAltitudeDetermination(determine);
	success = determine == config.getAltitudeDetermination();
	if( !success ) {
		std::cout << "Failed to set Altitude Determination" << std::endl;
		return 1;
	}
	
	//success
	return 0;
}
