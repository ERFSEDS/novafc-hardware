#include "Configuration.hpp"
#include <iostream>

int main() {
	Configuration config;
	float threshold;
	bool success;
	
	//test set Ignition threshold 10.25
	threshold = 10.25;
	config.setIgnitionThreshold(threshold);
	success = threshold == config.getIgnitionThreshold();
	if(!success) {
		std::cout << "Failed to set Ignition Threshold" << std::endl;
		return 1;
	}
	
	//test set ignition 83
	threshold = 83;
	config.setIgnitionThreshold(threshold);
	success = threshold == config.getIgnitionThreshold();
	if(!success) {
		std::cout << "Failed to set Ignition Threshold" << std::endl;
		return 1;
	}
	
	//test set cutoff threshold 6.5
	threshold = 6.5;
	config.setCutoffThreshold(threshold);
	success = threshold == config.getCutoffThreshold();
	if(!success) {
		std::cout << "Failed to set Cutoff Threshold" << std::endl;
		return 1;
	}
	
	//test set cutoff threshold 946
	threshold = 946;
	config.setCutoffThreshold(threshold);
	success = threshold == config.getCutoffThreshold();
	if(!success) {
		std::cout << "Failed to set Cutoff Threshold" << std::endl;
		return 1;
	}
	
	//SUCCESS
	return 0;
}
