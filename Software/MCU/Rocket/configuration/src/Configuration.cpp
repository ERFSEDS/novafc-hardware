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
void Configuration::setPyro(int pyroNum, Pyro pyro) {
	if( (pyroNum<0) || (pyroNum>=NUMBER_OF_PYROS) ) {
		return;
	}
	this->pyroChannels[pyroNum]=pyro;
}
void Configuration::setPyro(int pyroNum, int pyroConfigNum, PyroConfig config, float value) {
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
void Configuration::setPyro(int pyroNum, bool tiltLock,
							PyroConfig configOne, float valueOne,
							PyroConfig configTwo, float valueTwo) {
	if( (pyroNum<0) || (pyroNum>=NUMBER_OF_PYROS) ) {
   		return;
   	}
	this->pyroChannels[pyroNum].configOne = configOne;
	this->pyroChannels[pyroNum].valueOne = valueOne;
	this->pyroChannels[pyroNum].configTwo = configTwo;
	this->pyroChannels[pyroNum].valueTwo = valueTwo;
	this->pyroChannels[pyroNum].tiltLock = tiltLock;

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

float Configuration::getUpperTimeStepms() {
	return this->uppertimeStepms;
}
void Configuration::setUpperTimeStepms(float newTimeStep) {
	this->uppertimeStepms = newTimeStep;
}
	
float Configuration::getLowerTimeStepms() {
	return this->lowertimeStepms;
}
void Configuration::setLowerTimeStepms(float newTimeStep) {
	this->lowertimeStepms = newTimeStep;
}


void Configuration::setToDefault() {
	this->twoStageRocket = DEFAULT_TWO_STAGE_ROCKET;
		
	this->safetyLock = DEFAULT_SAFETY_LOCK;
	this->safetyLockValue = DEFAULT_SAFETY_LOCK_VALUE;
		
	this->pyroChannels[NUMBER_OF_PYROS];
	for(int i = 0; i < NUMBER_OF_PYROS; i++) {
		this->pyroChannels[i] = {
		DEFAULT_PYRO_CONFIG, DEFAULT_PYRO_VALUE, 
		DEFAULT_PYRO_CONFIG, DEFAULT_PYRO_VALUE};
	}
		
	this->ignitionThreshold = DEFAULT_IGNITION_THRESHOLD;
	this->cutoffThreshold = DEFAULT_CUTOFF_THRESHOLD;
		
	this->loggingRates = {	DEFAULT_PRE_LAUNCH_LOG_RATE, 
							DEFAULT_POWERED_FLIGHT_LOG_RATE,
							DEFAULT_UNPOWERED_FLIGHT_LOG_RATE,
							DEFAULT_DESCENT_LOG_RATE};
		
	this->altitudeDetermination = DEFAULT_ALTITUDE_DETERMINATION;
		
	this->armingAltitude = DEFAULT_ARMING_ALTITUDE;
		
	this->drogueChute = DEFAULT_DROGUE_CHUTE;
		
	this->mainPyroChannel = DEFAULT_MAIN_PYRO_CHANNEL;
	this->droguePyroChannel = DEFAULT_DROGUE_PYRO_CHANNEL;
	
	this->uppertimeStepms = DEFAULT_UPPER_TIME_STEP_MS;
	this->lowertimeStepms = DEFAULT_LOWER_TIME_STEP_MS;
	this->test = DEFAULT_MODE_TEST;
}

Configuration::Configuration() {
	setToDefault();
}

Configuration::~Configuration() {
	//should never get here
}


bool Configuration::getTest() {
  return this->test;
}

void Configuration::setTest( bool test) {
  this->test = test;
}
