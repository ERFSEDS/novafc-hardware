#include "Configuration.hpp"

int main() {
	Configuration config;

	//set false
	bool setValue = false;
	config.setSafetyLock(setValue);
	bool success = config.getSafetyLock() == setValue;
	if(!success) {
		return 1;
	}

	//set true	
	setValue = true;
	config.setSafetyLock(setValue);
	success = config.getSafetyLock() == setValue;
	if(!success) {
		return 1;
	}
	
	return 0;
}
