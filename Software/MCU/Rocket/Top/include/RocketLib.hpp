
//These are the function types that are expected to be passed into the top layer for setup and control

//this operated on function pointers that are called when the top layer needs to interact with the low layer. you could just pass void pointers but then that section of the code will not work
#define ARM_CALLBACK 			void (*arm_callback)(void) 	
#define FIRE_CALLBACK 			void (*fire_callback)(int) 	
#define FLASH_WRITE_CALLBACK 	void (*flash_write_callback)(char * msg, size_t length)
#define TRANSMIT_CALLBACK		void (*transmit)(char * msg, size_t length)

#include "Cartesian.hpp"

class RocketLayer {

	public:
		RocketLayer(ARM_CALLBACK armCallback, 
					FIRE_CALLBACK fireCallback,
					FLASH_WRITE_CALLBACK flashWriteCallback,
					TRANSMIT_CALLBACK transmitCallback);
					
		~RocketLayer();
		
		State getState();
		void handleMessage(char * msg, size_t size);
		void updateAcceleration(Cartesian acceleration); //meters per second^2
		void updateRotation(Cartesian rotation); //radians per second
		void updatePressure(float presssure); //[insert pressure units]
		void updatePyroCorrect(bool * pyros); //is each pyro correct precompiled sizeof this is expected to equal NUMBER_PYROS
		void update();
	private:
		

}
