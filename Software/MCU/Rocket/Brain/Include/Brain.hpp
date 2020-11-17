#include "cartesian.h"
#include "Configuration.hpp"
#include "RocketData.h"
#include "SensorValues.h"
#include "StateMachine.hpp"

#define APOGEE_DESCENT_DETECT_TIME 5
#define IGNITION_DETECT_TIME 0.25
#define CUTOFF_DETECT_TIME 0.25
#define LANDED_DETECTION_TIME 10
#define LANDED_ALTITUDE 5

class Brain {
	public:
		void check();
		void arm();
		void disarm();
	
		void updateConfigValues();
	private:
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
		
		
		bool postAgogee;
		
		float pastAltitude;
		int descentTimeSteps;
		int requiredTimeSteps;
		
		int delayPyroCharge[NUMBER_OF_PYROS];
		bool counting[NUMBER_OF_PYROS];
		
		float cutoffThreshold;
		int cutoffCountdown;
		int cutoffCountdownStart;
		
		float ignitionThreshold;
		int ignitionCountdown;
		int ignitionCountdownStart;
		
		int landedCountdown;
		int landedCountdownStart;
		
		static SensorValues * sensor;
		static RocketData * rocket;
		State lastState;
};

