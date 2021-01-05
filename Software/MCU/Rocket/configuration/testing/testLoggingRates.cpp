#include "Configuration.hpp"
#include <iostream>

int main() {
	LoggingRates logRates;
	bool success;
	Configuration config;
	
	//Set Logging rates to:
	//	preLaunch = 0.1
	//	poweredFlight = 50
	//	unpoweredFlight = 25
	//	descent = 0
	logRates = {0.1, 50, 25, 0};
	config.setLoggingRates(logRates);
	success = logRates == *config.getLoggingRates();
	if( !success) {
		std::cout << "Failed to set Logging Values" <<std::endl;
		return 1;
	}
	
	//Set Logging rates to:
	//	preLaunch = 100
	//	poweredFlight = 0.1
	//	unpoweredFlight = 0.6
	//	descent = 70
	logRates = {100, 0.1, 0.6, 70};
	config.setLoggingRates(logRates);
	success = logRates == *config.getLoggingRates();
	if( !success) {
		std::cout << "Failed to set Logging Values" <<std::endl;
		return 1;
	}
	
	//success
	return 0;
}
