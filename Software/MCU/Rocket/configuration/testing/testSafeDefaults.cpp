#include "Configuration.hpp"
#include <iostream>

int main() {
	//Safety Lock Enabled by default
	if (Configuration::getSafetyLock() != true) {
		std::cout << "Failed to enable Safety Lock by default" << std::endl;
		return false;
	}
	
	//Safety Lock Value is lower 0 < x <= 45
	float safetyLockValue = Configuration::getSafetyLockValue();
	if ( (safetyLockValue > 0) && (safetyLockValue <= 45) ) {
		std::cout << "Default Safety Lock Value is not appropriate" << std::endl;
		return false;
	}


}
