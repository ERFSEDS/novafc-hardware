#include "Configuration.hpp"
#include "StateMachine.hpp"
#include "MessageHandler.hpp"
int main() {
	uint8_t messageOutput[22] = {1, 16, 0, 1, 1, 56, 2, 4, 0, 1, 7, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 2};// get RotationX	set altitude 0	arm Rocket
	MessageHandler::parseMessage(messageOutput, 22);
	return 1;//I wanna see the output
	

}
