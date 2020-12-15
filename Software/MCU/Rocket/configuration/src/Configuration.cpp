#include "Configuration.hpp"


Configuration Configuration::INSTANCE;
bool Configuration::getTwoStageRocket_I() {
	return this->twoStageRocket;
}
void Configuration::setTwoStageRocket_I(bool twoStage) {
	this->twoStageRocket = twoStage;
}

bool Configuration::getSafetyLock_I() {
	return this->safetyLock;
}
void Configuration::setSafetyLock_I(bool safetyLock) {
	this->safetyLock = safetyLock;
}

float Configuration::getSafetyLockValue_I() {
	return this->safetyLockValue;
}
void Configuration::setSafetyLockValue_I(float safetyLockValue) {
	this->safetyLockValue = safetyLockValue;
}
void Configuration::setPyro_I(int pyroNum, Pyro pyro) {
	if( (pyroNum<0) || (pyroNum>=NUMBER_OF_PYROS) ) {
		return;
	}
	this->pyroChannels[pyroNum]=pyro;
}
void Configuration::setPyro_I(int pyroNum, int pyroConfigNum, PyroConfig config, float value) {
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
void Configuration::setPyro_I(int pyroNum, bool tiltLock,
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
Pyro* Configuration::getPyro_I(int pyroNum) {
	if( (pyroNum<0) ) {
		return &(this->pyroChannels[0]);
	}
	else if(pyroNum>=NUMBER_OF_PYROS) {
		return &(this->pyroChannels[NUMBER_OF_PYROS-1]);
	}
	return &(this->pyroChannels[pyroNum]);
}

Pyro* Configuration::getAllPyros_I() {
	return this->pyroChannels;
}

float Configuration::getIgnitionThreshold_I() {
	return this->ignitionThreshold;
}
void Configuration::setIgnitionThreshold_I(float ignitionThreshold) {
	this->ignitionThreshold = ignitionThreshold;
}
float Configuration::getCutoffThreshold_I() {
	return this->cutoffThreshold;
}
void Configuration::setCutoffThreshold_I(float cutoffThreshold) {
	this->cutoffThreshold = cutoffThreshold;
}

LoggingRates* Configuration::getLoggingRates_I() {
	return &(this->loggingRates);
}
void Configuration::setLoggingRates_I(LoggingRates logRates) {
	this->loggingRates = logRates;
}

AltitudeDeterminination Configuration::getAltitudeDetermination_I() {
	return this->altitudeDetermination;
}
void Configuration::setAltitudeDetermination_I(AltitudeDeterminination determination) {
	this->altitudeDetermination = determination;
}

float Configuration::getArmingAltitude_I() {
	return this->armingAltitude;
}
void Configuration::setArmingAltitude_I(float altitude) {
	this->armingAltitude = altitude;
}
		
bool Configuration::getDrogueChute_I() {
	return this->drogueChute;
}
void Configuration::setDrogueChute_I(bool drogueChute) {
	this->drogueChute = drogueChute;
}
		
int Configuration::getMainPyroChannel_I() {
	return this->mainPyroChannel;
}
void Configuration::setMainPyroChannel_I(int channel) {
	if(channel >= NUMBER_OF_PYROS) {
		channel = NUMBER_OF_PYROS - 1;
	}
	else if(channel < 0) {
		channel = 0;
	}
	this->mainPyroChannel = channel;
}
		
int Configuration::getDroguePyroChannel_I() {
	return this->droguePyroChannel;
}
void Configuration::setDroguePyroChannel_I(int channel) {
	if(channel >= NUMBER_OF_PYROS) {
		channel = NUMBER_OF_PYROS - 1;
	}
	else if(channel < 0) {
		channel = 0;
	}
	this->droguePyroChannel = channel;
}

int Configuration::getUpperTimeStepms_I() {
	return this->uppertimeStepms;
}
void Configuration::setUpperTimeStepms_I(int newTimeStep) {
	this->uppertimeStepms = newTimeStep;
}
	
int Configuration::getLowerTimeStepms_I() {
	return this->lowertimeStepms;
}
void Configuration::setLowerTimeStepms_I(int newTimeStep) {
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
}

Configuration &Configuration::GET_INSTANCE() {
	return INSTANCE;
}

Configuration::Configuration() {
	setToDefault();
}

Configuration::~Configuration() {
	//should never get here
}


//mapping static functions to proper
bool Configuration::getTwoStageRocket() {
	return Configuration::GET_INSTANCE().getTwoStageRocket_I();
}
void Configuration::setTwoStageRocket(bool twoStage) {
	return Configuration::GET_INSTANCE().setTwoStageRocket_I(twoStage);
}

bool Configuration::getSafetyLock() {
	return Configuration::GET_INSTANCE().getSafetyLock_I();
}
void Configuration::setSafetyLock(bool safetyLock) {
	return Configuration::GET_INSTANCE().setSafetyLock_I(safetyLock);
}
float Configuration::getSafetyLockValue() {
	return Configuration::GET_INSTANCE().getSafetyLockValue_I();
}						
void Configuration::setSafetyLockValue(float safetyLockValue) {
	Configuration::GET_INSTANCE().setSafetyLockValue_I(safetyLockValue);
} 

void Configuration::setPyro(int pyroNum, Pyro pyro) {
	Configuration::GET_INSTANCE().setPyro_I(pyroNum, pyro);
}
void Configuration::setPyro(int pyroNum, bool tiltLock,
					 PyroConfig configOne, float valueOne,
					 PyroConfig configTwo, float valueTwo) {
	Configuration::GET_INSTANCE().setPyro_I(pyroNum, tiltLock, configOne, valueOne, configTwo, valueTwo);
}
void Configuration::setPyro(int pyroNum, int pyroConfigNum,
					 PyroConfig config, float value) {
	Configuration::GET_INSTANCE().setPyro_I(pyroNum, pyroConfigNum, config, value);
}
Pyro* Configuration::getPyro(int pyroNum) {
	return Configuration::GET_INSTANCE().getPyro_I(pyroNum);
}
Pyro* Configuration::getAllPyros() {
	return Configuration::GET_INSTANCE().getAllPyros_I();
}
		
float Configuration::getIgnitionThreshold() {
	return Configuration::GET_INSTANCE().getIgnitionThreshold_I();
}
void Configuration::setIgnitionThreshold(float ignitionThreshold) {
	Configuration::GET_INSTANCE().setIgnitionThreshold_I(ignitionThreshold);
}
float Configuration::getCutoffThreshold() {
	return Configuration::GET_INSTANCE().getCutoffThreshold_I();
}
void Configuration::setCutoffThreshold(float cutoffThreshold) {
	Configuration::GET_INSTANCE().setCutoffThreshold_I(cutoffThreshold);
}

LoggingRates* Configuration::getLoggingRates() {
	return Configuration::GET_INSTANCE().getLoggingRates_I();
} 
void Configuration::setLoggingRates(LoggingRates logRates) {
	Configuration::GET_INSTANCE().setLoggingRates_I(logRates);
}
		
AltitudeDeterminination Configuration::getAltitudeDetermination() {
	return Configuration::GET_INSTANCE().getAltitudeDetermination_I();
}
void Configuration::setAltitudeDetermination(AltitudeDeterminination determination) {
	Configuration::GET_INSTANCE().setAltitudeDetermination_I(determination);
}
		
float Configuration::getArmingAltitude() {
	return Configuration::GET_INSTANCE().getArmingAltitude_I();
}
void Configuration::setArmingAltitude(float altitude) {
	Configuration::GET_INSTANCE().setArmingAltitude_I(altitude);
}
		
bool Configuration::getDrogueChute() {
	return Configuration::GET_INSTANCE().getDrogueChute_I();
}
void Configuration::setDrogueChute(bool drogueChute) {
	Configuration::GET_INSTANCE().setDrogueChute_I(drogueChute);
}
		
int Configuration::getMainPyroChannel() {
	return Configuration::GET_INSTANCE().getMainPyroChannel_I();
}
void Configuration::setMainPyroChannel(int channel) {
	Configuration::GET_INSTANCE().setMainPyroChannel_I(channel);
}
		
int Configuration::getDroguePyroChannel() {
	return Configuration::GET_INSTANCE().getDroguePyroChannel_I();
}
void Configuration::setDroguePyroChannel(int channel) {
	Configuration::GET_INSTANCE().setDroguePyroChannel_I(channel);
}

int Configuration::getUpperTimeStepms() {
	return Configuration::GET_INSTANCE().getUpperTimeStepms_I();
}
void Configuration::setUpperTimeStepms(int newTimeStep) {
	Configuration::GET_INSTANCE().setUpperTimeStepms_I(newTimeStep);
}
		
int Configuration::getLowerTimeStepms() {
	return Configuration::GET_INSTANCE().getLowerTimeStepms_I();
}
void Configuration::setLowerTimeStepms(int newTimeStep) {
	Configuration::GET_INSTANCE().setLowerTimeStepms_I(newTimeStep);
}
