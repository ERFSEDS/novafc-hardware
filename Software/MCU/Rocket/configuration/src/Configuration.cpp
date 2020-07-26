#include "Configuration.hpp"

bool Configuration::getTwoStageRocket() {
	return this->twoStageRocket;
}
void Configuration::setTwoStageRocket(bool twoStage) {
	this->twoStageRocket = twoStage;
}

bool Configuration::getSafetyLock() {
	return this->safetyLock;
}
void Configuration::setSafetyLock(bool safetyLock) {
	this->safetyLock = safetyLock;
}

float Configuration::getSafetyLockValue() {
	return this->safetyLockValue;
}
void Configuration::setSafetyLockValue(float safetyLockValue) {
	this->safetyLockValue = safetyLockValue;
}
void Configuration::setPyro(int pyroNum, Pyro& pyro) {
	if( (pyroNum<0) || (pyroNum>=NUMBER_OF_PYROS) ) {
		return;
	}
	this->pyroChannels[pyroNum]=pyro;
}
void Configuration::setPyro(int pyroNum, int pyroConfigNum, PyroConfig& config, float& value) {
	if( (pyroNum<0) || (pyroNum>=NUMBER_OF_PYROS) ) {
		return;
	}
	if(config == 1) {
		this->pyroChannels[pyroNum].configOne = config;
		this->pyroChannels[pyroNum].valueOne = value;
	}
	else if(config == 2) {
		this->pyroChannels[pyroNum].configTwo = config;
		this->pyroChannels[pyroNum].valueTwo = value;
	}
}
void Configuration::setPyro(int pyroNum, 
							PyroConfig& configOne, float& valueOne,
							PyroConfig& configTwo, float& valueTwo) {
	if( (pyroNum<0) || (pyroNum>=NUMBER_OF_PYROS) ) {
   		return;
   	}
	this->pyroChannels[pyroNum].configOne = configOne;
	this->pyroChannels[pyroNum].valueOne = valueOne;
	this->pyroChannels[pyroNum].configTwo = configTwo;
	this->pyroChannels[pyroNum].valueTwo = valueTwo;

}
Pyro* Configuration::getPyro(int pyroNum) {
	if( (pyroNum<0) ) {
		return &(this->pyroChannels[0]);
	}
	else if(pyroNum>=NUMBER_OF_PYROS) {
		return &(this->pyroChannels[NUMBER_OF_PYROS-1]);
	}
	return &(this->pyroChannels[pyroNum]);
}

Pyro* Configuration::getAllPyros() {
	return this->pyroChannels;
}

float Configuration::getIgnitionThreshold() {
	return this->ignitionThreshold;
}
void Configuration::setIgnitionThreshold(float ignitionThreshold) {
	this->ignitionThreshold = ignitionThreshold;
}
float Configuration::getCutoffThreshold() {
	return this->cutoffThreshold;
}
void Configuration::setCutoffThreshold(float cutoffThreshold) {
	this->cutoffThreshold = cutoffThreshold;
}

LoggingRates* Configuration::getLoggingRates() {
	return &(this->loggingRates);
}
void Configuration::setLoggingRates(LoggingRates logRates) {
	this->loggingRates = logRates;
}

AltitudeDeterminination Configuration::getAltitudeDetermination() {
	return this->altitudeDetermination;
}
void Configuration::setAltitudeDetermination(AltitudeDeterminination determination) {
	this->altitudeDetermination = determination;
}

float Configuration::getArmingAltitude() {
	return this->armingAltitude;
}
void Configuration::setArmingAltitude(float altitude) {
	this->armingAltitude = altitude;
}
		
bool Configuration::getDrogueChute() {
	return this->drogueChute;
}
void Configuration::setDrogueChute(bool drogueChute) {
	this->drogueChute = drogueChute;
}
		
int Configuration::getMainPyroChannel() {
	return this->mainPyroChannel;
}
void Configuration::setMainPyroChannel(int channel) {
	if(channel >= NUMBER_OF_PYROS) {
		channel = NUMBER_OF_PYROS - 1;
	}
	else if(channel < 0) {
		channel = 0;
	}
	this->mainPyroChannel = channel;
}
		
int Configuration::getDroguePyroChannel() {
	return this->droguePyroChannel;
}
void Configuration::setDroguePyroChannel(int channel) {
	if(channel >= NUMBER_OF_PYROS) {
		channel = NUMBER_OF_PYROS - 1;
	}
	else if(channel < 0) {
		channel = 0;
	}
	this->droguePyroChannel = channel;
}



