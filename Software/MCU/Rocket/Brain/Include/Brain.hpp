#pragma once

#include "cartesian.h"
#include "Configuration.hpp"
#include "RocketData.h"
#include "SensorValues.h"
#include "StateMachine.hpp"
#define ARM_CALLBACK 			void (*arm_callback)(void *, bool) 	
#define FIRE_CALLBACK 			void (*fire_callback)(void *, int) 	

#define APOGEE_DESCENT_DETECT_TIME 0.5
#define IGNITION_DETECT_TIME 0.25
#define CUTOFF_DETECT_TIME 0.25
#define LANDED_DETECTION_TIME 10
#define LANDED_ALTITUDE 5

class Brain {
	public:
		Brain(Configuration& config, StateMachine& state, RocketData& rocket, SensorValues& sensor, ARM_CALLBACK, void* armContext, FIRE_CALLBACK, void* fireContext);
  void check();
		void arm();
		void disarm();
	
		void updateConfigValues();
	private:
		Configuration& config;
		StateMachine& state;
		RocketData& rocket;
		SensorValues& sensors;
		ARM_CALLBACK;
		void* armContext;
		FIRE_CALLBACK;
		void* fireContext;
		//checks if the motor ignited
		bool motorIgnition();
		//checks if the motor has cutoff
		bool motorCutoff();
		
		//Checks for apogee and sets postApogee
		void checkApogee();
		
		//checks and if neccessary fires pyros
		bool checkPyros();
		
		//check if landed
		bool checkLanded();
		
		//checks a pyro case
		bool checkPyroCase(Pyro pyro, int casen );
		
		//handles all state changes
		void hangleStateChange();
		
		
		bool postApogee;
		
		float pastAltitude;
		int descentTimeSteps;
		int requiredTimeSteps;
		
		int delayPyroCharge[NUMBER_OF_PYROS];
		bool counting[NUMBER_OF_PYROS];
		bool hasFired[NUMBER_OF_PYROS];
		
		float cutoffThreshold;
		int cutoffCountdown;
		int cutoffCountdownStart;
		
		float ignitionThreshold;
		int ignitionCountdown;
		int ignitionCountdownStart;
		
		int landedCountdown;
		int landedCountdownStart;
		
		State lastState;
};

