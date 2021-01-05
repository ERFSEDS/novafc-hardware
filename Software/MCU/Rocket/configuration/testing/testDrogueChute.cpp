#include "Configuration.hpp"
#include <iostream>

int main() {
	bool drogueChute;
	bool success;
	Configuration config;
	
	//set arming altitude to true
	drogueChute = true;
	config.setDrogueChute(drogueChute);
	success = drogueChute == config.getDrogueChute();
	if (!success) {
		std::cout << "Failed to set drogue chute" << std::endl;
		return 1;
	}
	
	
	//set arming altitude to false
	drogueChute = false;
	config.setDrogueChute(drogueChute);
	success = drogueChute == config.getDrogueChute();
	if (!success) {
		std::cout << "Failed to set drogue chute" << std::endl;
		return 1;
	}
	
	//success
	return 0;
}
