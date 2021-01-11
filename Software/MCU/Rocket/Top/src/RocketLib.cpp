#include "RocketrLib.hpp"

RocketLayer(ARM_CALLBACK armCallback, 
			FIRE_CALLBACK fireCallback,
			FLASH_WRITE_CALLBACK flashWriteCallback,
			TRANSMIT_CALLBACK transmitCallback) {
					
}
					
~RocketLayer() {

}
		
State RocketLayer::getState() {

}
void RocketLayer::handleMessage(char * msg, size_t size) {

}
void RocketLayer::updateAcceleration(Cartesian acceleration) {

}
void RocketLayer::updateRotation(Cartesian rotation) {

}
void RocketLayer::updatePressure(float presssure) {

}

void RocketLayer::updatePyroCorrect(bool * pyros) {

}
