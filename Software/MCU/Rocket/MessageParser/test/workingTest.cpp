#include "Configuration.hpp"
#include "StateMachine.hpp"
#include "MessageHandler.hpp"
#include <iostream>

int main() {
	uint8_t messageOutput[22] = {1, 16, 0, 1, 1, 56, 2, 4, 0, 1, 7, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 2};// get RotationX	set altitude 0	arm Rocket
	
	uint8_t * responseBuffer = new uint8_t[BUFFER_SIZE * 2];
	
	uint16_t size = MessageHandler::parseMessage(messageOutput, 22, responseBuffer);
	
	std::cout << "Response: <";
	for(int i = 0; i < (int)size; i++) {
		std::cout << (int)responseBuffer[i] << ", " ;
	}
	std::cout << ">" << std::endl;
	return 1;//I wanna see the output
	

}
