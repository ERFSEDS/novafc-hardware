#include "Configuration.hpp"
#include <iostream>

int main() {
	bool drogueChute;
	bool success;
	
	//set arming altitude to true
	drogueChute = true;
	Configuration::setDrogueChute(drogueChute);
	success = drogueChute == Configuration::getDrogueChute();
	if (!success) {
		std::cout << "Failed to set drogue chute" << std::endl;
		return 1;
	}
	
	
	//set arming altitude to false
	drogueChute = false;
	Configuration::setDrogueChute(drogueChute);
	success = drogueChute == Configuration::getDrogueChute();
	if (!success) {
		std::cout << "Failed to set drogue chute" << std::endl;
		return 1;
	}
	
	//success
	return 0;
}
