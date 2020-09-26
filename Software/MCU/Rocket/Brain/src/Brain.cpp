
#include "Brain.hpp"
#include "StateMachine.hpp"
#include "RocketData.h"
#include "SensorValues.h"
#include "Logger.hpp"

//Needed Instances
SensorValues * Brain::sensor = SensorValues::getInstance();
RocketData * Brain::rocket = RocketData();
void Brain::check() {
	bool stateChange = StateMachine::getCurrentState() == lastState;
	hangleStateChange();
	
	switch(StateMachine::getCurrentState()) {
	case UNARMED:
		//TODO impliment arm checker(either sensor values read or vertical)
		break;
	case READY:
		if(motorIgnition()) {
			//IGNITION
			StateMachine::changeState(STAGE1POWERED);
		}
		else {
			//TODO Watch for disarming 
		}
		break;
	case STAGE1POWERED:
		if(motorCutoff()) {
			StateMachine::changeState(STAGE1COAST);
		}
		break;
	case STAGE1COAST:
		if(Configuration::getTwoStageRocket() ) {
			if(motorIgnition()) {
				StateMachine::changeState(STAGE1COAST);	
			}
		}
		else {
			StateMachine::changeState(STAGE1POWERED);
		}
		checkPyros();
		break;
	case STAGE2POWERED:
		if(motorCutoff()) {
		StateMachine::changeState(STAGE1POWERED);
		}
	case STAGE2COAST:
	case DROGUEPAR:
	case MAINPAR:
		checkPyros();
		break;
	case LANDED:
	case RESET:
		break;
	}
	lastState = StateMachine::getCurrentState();
}
//handles all state changes
void Brain::hangleStateChange() {
	State cState = StateMachine::getCurrentState();
	State pState = StateMachine::getPreviousState();
	
	switch(cstate) {
	case UNARMED:
		if(pstate == READY) {
			LOGGER::EVENT("ROCKET DISARMED");
		}
		else {//shrug
		}
	case READY:
		if(pstate == UNARMED) {
			LOGGER::EVENT("ROCKET READY");
			//TODO arm
		}
		else {//shrug
		}
	case STAGE1POWERED:
		if(pstate == READY) {
			LOGGER::EVENT("STAGE 1 IGNITION");
		}
		else {//shrug
		}
	case STAGE1COAST:
		if(pstate == STAGE1POWERED) {
			LOGGER::EVENT("STAGE 1 MECO");
		}
		else {//shrug
		}
	case STAGE2POWERED:
		if(pstate == STAGE1COAST) {
			LOGGER::EVENT("STAGE 2 IGNITION");
		}
		else {//shrug
		}
	case STAGE2COAST:
		if(pstate == STAGE2POWERED) {
			LOGGER::EVENT("STAGE 2 MECO");
		}
		else {//shrug
		}
	case DROGUEPAR:
		if(pstate == STAGE1COAST) {
			LOGGER::EVENT("Drogue Deployed");
		}
		else if(pstate == STAGE2COAST) {
			LOGGER::EVENT("Drogue Deployed");
		}
		else {//shrug
		}
	case MAINPAR:
		if(pstate == STAGE1COAST) {
			LOGGER::EVENT("Main Chute Deployed");
		}
		else if(pstate == STAGE2COAST) {
			LOGGER::EVENT("Main Chute Deployed");
		}
		else if(pstate == DROGUEPAR) {
			LOGGER::EVENT("Main Chute Deployed");
		}
		else {//shrug
		}
	case LANDED:
		if(pstate == MAINPAR) {
			LOGGER::EVENT("SUCCESSFUL LANDING");
			//TODO copy flash to SD
		}
		else {//shrug
		}
	case RESET:
		if(pstate == LANDED) {
			LOGGER::EVENT("RESETTING");
		}
		else {//shrug
		}
	}
}
void Brain::arm() {
	if(StateMachine::getCurrentState() == UNARMED) {
		StateMachine::changeState(READY);
		Logger::EVENT("Rocket Disarmed");
	}
}
void Brain::disarm() {
	if(StateMachine::getCurrentState() == READY) {
		StateMachine::changeState(UNARMED);
		Logger::EVENT("Rocket Disarmed");
	}
}

bool Brain::motorIgnition() {
	float acceleration = rocket->getAcceleration().magnitude();
	if (acceleration > ignitionThreshold) {
		ignitionCountdown--;
		if(ignitionCountdown) {
			return true;
		}
	}
	else {
		ignitionCountdown = ignitionCountdownStart;
	}
	return false;

}
bool Brain::motorCutoff() {
	float acceleration = rocket->getAcceleration().magnitude();
	if (acceleration < cutoffThreshold) {
		cutoffCountdown--;
		if(cutoffCountdown) {
			return true;
		}
	}
	else {
		cutoffCountdown = cutoffCountdownStart;
	}
	return false;
}


bool Brain::checkApogee() {
	float currentAltitude = rocket.getDisplacement().dimension[3];
	if( currentAltitude <= pastAltitude ) {
		descentTimeSteps++;
		if(descentTimeSteps >= requiredTimeSteps) {
			postAgogee = true;
		}
	}
	else {
		descentTimeSteps = 0;
	}
}
		
void Brain::updateConfigValues() {
	float stepHz = 1000.0/( (float)Configuration::getUpperTimeStepms ) 
	requiredTimeSteps = stepHz * APOGEE_DESCENT_DETECT_TIME;
	
	cutoffThreshold = Configuration::getCutoffThreshold();
	ignitionThreshold = Configuration::getIgnitionThreshold();
	
	cutoffCountdownStart = (int)( stepHz * CUTOFF_DETECT_TIME );
	cutoffCountdown = cutoffCountdownStart;
	ignitionCountdownStart = (int)( stepHz * IGNITION_DETECT_TIME );
	ignitionCountdown = ignitionCountdownStart;
	for(int i = 0; i < NUMBER_OF_PYROS; i++) {	
		PyroConfig configOne = Configuration::getPyro(i).configOne;
		PyroConfig configTwo = Configuration::getPyro(i).configTwo;
		if( configOne == TIME_DELAY ) {
			delayPyroCharge[i] = (int)(stepHz) * Configuration::getPyro(i).valueOne);
			counting[i] = false;
		}
		else if( configTwo == TIME_DELAY ) {
			delayPyroCharge[i] = (int)( stepHz ) * Configuration::getPyro(i).valueTwo);
			counting[i] = false;
		}
		else {
			delayPyroCharge[i] = 0;
			counting[i] = false;
		}
	}
}

//checks and if neccessary fires pyros
void Brain::checkPyros() {
	for(int i = 0; i < NUMBER_OF_PYROS; i++) {
		Pyro pyro = Configuration::getPyro(i);
		bool caseOneMet = checkPyroCase(pyro, 1);
		bool caseTwoMet = checkPyroCase(pyro, 2);
		

		if(caseOneMet && caseTwoMet) {
			//Cases are met, begin the countdown
			counting[i] = true;
		}
		
		if(counting[i] == true) {
			if(delayPyroCharge[i] == 0) {
				LOGGER::EVENT("FIRE PYRO " + std::to_string(i));
				sensor->firePyro(i); //FIRE THE PYRO
			}
			else {
				delayPyroCharge[i]--; //waaaaaaaait
			}
		}
	}	
}

		
bool Brain::checkPyroCase(Pyro pyro, int caseN ) {
	PyroConfig config;
	float value;
	if( caseN == 1) {
		config = pyro.configOne;
		value = pyro.valueOne;
	}
	else {
		config = pyro.configTwo;
		value = pyro.valueTwo;
	
	}
	switch(config) {
	case VELOCITY_ABOVE:
		//no velocity variable
		break;	
	case VELOCITY_BELOW:
		//no velocity variable
		break;	
	case ACCELERATION_BELOW:
		float acceleration = rocket->getAcceleration().magnitude();
		if (acceleration < value ) {
			return true;
		}
		else {
			return false;
		}
	case ACCELERATION_ABOVE:
		float altitude = rocket->getDisplacement().dimension[3];
		if( altitude > value ) {
			return true;
		} 
		else {
			return false;
		}
	case ALTITUDE_ABOVE:
		float altitude = rocket->getDisplacement().dimension[3];
		if( altitude > value ) {
			return true;
		} 
		else {
			return false;
		}
	case ALTITUDE_BELOW:
		float altitude = rocket->getDisplacement().dimension[3];
		if( altitude < value ) {
			return true;
		} 
		else {
			return false;
		}	
	case TIME_DELAY://treat time_delay like none, it is implimented elsewhere
	case NONE:
		return true;
	default:
		return false;
	}
}
