//These are the function types that are expected to be passed into the top layer for setup and control

//this operated on function pointers that are called when the top layer needs to interact with the low layer. you could just pass void pointers but then that section of the code will not work
#pragma once
#include <cinttypes>
#include "Logger.hpp"
#include "Brain.hpp"
#include "Cartesian.hpp"
#include "RocketData.hpp"
#include "SensorValues.hpp"
#include "StateMachine.hpp"
#include "MessageHandler.hpp"

class RocketLayer {

	public:
  RocketLayer(void (*arm_callback)(void*, bool), void *armContext,
	      void (*fire_callback)(void*, int), void *fireContext,
	      void (*flash_write_callback)(void*, std::string), void * writeContext,
	      void (*transmit_callback)(void*, std::string), void *transmitContext,
	      uint8_t * configurationBytes, float upperTimeStep,
	      Cartesian startGravity, float groundPressure);
					
		~RocketLayer();
		
		State getState();
  void handleMessage(uint8_t * msg, size_t size);
		void updateAcceleration(Cartesian acceleration); //meters per second^2
		void updateRotation(Cartesian rotation); //radians per second
		void updatePressure(float presssure); //[insert pressure units]
		void update();
private:
  SensorValues sensors;
  Configuration config;
  RocketData data;
  StateMachine stateMachine;
  Brain brain;
  Logger logger;
  MessageHandler parser;
};
