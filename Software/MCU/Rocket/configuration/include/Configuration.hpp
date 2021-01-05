#pragma once
//This needs to be moved to top level header file
#define NUMBER_OF_PYROS 3
//A bunch of defualt defines

#define DEFAULT_TWO_STAGE_ROCKET			(true)
#define DEFAULT_SAFETY_LOCK					(true)
#define DEFAULT_SAFETY_LOCK_VALUE			(15)
#define DEFAULT_PYRO_CONFIG					(NONE)	
#define DEFAULT_PYRO_VALUE					(0)
#define DEFAULT_IGNITION_THRESHOLD			(50)
#define DEFAULT_CUTOFF_THRESHOLD			(20)
#define DEFAULT_PRE_LAUNCH_LOG_RATE			(0)
#define DEFAULT_POWERED_FLIGHT_LOG_RATE		(50)
#define DEFAULT_UNPOWERED_FLIGHT_LOG_RATE	(50)
#define DEFAULT_DESCENT_LOG_RATE			(1)
#define DEFAULT_ALTITUDE_DETERMINATION		(BOTH)
#define DEFAULT_ARMING_ALTITUDE				(50)
#define DEFAULT_DROGUE_CHUTE				(true)
#define DEFAULT_MAIN_PYRO_CHANNEL			(0)
#define DEFAULT_DROGUE_PYRO_CHANNEL			(1)
#define DEFAULT_UPPER_TIME_STEP_MS			(20) //50Hz
#define DEFAULT_LOWER_TIME_STEP_MS			(20) //50Hz

enum PyroConfig {
	VELOCITY_ABOVE,
	VELOCITY_BELOW,
	ACCELERATION_BELOW,
	ACCELERATION_ABOVE,
	ALTITUDE_ABOVE,
	ALTITUDE_BELOW,
	TIME_DELAY,
	NONE
};
enum AltitudeDeterminination {
	ACCELEROMETER_ONLY,
	BAROMETER_ONLY,
	BOTH
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
	float preLaunch;
	float poweredFlight;
	float unpoweredFlight;
	float descent;
	
	bool operator==(const LoggingRates& rates){
   	if ( (preLaunch == rates.preLaunch) &&
		 (poweredFlight == rates.poweredFlight) &&
		 (unpoweredFlight == rates.unpoweredFlight) &&
		 (descent == rates.descent) ) {
		return true;
	}
	
	return false;
	}
};

class Configuration {	
	public:		
		Configuration(); //constructor is private
		
		~Configuration(); //deconstructor is private

		void setToDefault();
		bool getTwoStageRocket();
		void setTwoStageRocket(bool twoStage);

		bool getSafetyLock();
		void setSafetyLock(bool safetyLock);
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
		
		bool getDrogueChute();
		void setDrogueChute(bool drogueChute);
		
		int getMainPyroChannel();
		void setMainPyroChannel(int channel);
		
		int getDroguePyroChannel();
		void setDroguePyroChannel(int channel);
		
		float getUpperTimeStepms(); //miliseconds
		void setUpperTimeStepms(float newTimeStep); //miliseconds
		
		float getLowerTimeStepms(); //miliseconds
		void setLowerTimeStepms(float newTimeStep); //miliseconds
		
	//Private Variables
	private:
		static Configuration INSTANCE;
		
		bool twoStageRocket;
		
		bool safetyLock;
		float safetyLockValue;
		
		Pyro pyroChannels[NUMBER_OF_PYROS];
		
		float ignitionThreshold;
		float cutoffThreshold;
		
		LoggingRates loggingRates;
		
		AltitudeDeterminination altitudeDetermination;
		
		float armingAltitude;
		
		bool drogueChute;
		
		int mainPyroChannel;
		int droguePyroChannel;
		
		float uppertimeStepms; //miliseconds
		float lowertimeStepms; //miliseconds
		
};
