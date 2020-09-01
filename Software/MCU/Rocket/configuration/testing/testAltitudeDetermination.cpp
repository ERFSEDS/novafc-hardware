#include "Configuration.hpp"
#include <iostream>

int main() {
	AltitudeDeterminination determine;
	bool success;
	
	//Altitude Determination = ACCELEROMETER ONLY
	determine = ACCELEROMETER_ONLY;
	Configuration::setAltitudeDetermination(determine);
	success = determine == Configuration::getAltitudeDetermination();
	if( !success ) {
		std::cout << "Failed to set Altitude Determination" << std::endl;
		return 1;
	}
	
	//Altitude Determination = BOTH
	determine = BOTH;
	Configuration::setAltitudeDetermination(determine);
	success = determine == Configuration::getAltitudeDetermination();
	if( !success ) {
		std::cout << "Failed to set Altitude Determination" << std::endl;
		return 1;
	}
	
	//success
	return 0;
}
