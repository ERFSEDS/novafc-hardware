#include "Configuration.hpp"
#include <iostream>

int main() {
	Configuration config;
	if (config.getTwoStageRocket() != DEFAULT_TWO_STAGE_ROCKET) {
		std::cout << "Failed Two Stage Rocket" << std::endl;
		return 1;
	}

	if (config.getSafetyLock() != DEFAULT_SAFETY_LOCK) {
		std::cout << "Failed Safety Lock" << std::endl;
		return 1;
	}
	if (config.getSafetyLockValue() != DEFAULT_SAFETY_LOCK_VALUE) {
		std::cout << "Failed Safety Lock Value" << std::endl;
		return 1;
	}
	
	Pyro* pyros = config.getAllPyros();
	for(int i = 0; i < NUMBER_OF_PYROS; i++) {
		if( (pyros[i].configOne != DEFAULT_PYRO_CONFIG) ||
			(pyros[i].valueOne != DEFAULT_PYRO_VALUE) ||
			(pyros[i].configTwo != DEFAULT_PYRO_CONFIG) ||
			(pyros[i].valueTwo != DEFAULT_PYRO_VALUE) ) {
			std::cout << "Failed Pyro Config" << std::endl;
			return 1;	
		}
	}
	
	if (config.getIgnitionThreshold() != DEFAULT_IGNITION_THRESHOLD) {
		std::cout << "Failed Ignition Threshold" << std::endl;
		return 1;
	}
	if (config.getCutoffThreshold() != DEFAULT_CUTOFF_THRESHOLD) {
		std::cout << "Failed Cutoff THreshold" << std::endl;
		return 1;
	}

	LoggingRates logRates = {
							DEFAULT_PRE_LAUNCH_LOG_RATE, 
							DEFAULT_POWERED_FLIGHT_LOG_RATE,
							DEFAULT_UNPOWERED_FLIGHT_LOG_RATE,
							DEFAULT_DESCENT_LOG_RATE};
	if ( !(*config.getLoggingRates() == logRates) ){
		std::cout << "Failed Logging Rates" << std::endl;
		return 1;
	} 
		
	if(config.getAltitudeDetermination() != DEFAULT_ALTITUDE_DETERMINATION) {
		std::cout << "Failed Altitude Determination" << std::endl;
		return 1;
	}
		
	if (config.getArmingAltitude() != DEFAULT_ARMING_ALTITUDE) {
		std::cout << "Failed Arming Altitude" << std::endl;
		return 1;
	}
		
	if (config.getDrogueChute() != DEFAULT_DROGUE_CHUTE) {
		std::cout << "Failed Drogue Chute" << std::endl;
		return 1;
	}
		
	if (config.getMainPyroChannel() != DEFAULT_MAIN_PYRO_CHANNEL) {
		std::cout << "Failed Main Pyro CHannel" << std::endl;
		return 1;
	}
		
	if (config.getDroguePyroChannel() != DEFAULT_DROGUE_PYRO_CHANNEL) {
		std::cout << "Failed Drogue Pyro Channel" << std::endl;
		return 1;
	}
	if (config.getUpperTimeStepms() != DEFAULT_UPPER_TIME_STEP_MS) {
		std::cout << "Failed upper layer time" << std::endl;
		return 1;
	}
	if (config.getLowerTimeStepms() != DEFAULT_LOWER_TIME_STEP_MS) {
		std::cout << "Failed Lower Layer time" << std::endl;
		return 1;
	}
	
	return 0;
}
