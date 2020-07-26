#pragma once
//This needs to be moved to top level header file
#define NUMBER_OF_PYROS 3


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
	
	bool operator==(const Pyro& pyro){
    	if ( (configOne == pyro.configOne) &&
			 (valueOne == pyro.valueOne) &&
			 (configTwo == pyro.configTwo) &&
			 (valueTwo == pyro.valueTwo) ) {
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
		bool getTwoStageRocket();
		void setTwoStageRocket(bool twoStage);

		bool getSafetyLock();
		void setSafetyLock(bool safetyLock);
		float getSafetyLockValue();						
		void setSafetyLockValue(float safetyLockValue); 

		void setPyro(int pyroNum, Pyro& pyro);
		void setPyro(int pyroNum, 
					 PyroConfig& configOne, float& valueOne,
					 PyroConfig& configTwo, float& valueTwo);
		void setPyro(int pyroNum, int pyroConfigNum,
					 PyroConfig& config, float& value);
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

	private:
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
		
};
