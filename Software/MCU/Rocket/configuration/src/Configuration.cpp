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
Pyro Configuration::getPyro(int pyroNum) {
	if( (pyroNum<0) ) {
		return this->pyroChannels[0];
	}
	else if(pyroNum>=NUMBER_OF_PYROS) {
		return this->pyroChannels[NUMBER_OF_PYROS-1];
	}
	return this->pyroChannels[pyroNum];
}

Pyro* Configuration::getAllPyros() {
	return this->pyroChannels;
}
