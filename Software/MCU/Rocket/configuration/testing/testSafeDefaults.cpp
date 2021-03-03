#include "Configuration.hpp"
#include <iostream>

int main() {
	//Safety Lock Enabled by default
	Configuration config;	
	//Safety Lock Value is lower 0 < x <= 45
	float safetyLockValue = config.getSafetyLockValue();
	if ( (safetyLockValue > 0) && (safetyLockValue <= 45) ) {
		std::cout << "Default Safety Lock Value is not appropriate" << std::endl;
		return false;
	}


}
