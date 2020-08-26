#include "Configuration.hpp"
#include <iostream>

int main() {
	//can set to false
	bool testSet = false;
	Configuration::setTwoStageRocket(testSet);
	bool success = Configuration::getTwoStageRocket() == testSet;
	if(!success) {
		std::cout << "Failed to set two stage" << std::endl;
		return 1;
	}

	//can set to true
	testSet = true;
	Configuration::setTwoStageRocket(testSet);
	success == Configuration::getTwoStageRocket() == testSet;
	if(!success) {
		std::cout << "Failed to set two stage" << std::endl;
		return 1;
	}


	return 0;
}
