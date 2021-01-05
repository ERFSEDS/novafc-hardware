#include "Configuration.hpp"
#include <iostream>

bool testSet(int index,  bool tiltLock,
			 PyroConfig configOne, float valueOne,
			 PyroConfig configTwo, float valueTwo, Configuration config);
bool testSetAll(Pyro pyroArray[], Configuration config);

int main() {
	Configuration config;
	PyroConfig configOne, configTwo;
	float valueOne, valueTwo;
	int index;
	bool tiltLock, success;
	//test set Pyro 0 VELOCITY_ABOVE 10

	configOne = VELOCITY_ABOVE;
	valueOne = 10;
	configTwo = VELOCITY_BELOW;
	valueTwo = 50;
	index = 0;
	tiltLock = true;
	success = testSet(index, tiltLock, configOne, valueOne, configTwo, valueTwo,config);
	if( !success ) {
		std::cout << "FAILED to set pyro " << index << std::endl;
		return 1;
	}

	//test set Pyro 0 DELAY 3

	configOne = TIME_DELAY;
    valueOne = 2.5;
    configTwo = ALTITUDE_ABOVE;
    valueTwo = 20;
    index = 0;
	tiltLock = false;
	success = testSet(index, tiltLock, configOne, valueOne, configTwo, valueTwo, config);
    if( !success ) {
        std::cout << "FAILED to set pyro " << index << std::endl;
        return 1;
    }


	//test set Pyro 1 VELOCITY_BELOW 1000
	
	configOne = VELOCITY_BELOW;
    valueOne = 165;
    configTwo = TIME_DELAY;
    valueTwo = 2.3;
    index = 1;
	tiltLock = true;
	success = testSet(index, tiltLock, configOne, valueOne, configTwo, valueTwo,config);
    if( !success ) {
        std::cout << "FAILED to set pyro " << index << std::endl;
        return 1;
    }

	//test set Pyro 1 ACCELERATION_BELOW 10

	configOne = ACCELERATION_BELOW;
    valueOne = 10;
    configTwo = ACCELERATION_ABOVE;
    valueTwo = 256;
    index = 1;
	tiltLock = false;
	success = testSet(index, tiltLock, configOne, valueOne, configTwo, valueTwo, config);
    if( !success ) {
        std::cout << "FAILED to set pyro " << index << std::endl;
        return 1;
    }

	//test set Pyro 2 ACCELERATION_ABOVE 10000
	
	configOne = ACCELERATION_ABOVE;
    valueOne = 10;
    configTwo = NONE;
    valueTwo = 50;
    index = 2;
	tiltLock = true;
	success = testSet(index, tiltLock, configOne, valueOne, configTwo, valueTwo, config);
    if( !success ) {
        std::cout << "FAILED to set pyro " << index << std::endl;
        return 1;
    }

	//test set Pyro 2 ALTITUDE_ABOVE 3.25

	configOne = ALTITUDE_ABOVE;
    valueOne = 3.25;
    configTwo = NONE;
    valueTwo = 50;
    index = 0;
	tiltLock = false;
	success = testSet(index, tiltLock, configOne, valueOne, configTwo, valueTwo,config);
    if( !success ) {
        std::cout << "FAILED to set pyro " << index << std::endl;
        return 1;
    }

	//test get all pyros

	Pyro pyroOne = {ALTITUDE_ABOVE, 61.2, ALTITUDE_BELOW, 45, true};
	Pyro pyroTwo = {VELOCITY_ABOVE, 41.7, NONE, 21};

	Pyro pyroThree = {TIME_DELAY, 10, ACCELERATION_ABOVE, 10, false};
	Pyro pyroArray[] = {pyroOne, pyroTwo, pyroThree};
	success = testSetAll( pyroArray, config);
	if (!success) {
		std::cout << "FAILED to set all" << std::endl;
	}
	//test get out of range
	

	//return success
	return 0;

}


bool testSet(int index, bool tiltLock, 
             PyroConfig configOne, float valueOne,
             PyroConfig configTwo, float valueTwo, Configuration config) {
	Pyro pyroSet = {configOne, valueOne, configTwo, valueTwo, tiltLock};
    config.setPyro(index, tiltLock, configOne, valueOne, configTwo, valueTwo);
    Pyro pyroGet = *(config.getPyro(index));
    if( pyroSet == pyroGet ) {
        return true;
    }
	return false;
}

bool testSetAll(Pyro pyros[], Configuration config) {
	for(int i = 0; i < NUMBER_OF_PYROS; i++) {
		config.setPyro(i, pyros[i]);
	}
	Pyro *getPyros = config.getAllPyros();
	
	bool success = true;
	for(int i = 0; i < NUMBER_OF_PYROS; i++) {
		if ( !(getPyros[i] == pyros[i]) ) {
			success = false;
			break;
		}
	}
	return success;
}

