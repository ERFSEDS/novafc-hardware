#include "Configuration.hpp"
#include <iostream>

bool testSet(int index, 
			 PyroConfig configOne, float valueOne,
			 PyroConfig configTwo, float valueTwo);
bool testSetAll(Pyro pyroArray[]);

int main() {
	PyroConfig configOne, configTwo;
	float valueOne, valueTwo;
	int index;
	bool success;
	//test set Pyro 0 VELOCITY_ABOVE 10

	configOne = VELOCITY_ABOVE;
	valueOne = 10;
	configTwo = VELOCITY_BELOW;
	valueTwo = 50;
	index = 0;
	success = testSet(index, configOne, valueOne, configTwo, valueTwo);
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
    success = testSet(index, configOne, valueOne, configTwo, valueTwo);
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
    success = testSet(index, configOne, valueOne, configTwo, valueTwo);
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
    success = testSet(index, configOne, valueOne, configTwo, valueTwo);
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
    success = testSet(index, configOne, valueOne, configTwo, valueTwo);
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
    success = testSet(index, configOne, valueOne, configTwo, valueTwo);
    if( !success ) {
        std::cout << "FAILED to set pyro " << index << std::endl;
        return 1;
    }

	//test get all pyros

	Pyro pyroOne = {ALTITUDE_ABOVE, 61.2, ALTITUDE_BELOW, 45};
	Pyro pyroTwo = {VELOCITY_ABOVE, 41.7, NONE, 21};

	Pyro pyroThree = {TIME_DELAY, 10, ACCELERATION_ABOVE, 10};
	Pyro pyroArray[] = {pyroOne, pyroTwo, pyroThree};
	success = testSetAll( pyroArray);
	if (!success) {
		std::cout << "FAILED to set all" << std::endl;
	}
	//test get out of range
	

	//return success
	return 0;

}


bool testSet(int index,
             PyroConfig configOne, float valueOne,
             PyroConfig configTwo, float valueTwo) {
	Pyro pyroSet = {configOne, valueOne, configTwo, valueTwo};
    Configuration::setPyro(index, configOne, valueOne, configTwo, valueTwo);
    Pyro pyroGet = *(Configuration::getPyro(index));
    if( pyroSet == pyroGet ) {
        return true;
    }
	return false;
}

bool testSetAll(Pyro pyros[]) {
	for(int i = 0; i < NUMBER_OF_PYROS; i++) {
		Configuration::setPyro(i, pyros[i]);
	}
	Pyro *getPyros = Configuration::getAllPyros();
	
	bool success = true;
	for(int i = 0; i < NUMBER_OF_PYROS; i++) {
		if ( !(getPyros[i] == pyros[i]) ) {
			success = false;
			break;
		}
	}
	return success;
}
