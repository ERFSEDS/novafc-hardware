#pragma once
#include "CommonDefines.hpp"
#include <cinttypes>
//A bunch of defualt defines

#define DEFAULT_TWO_STAGE_ROCKET			(true)
#define DEFAULT_SAFETY_LOCK					(true)
#define DEFAULT_SAFETY_LOCK_VALUE			(15)
#define DEFAULT_PYRO_CONFIG					(NONE)	
#define DEFAULT_PYRO_VALUE					(0)
#define DEFAULT_IGNITION_THRESHOLD			(50)
#define DEFAULT_CUTOFF_THRESHOLD			(20)
#define DEFAULT_ASCENT_LOG_RATE		(50)
#define DEFAULT_DESCENT_LOG_RATE	(50)
#define DEFAULT_ALTITUDE_DETERMINATION		(BOTH)
#define DEFAULT_ARMING_ALTITUDE				(50)
#define DEFAULT_DROGUE_CHUTE				(true)
#define DEFAULT_MAIN_PYRO_CHANNEL			(0)
#define DEFAULT_DROGUE_PYRO_CHANNEL			(1)
#define DEFAULT_UPPER_TIME_STEP_MS			(20) //50Hz
#define DEFAULT_LOWER_TIME_STEP_MS			(20) //50Hz
#define DEFAULT_MODE_TEST                               (false)

#define CONFIG_BUFFER_SIZE    (63)

enum PyroConfig {
		 VELOCITY_ABOVE = 0,
		 VELOCITY_BELOW = 1,
		 ACCELERATION_BELOW = 2,
		 ACCELERATION_ABOVE = 3,
		 ALTITUDE_ABOVE = 4,
		 ALTITUDE_BELOW = 5,
		 TIME_DELAY = 6,
		 PAST_APOGEE = 7,
		 STATE = 8,//value is state desired(it will be cast to int)
		 NONE = 9,	//this condition is always met
		 NO_FIRE = 10//this condition is never met
};
enum AltitudeDeterminination {
	ACCELEROMETER_ONLY=0,
	BAROMETER_ONLY=1,
	BOTH=2
};
struct Pyro {
	PyroConfig configOne;
	float valueOne;
	PyroConfig configTwo;
	float valueTwo;
	bool tiltLock;
	
	bool operator==(const Pyro& pyro){
	  if ( (configOne == pyro.configOne) &&
	       (valueOne == pyro.valueOne) &&
	       (configTwo == pyro.configTwo) &&
	       (valueTwo == pyro.valueTwo) &&
	       (tiltLock == pyro.tiltLock)) {
	    return true;
	  }
	  return false;
	}
};
struct LoggingRates {
  float ascent;
  float descent;
	
  bool operator==(const LoggingRates& rates){
    if (	 (ascent == rates.ascent) &&
		 (descent == rates.descent)) {
      return true;
    }
    return false;
  }
};

class Configuration {	
	public:		
		Configuration();
		
		~Configuration();

		void setToDefault();
		bool getTwoStageRocket();
		void setTwoStageRocket(bool twoStage);

		float getSafetyLockValue();						
		void setSafetyLockValue(float safetyLockValue); 

		void setPyro(int pyroNum, Pyro pyro);
		void setPyro(int pyroNum, bool tiltLock,
					 PyroConfig configOne, float valueOne,
					 PyroConfig configTwo, float valueTwo);
		void setPyro(int pyroNum, int pyroConfigNum,
					 PyroConfig config, float value);
		Pyro* getPyro(int pyroNum);	
		Pyro* getAllPyros();
		
		float getIgnitionThreshold();
		void setIgnitionThreshold(float ignitionThreshold);
		float getCutoffThreshold();
		void setCutoffThreshold(float cutoffThreshold);

		LoggingRates* getLoggingRates(); 
		void setLoggingRates(LoggingRates logRates);
		
		AltitudeDeterminination getAltitudeDetermination();
		void setAltitudeDetermination(AltitudeDeterminination determination);
		
		float getArmingAltitude();
		void setArmingAltitude(float altitude);
				
		float getUpperTimeStepms(); //miliseconds
		void setUpperTimeStepms(float newTimeStep); //miliseconds
		
  bool getTest();
  void setTest(bool test);

  void generateConfig(uint8_t * buffer);
  void updateFromConfig(uint8_t* buffer);
	//Private Variables
	private:
  bool twoStageRocket;
		
		float safetyLockValue;
		
		Pyro pyroChannels[NUMBER_OF_PYROS];
		
		float ignitionThreshold;
		float cutoffThreshold;
		
		LoggingRates loggingRates;
		
		AltitudeDeterminination altitudeDetermination;
		
		float armingAltitude;
				
		float uppertimeStepms; //miliseconds
                bool test;
};
