//These are the function types that are expected to be passed into the top layer for setup and control

//this operated on function pointers that are called when the top layer needs to interact with the low layer. you could just pass void pointers but then that section of the code will not work
#pragma once
//arm callback defined in Brain.hpp
//fire callback defined in Brain.hpp
//flash write callback defined in Logger.hpp
//transmit callback defined in Logger.hpp
#include "Logger.hpp"
#include "Brain.hpp"
#include "cartesian.h"
#include "RocketData.h"
#include "SensorValues.h"
#include "StateMachine.hpp"

class RocketLayer {

	public:
  RocketLayer(ARM_CALLBACK, void *armContext,
	      FIRE_CALLBACK, void *fireContext,
	      FLASH_WRITE_CALLBACK, void * writeContext,
	      TRANSMIT_CALLBACK, void *transmitContext,
	      Cartesian startGravity, float groundPressure);
					
		~RocketLayer();
		
		State getState();
		void handleMessage(char * msg, size_t size);
		void updateAcceleration(Cartesian acceleration); //meters per second^2
		void updateRotation(Cartesian rotation); //radians per second
		void updatePressure(float presssure); //[insert pressure units]
		void updatePyroCorrect(bool * pyros); //is each pyro correct precompiled sizeof this is expected to equal NUMBER_PYROS
		void update();
private:
  SensorValues sensors;
  Configuration config;
  RocketData data;
  StateMachine stateMachine;
  Brain brain;
};