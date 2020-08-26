#include "Configuration.hpp"
#include <iostream>

int main() {
	float threshold;
	bool success;
	
	//test set Ignition threshold 10.25
	threshold = 10.25;
	Configuration::setIgnitionThreshold(threshold);
	success = threshold == Configuration::getIgnitionThreshold();
	if(!success) {
		std::cout << "Failed to set Ignition Threshold" << std::endl;
		return 1;
	}
	
	//test set ignition 83
	threshold = 83;
	Configuration::setIgnitionThreshold(threshold);
	success = threshold == Configuration::getIgnitionThreshold();
	if(!success) {
		std::cout << "Failed to set Ignition Threshold" << std::endl;
		return 1;
	}
	
	//test set cutoff threshold 6.5
	threshold = 6.5;
	Configuration::setCutoffThreshold(threshold);
	success = threshold == Configuration::getCutoffThreshold();
	if(!success) {
		std::cout << "Failed to set Cutoff Threshold" << std::endl;
		return 1;
	}
	
	//test set cutoff threshold 946
	threshold = 946;
	Configuration::setCutoffThreshold(threshold);
	success = threshold == Configuration::getCutoffThreshold();
	if(!success) {
		std::cout << "Failed to set Cutoff Threshold" << std::endl;
		return 1;
	}
	
	//SUCCESS
	return 0;
}
