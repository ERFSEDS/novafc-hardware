#include "Configuration.hpp"
#include "Common.hpp"
bool Configuration::getTwoStageRocket() {
	return this->twoStageRocket;
}
void Configuration::setTwoStageRocket(bool twoStage) {
	this->twoStageRocket = twoStage;
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


float Configuration::getUpperTimeStepms() {
	return this->uppertimeStepms;
}
void Configuration::setUpperTimeStepms(float newTimeStep) {
	this->uppertimeStepms = newTimeStep;
}


void Configuration::setToDefault() {
	this->twoStageRocket = DEFAULT_TWO_STAGE_ROCKET;
	        
	this->safetyLockValue = DEFAULT_SAFETY_LOCK_VALUE;
		
	this->pyroChannels[NUMBER_OF_PYROS];
	for(int i = 0; i < NUMBER_OF_PYROS; i++) {
		this->pyroChannels[i] = {
		DEFAULT_PYRO_CONFIG, DEFAULT_PYRO_VALUE, 
		DEFAULT_PYRO_CONFIG, DEFAULT_PYRO_VALUE};
	}
		
	this->ignitionThreshold = DEFAULT_IGNITION_THRESHOLD;
	this->cutoffThreshold = DEFAULT_CUTOFF_THRESHOLD;
		
	this->loggingRates = {	DEFAULT_ASCENT_LOG_RATE,
				DEFAULT_DESCENT_LOG_RATE,};
		
	this->altitudeDetermination = DEFAULT_ALTITUDE_DETERMINATION;
		
	this->armingAltitude = DEFAULT_ARMING_ALTITUDE;
	        
	        
	
	this->uppertimeStepms = DEFAULT_UPPER_TIME_STEP_MS;
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

void Configuration::generateConfig(uint8_t * buffer) {
  //mem map
  // 0 twoStageRocket, bool
  // 1-4 safetyLockValue, float
  // pyro 0
  // 5 configOne, PyroConfig
  // 6-9 valueOne, float
  // 10 configTwo, PyroConfig
  // 11-14 valueTwo, float
  // 15 tiltLock
  // pyro 1
  // 16 configOne, PyroConfig
  // 17-20 valueOne, float
  // 21 configTwo, PyroConfig
  // 22-25 valueTwo, float
  // 26 tiltLock
  // pyro 2
  // 27 configOne, PyroConfig
  // 28-31 valueOne, float
  // 32 configTwo, PyroConfig
  // 33-36 valueTwo, float
  // 37 tiltLock
  // 38-41 ignitionThreshold
  // 42-45 cutoffThreshold
  // Logging rates
  // 46-49 ascentLoggingRates
  // 50-53 descentLoggingRates
  // 54 AltitudeDetermination
  // 55-58 armingAltitude
  // 59-62 upperTimeStepMS

  buffer[0] = (uint8_t)(twoStageRocket);
  
  setFloat(safetyLockValue, buffer, 1);
  buffer[5] = (uint8_t)(pyroChannels[0].configOne);
  setFloat(pyroChannels[0].valueOne, buffer, 6);
  buffer[10] = (uint8_t)(pyroChannels[0].configTwo);
  setFloat(pyroChannels[0].valueTwo, buffer, 11);
  buffer[15] = (uint8_t)(pyroChannels[0].tiltLock);

  
  buffer[16] = (uint8_t)(pyroChannels[1].configOne);
  setFloat(pyroChannels[1].valueOne, buffer, 17);
  buffer[21] = (uint8_t)(pyroChannels[1].configTwo);
  setFloat(pyroChannels[1].valueTwo, buffer, 22);
  buffer[26] = (uint8_t)(pyroChannels[1].tiltLock);
  
  buffer[27] = (uint8_t)(pyroChannels[2].configOne);
  setFloat(pyroChannels[2].valueOne, buffer, 28);
  buffer[32] = (uint8_t)(pyroChannels[2].configTwo);
  setFloat(pyroChannels[2].valueTwo, buffer, 33);
  buffer[37] = (uint8_t)(pyroChannels[2].tiltLock);

  setFloat(ignitionThreshold, buffer, 38);
  setFloat(cutoffThreshold, buffer, 42);

  setFloat(loggingRates.ascent, buffer, 46);
  setFloat(loggingRates.descent, buffer, 50);

  buffer[54] = (uint8_t)(altitudeDetermination);

  setFloat(armingAltitude, buffer, 55);
  setFloat(uppertimeStepms, buffer, 59);
}

void Configuration::updateFromConfig(uint8_t * buffer) {
  //mem map
  // 0 twoStageRocket, bool
  // 1-4 safetyLockValue, float
  // pyro 0
  // 5 configOne, PyroConfig
  // 6-9 valueOne, float
  // 10 configTwo, PyroConfig
  // 11-14 valueTwo, float
  // 15 tiltLock
  // pyro 1
  // 16 configOne, PyroConfig
  // 17-20 valueOne, float
  // 21 configTwo, PyroConfig
  // 22-25 valueTwo, float
  // 26 tiltLock
  // pyro 2
  // 27 configOne, PyroConfig
  // 28-31 valueOne, float
  // 32 configTwo, PyroConfig
  // 33-36 valueTwo, float
  // 37 tiltLock
  // 38-41 ignitionThreshold
  // 42-45 cutoffThreshold
  // Logging rates
  // 46-49 ascentLoggingRates
  // 50-53 descentLoggingRates
  // 54 AltitudeDetermination
  // 55-58 armingAltitude
  // 59-62 upperTimeStepMS

  twoStageRocket = (bool)(buffer[0]);
  
  safetyLockValue = getFloat(buffer,1);

  pyroChannels[0].configOne = (PyroConfig)(buffer[5]);
  pyroChannels[0].valueOne = getFloat(buffer, 6);
  pyroChannels[0].configTwo = (PyroConfig)(buffer[10]);
  pyroChannels[0].valueTwo = getFloat(buffer, 11);
  pyroChannels[0].tiltLock = (bool)(buffer[15]);

  pyroChannels[1].configOne = (PyroConfig)(buffer[16]);
  pyroChannels[1].valueOne = getFloat(buffer, 17);
  pyroChannels[1].configTwo = (PyroConfig)(buffer[21]);
  pyroChannels[1].valueTwo = getFloat(buffer, 22);
  pyroChannels[1].tiltLock = (bool)(buffer[26]);

  pyroChannels[2].configOne = (PyroConfig)(buffer[27]);
  pyroChannels[2].valueOne = getFloat(buffer, 28);
  pyroChannels[2].configTwo = (PyroConfig)(buffer[32]);
  pyroChannels[2].valueTwo = getFloat(buffer, 33);
  pyroChannels[2].tiltLock = (bool)(buffer[37]);

  ignitionThreshold = getFloat(buffer, 38);
  cutoffThreshold = getFloat(buffer, 42);

  loggingRates.ascent = getFloat(buffer, 46);
  loggingRates.descent = getFloat(buffer, 50);

  altitudeDetermination = (AltitudeDeterminination)(buffer[54]);

  armingAltitude = getFloat(buffer, 55);
  uppertimeStepms = getFloat(buffer, 59);

}
