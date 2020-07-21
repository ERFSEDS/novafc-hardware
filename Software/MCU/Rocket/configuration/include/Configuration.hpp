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

class Configuration {	
	public:
		bool getTwoStageRocket();
		void setTwoStageRocket(bool twoStage);

		bool getSafetyLock();
		void setSafetyLock(bool safetyLock);

		void setPyro(int pyroNum, Pyro& pyro);
		void setPyro(int pyroNum, 
					 PyroConfig& configOne, float& valueOne,
					 PyroConfig& configTwo, float& valueTwo);
		void setPyro(int pyroNum, int pyroConfigNum,
					 PyroConfig& config, float& value);
		Pyro getPyro(int pyroNum);	
		Pyro*  getAllPyros();

	private:
		bool twoStageRocket;
		bool safetyLock;
		Pyro pyroChannels[NUMBER_OF_PYROS];
		
};
