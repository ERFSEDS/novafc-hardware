#include "Configuration.hpp"
#include "StateMachine.hpp"
#include "MessageHandler.hpp"
#include <iostream>
#include <cassert>

MessageHandler MessageHandler::INSTANCE;
void MessageHandler::parseMessage(uint8_t* message, uint16_t arraySize) {
	uint8_t * buffer = new uint8_t[BUFFER_SIZE];
	
	uint8_t bufferIndex = 0;
	uint8_t messageSize = 0;
	for(uint16_t i = 0; i < arraySize; i++) {
		if(message[i] == ESCAPE_INT) {
			//escape charachter
			i++;
			if(message[i] == 0) {
				bufferIndex++;
				break;
			}
			else if(message[i] == ESCAPE_0) {
				buffer[bufferIndex] = 0;
			}
		}
		else {
			buffer[bufferIndex] = message[i];
		}
		
		
		if(bufferIndex == BUFFER_SIZE-1) {
			delete buffer;
			return; //message too large, drop
		}
		bufferIndex++;
	}
	messageSize = bufferIndex;
	
	//check some stuff
	if(MESSAGE_VERSION != buffer[MESSAGE_VERSION_BYTE]) {
		std::cout << "Incorrect version" << std::endl;
		std::cout << "Expected: " << (int)MESSAGE_VERSION << " GOT: " << (int)buffer[MESSAGE_VERSION_BYTE] << std::endl;
		//drop message wrong message version
	}
	else if(messageSize != buffer[MESSAGE_LENGTH_BYTE]) {
		std::cout << "Incorrect message Size" << std::endl;
		std::cout << "Expected: " << (int)messageSize << " GOT: " << (int)buffer[MESSAGE_LENGTH_BYTE] << std::endl;
		//drop, message incorrect size
	} 
	else if(BOARD_TYPE != buffer[BOARD_TYPE_BYTE] ) {
		std::cout << "Incorrect Board Type" << std::endl;
		std::cout << "Expected: " << (int)BOARD_TYPE << " GOT: " << (int)buffer[BOARD_TYPE_BYTE] << std::endl;
		//drop incorrect boardType
	}
	else if( (INSTANCE.address != buffer[ADDRESS_BYTE]) 
			 && (INSTANCE.address != BROADCAST_ADDRESS) ) {
		std::cout << "Incorrect address" << std::endl;
		std::cout << "Expected: " << (int)INSTANCE.address << " GOT: " << (int)buffer[ADDRESS_BYTE] << std::endl;
		//drop, not addressed to this device
	}
	else if(COMMAND_TYPE == buffer[COMMAND_RESPONSE_BYTE]) {
		handleCommand(buffer, messageSize);
	}
	else if(RESPONSE_TYPE == buffer[COMMAND_RESPONSE_BYTE]) {
		handleResponse(buffer, messageSize);
	}
	else {
		std::cout << "Incorrect address" << std::endl;
		std::cout << "Expected: 1 || 2 GOT: " << (int)buffer[COMMAND_RESPONSE_BYTE] << std::endl;
	}
	
	delete buffer;
	return;
}
void MessageHandler::sendCommand(uint8_t* message, uint8_t size) {

}

void MessageHandler::sendMessage(uint8_t* response,  uint8_t size) {
	
}
void MessageHandler::handleCommand(uint8_t* message, uint8_t size) {
	uint8_t index = MESSAGE_DATA_START;
	uint8_t numFields = message[index++];
	
	CommandStatus fieldStatuses[numFields];
	for(int i = 0; i < numFields; i++) {
		uint8_t fieldId = message[index++];
		uint8_t setGet = message[index++];
		fieldStatuses[i].ID = fieldId;
		fieldStatuses[i].value = 0; //by default ignore
		fieldStatuses[i].size = 0; //by default ignore
		switch(fieldId) {
		case FIELD_PRESSURE:
			if(setGet == FIELD_SET) {
				std::cout << "Cannot set FIELD_PRESSURE silly " << std::endl;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Get get Pressure yet" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
		case FIELD_ACCELERATION_X:
			if(setGet == FIELD_SET) {
				std::cout << "Cannot set FIELD_ACCELERATION_X silly " << std::endl;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_ACCELERATION_X " << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
			break;
		case FIELD_ACCELERATION_Y:
			if(setGet == FIELD_SET) {
				std::cout << "Cannot set FIELD_ACCELERATION_Y silly " << std::endl;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_ACCELERATION_Y" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
			break;
		case FIELD_ACCELERATION_Z:
			if(setGet == FIELD_SET) {
				std::cout << "Cannot set FIELD_ACCELERATION_Z silly " << std::endl;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_ACCELERATION_Z" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
			break;
		case FIELD_ROTATION_X:
			if(setGet == FIELD_SET) {
				std::cout << "Cannot set FIELD_ROTATION_X silly " << std::endl;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_ROTATION_X" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
			break;
		case FIELD_ROTATION_Y:
			if(setGet == FIELD_SET) {
				std::cout << "Cannot set FIELD_ROTATION_Y silly " << std::endl;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_ROTATION_Y" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
			break;
		case FIELD_ROTATION_Z:
			if(setGet == FIELD_SET) {
				std::cout << "Cannot set FIELD_ROTATION_Z silly " << std::endl;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_ROTATION_Z" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
			break;
		case FIELD_ALTITUDE:
			if(setGet == FIELD_SET) {
				uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				std::cout << "Set FIELD_ALTITUDE to " << value << std::endl;
				fieldStatuses[i].value = 0;
				fieldStatuses[i].size = 0;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_ALTITUDE" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
		case FIELD_ANGLE_X:
			if(setGet == FIELD_SET) {
				uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				std::cout << "Set FIELD_ANGLE_X to " << value << std::endl;
				fieldStatuses[i].value = 0;
				fieldStatuses[i].size = 0;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_ANGLE_X" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
		case FIELD_ANGLE_Y:
			if(setGet == FIELD_SET) {
				uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				std::cout << "Set FIELD_ANGLE_Y to " << value << std::endl;
				fieldStatuses[i].value = 0;
				fieldStatuses[i].size = 0;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_ANGLE_Y" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
		case FIELD_ANGLE_Z:
			if(setGet == FIELD_SET) {
				uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				std::cout << "Set FIELD_ANGLE_Z to " << value << std::endl;
				fieldStatuses[i].value = 0;
				fieldStatuses[i].size = 0;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_ANGLE_Z" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
		case FIELD_ROCKET_STATE:
			break;
		case FIELD_LED_1:
			if(setGet == FIELD_SET) {
				uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				std::cout << "Set FIELD_LED_1 to " << value << std::endl;
				fieldStatuses[i].value = 0;
				fieldStatuses[i].size = 0;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_LED_1" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
		case FIELD_LED_2:
			if(setGet == FIELD_SET) {
				uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				std::cout << "Set FIELD_LED_2 to " << value << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_LED_2" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
		case FIELD_BUZZER:
			if(setGet == FIELD_SET) {
				uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				std::cout << "Set FIELD_BUZZER to " << value << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_BUZZER" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 0; 
			}
			break;
		case FIELD_SOFTWARE_VERSION:
			if(setGet == FIELD_SET) {
				std::cout << "cannot set FIELD_SOFTWARE_VERSION silly" << std::endl;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Get FIELD_SOFTWARE_VERSION" << std::endl;
				fieldStatuses[i].value = 17; //TODO Change to use Nova Header
				fieldStatuses[i].size = 0; 
			}
			break;
		case FIELD_HARDWARE_VERSION:
			if(setGet == FIELD_SET) {
				std::cout << "cannot set FIELD_HARDWARE_VERSION silly" << std::endl;
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Get FIELD_HARDWARE_VERSION" << std::endl;
				fieldStatuses[i].value = 17; //TODO Change to use Nova Header
				fieldStatuses[i].size = 2; 
			}
			break;
		case FIELD_ADDRESS:
			if(setGet == FIELD_SET) {
				uint8_t address = message[index++];
				std::cout << "Set FIELD_ADDRESS to " << (int)address << std::endl;
				INSTANCE.address = address;
				fieldStatuses[i].value = 1; 
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Get FIELD_ADDRESS" << std::endl;
				fieldStatuses[i].value = INSTANCE.address; 
				fieldStatuses[i].size = 1; 
			}
			break;
		}
	}	
	
	
	uint8_t numActions = message[index++];
	CommandStatus actionStatuses[numActions];
	for(int i = 0; i < numActions; i++) {
		uint8_t actionID = message[index++];
		actionStatuses[i].id = actionID;
		actionStatuses[i].value = 1; //default is success
		actionStatuses[i].size = 0; 
		switch(actionID) {
		case ACTION_COPY_FLASH:
			std::cout << "Copying Flash" << std::endl;
			break;
		case ACTION_FIRE_PYRO:
			std::cout << "FIRE" << std::endl;
			break;
		case ACTION_ARM:
			std::cout << "ARM" << std::endl;
			break;
		case ACTION_DISARM:
			std::cout << "DISARM" << std::endl;
			break;
		}
	}
	
	
	formatResponse(fieldStatuses, numFields, actionStatuses, numActions);
}

void MessageHandler::formatResponse(CommandStatus * fieldStatuses, int numFields, CommandStatus * actionStatuses, int numActions) {
	std::cout <<"This is where I format a response" <<std::endl;
}



void MessageHandler::handleResponse(uint8_t* message, uint8_t size) {
	std::cout << "I got a response message" << std::endl;
	std::cout << "msgData: ";
	int i = MESSAGE_DATA_START;
	while(i < size) {
		std::cout << (int)message[i] << ", "; 
		i++;
	}
	std::cout << std::endl;
}
MessageHandler::MessageHandler() {
	assert(sizeof (float) == 4);//need float to be 32 bit
	address = DEFAULT_ADDRESS;
}
MessageHandler::~MessageHandler() {

}
