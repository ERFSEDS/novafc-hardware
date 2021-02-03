#include "Configuration.hpp"
#include <iostream>

int main() {
	LoggingRates logRates;
	bool success;
	Configuration config;
	
	//Set Logging rates to:
	//      ascent = 0.1
	//	descent = 0.2
	logRates = {0.1, 0.2};
	config.setLoggingRates(logRates);
	success = logRates == *config.getLoggingRates();
	if( !success) {
		std::cout << "Failed to set Logging Values" <<std::endl;
		return 1;
	}
	
	//Set Logging rates to:
	//	ascent = 100
	//	descent = 70
	logRates = {100, 70};
	config.setLoggingRates(logRates);
	success = logRates == *config.getLoggingRates();
	if( !success) {
		std::cout << "Failed to set Logging Values" <<std::endl;
		return 1;
	}
	
	//success
	return 0;
}
