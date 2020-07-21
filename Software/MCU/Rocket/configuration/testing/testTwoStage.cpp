#include "Configuration.hpp"

int main() {
	Configuration config;

	//can set to false
	bool testSet = false;
	config.setSafetyLock(testSet);
	bool success = config.getSafetyLock() == testSet;
	if(!success) {
		return 1;
	}

	//can set to true
	testSet = true;
	config.setSafetyLock(testSet);
	success == config.getSafetyLock() == testSet;
	if(!success) {
		return 1;
	}

	return 0;
}
