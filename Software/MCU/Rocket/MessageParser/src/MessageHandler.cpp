#include "MessageHandler.hpp"
#include <cassert>
//TODO put all the get value from array and put value in bytes to account for big and little endian differences
void MessageHandler::parseMessage(uint8_t* message, uint16_t arraySize) {
	uint8_t * buffer = new uint8_t[BUFFER_SIZE];
	
	uint8_t bufferIndex = 0;
	uint8_t messageSize = 0;
	for(uint16_t i = 0; i < arraySize; i++) {
		if(message[i] == ESCAPE_INT) {
			//escape charachter fun!
			i++;
			if(message[i] == ESCAPE_END_MSG) {
				break;
			}
			else if(message[i] == ESCAPE_0) {
				buffer[bufferIndex] = 0;
			}
			else if(message[i] == ESCAPE_1) {
			  buffer[bufferIndex] = 1;
			}
		}
		else {
			buffer[bufferIndex] = message[i];
		}
		
		
		if(bufferIndex == BUFFER_SIZE-1) {
			delete buffer;
		}
		bufferIndex++;
	}
	messageSize = bufferIndex;
	
	//check some stuff
	if(MESSAGE_VERSION != buffer[MESSAGE_VERSION_BYTE]) {
	  logger.Warning(std::string("Incorrect Message Version"));
		//drop message wrong message version
	}
	else if(messageSize != buffer[MESSAGE_LENGTH_BYTE]) {
	  logger.Warning("Message Sizes do not match listed: " +
			 std::to_string(buffer[MESSAGE_LENGTH_BYTE]) + " Actual: " +
			 std::to_string(messageSize));
		//drop, message incorrect size
	} 
	else if( (address != buffer[DEST_ADDRESS_BYTE]) 
			 && (address != BROADCAST_ADDRESS) ) {
		//drop, not addressed to this device
	}
	else if(COMMAND_TYPE == buffer[COMMAND_RESPONSE_BYTE]) {
		handleCommand(buffer, messageSize);
	}
	else if(RESPONSE_TYPE == buffer[COMMAND_RESPONSE_BYTE]) {
		handleResponse(buffer, messageSize);
	}
	else {
	  logger.Warning("Unkown Command response byte");
	}
	
	delete buffer;
}
void MessageHandler::sendCommand(uint8_t* message, uint8_t size) {
  //Dont have any commands to send so I am just being great and not doing this
  //for the future
}

void MessageHandler::handleCommand(uint8_t* message, uint8_t size) {
  uint8_t *responseBuffer = (uint8_t*)malloc(128);
	uint8_t index = MESSAGE_DATA_START;
	uint8_t numFields = message[index++];
	
	CommandStatus fieldStatuses[numFields];
	for(int i = 0; i < numFields; i++) {
		uint8_t fieldId = message[index++];
		uint8_t setGet = message[index++];
		fieldStatuses[i].ID = fieldId;
		fieldStatuses[i].value = 0; //by default 0
		fieldStatuses[i].size = 4; //by default 0
		switch(fieldId) {
		case FIELD_PRESSURE:
			if(setGet == FIELD_SET) {
			  uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				sensors.setCPressure_test(value);
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
			  fieldStatuses[i].value = sensors.getCPressure();
			  fieldStatuses[i].size = 4;
			}
			break;
		case FIELD_ACCELERATION_X:
			if(setGet == FIELD_SET) {
			  uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				Cartesian acceleration = sensors.getAcceleration();
				acceleration.x = value;
				sensors.setAcceleration_test(acceleration);
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
			  fieldStatuses[i].value = sensors.getAcceleration().x;
				fieldStatuses[i].size = 4; 
			}
			break;
		case FIELD_ACCELERATION_Y:
			if(setGet == FIELD_SET) {
			  uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				Cartesian acceleration = sensors.getAcceleration();
				acceleration.y = value;
				sensors.setAcceleration_test(acceleration);
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
			  fieldStatuses[i].value = sensors.getAcceleration().y;
				fieldStatuses[i].size = 4; 
			}
			break;
		case FIELD_ACCELERATION_Z:
			if(setGet == FIELD_SET) {
			  uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				Cartesian acceleration = sensors.getAcceleration();
				acceleration.z = value;
				sensors.setAcceleration_test(acceleration);
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
			  fieldStatuses[i].value = sensors.getAcceleration().z;
			  fieldStatuses[i].size = 4;
			}
			break;
		case FIELD_ROTATION_X:
			if(setGet == FIELD_SET) {
			  uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				Cartesian rotation = sensors.getAngularVelocity();
				rotation.x = value;
				sensors.setAngularVelocity_test(rotation);
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
			  fieldStatuses[i].value = sensors.getAngularVelocity().x;
			  fieldStatuses[i].size = 4;
			}
			break;
		case FIELD_ROTATION_Y:
			if(setGet == FIELD_SET) {
			  uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				Cartesian rotation = sensors.getAngularVelocity();
				rotation.y = value;
				sensors.setAngularVelocity_test(rotation);
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
			  fieldStatuses[i].value = sensors.getAngularVelocity().y;
			  fieldStatuses[i].size = 4;
			}
			break;
		case FIELD_ROTATION_Z:
			if(setGet == FIELD_SET) {
			  uint32_t floatBytes = 	(message[index + 3] << 24) + 
										(message[index + 2] << 16) + 
										(message[index + 1] << 8) + 
										(message[index + 0]);
				float value = static_cast<float>(floatBytes);
				index = index + 4;
				Cartesian rotation = sensors.getAngularVelocity();
				rotation.z = value;
				sensors.setAngularVelocity_test(rotation);
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
			  fieldStatuses[i].value = sensors.getAngularVelocity().z;
			  fieldStatuses[i].size = 4;
			}
			break;
		case FIELD_ALTITUDE:
			if(setGet == FIELD_SET) {
			  logger.Warning("Attempted to set altitude");
			}
			else if(setGet == FIELD_GET) {
			  fieldStatuses[i].value = data.getAltitude();
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
				std::cout << "Cannot set FIELD_PRESSURE silly " << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Get get Pressure yet" << std::endl;
				fieldStatuses[i].value = 0;
				fieldStatuses[i].size = 4;  
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
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_ANGLE_Y" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 4; 
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
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_ANGLE_Z" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 4; 
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
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_LED_1" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 4; 
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
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_LED_2" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 4; 
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
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Cannot Get FIELD_BUZZER" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 4; 
			}
			break;
		case FIELD_SOFTWARE_VERSION:
			if(setGet == FIELD_SET) {
				std::cout << "cannot set FIELD_SOFTWARE_VERSION silly" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Get FIELD_SOFTWARE_VERSION" << std::endl;
				fieldStatuses[i].value = SOFTWARE_VERSION; //TODO Change to use Nova Header
				fieldStatuses[i].size = 2; 
			}
			break;
		case FIELD_HARDWARE_VERSION:
			if(setGet == FIELD_SET) {
				std::cout << "cannot set FIELD_HARDWARE_VERSION silly" << std::endl;
				fieldStatuses[i].value = 0; 
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Get FIELD_HARDWARE_VERSION" << std::endl;
				fieldStatuses[i].value = BOARD_VERSION; //TODO Change to use Nova Header
				fieldStatuses[i].size = 2; 
			}
			break;
		case FIELD_ADDRESS:
			if(setGet == FIELD_SET) {
				uint8_t address = message[index++];
				std::cout << "Set FIELD_ADDRESS to " << (int)address << std::endl;
				this->address = address;
				fieldStatuses[i].value = 1; 
				fieldStatuses[i].size = 1; 
			}
			else if(setGet == FIELD_GET) {
				std::cout << "Get FIELD_ADDRESS" << std::endl;
				fieldStatuses[i].value = address; 
				fieldStatuses[i].size = 1; 
			}
			break;
		}
	}	

	uint8_t numActions = message[index++];
	CommandStatus actionStatuses[numActions];
	for(int i = 0; i < numActions; i++) {
		uint8_t actionID = message[index++];
		actionStatuses[i].ID = actionID;
		actionStatuses[i].value = 1; //default is success
		actionStatuses[i].size = 1; 
		switch(actionID) {
		case ACTION_COPY_FLASH:
		  //TODO impliment this
			break;
		case ACTION_FIRE_PYRO:
		  //TODO impliment this
			break;
		case ACTION_ARM:
		  brain.arm();
			break;
		case ACTION_DISARM:
		  brain.disarm();
			break;
		}
	}
	
	
	uint8_t srcAddress = message[SRC_ADDRESS_BYTE];
	uint16_t messageSize = formatResponse(fieldStatuses, numFields, actionStatuses, numActions, srcAddress, responseBuffer);
	std::string msg((const char *)responseBuffer, messageSize);
	transmit_callback(transmitContext, msg); //This function takes responsibility for freeing memory
	free(responseBuffer);
}

uint16_t MessageHandler::formatResponse(CommandStatus * fieldStatuses, int numFields, CommandStatus * actionStatuses, int numActions, uint8_t srcAddress, uint8_t * responseBuffer) {

	uint8_t * response = new uint8_t[BUFFER_SIZE];
	response[MESSAGE_VERSION_BYTE] = MESSAGE_VERSION;
	response[COMMAND_RESPONSE_BYTE] = RESPONSE_TYPE;
	response[DEST_ADDRESS_BYTE] = srcAddress;
	response[SRC_ADDRESS_BYTE] = address;
	
	uint8_t index = MESSAGE_DATA_START;
	response[index++] = numFields;
	
	
	for(int i = 0; i < numFields; i++) {
		uint32_t value = fieldStatuses[i].value;
		response[index++] = fieldStatuses[i].ID;
		switch(fieldStatuses[i].size) {
		case 0:
			break;
		case 1:
			response[index++] = value & 0xFF;
			break;	
		case 2:
			response[index++] = (value & (0xFF << 8) >> 8);
			response[index++] = value & 0xFF;
			break;
		case 3:
			response[index++] = (value & (0xFF << 16) >> 16);
			response[index++] = (value & (0xFF << 8) >> 8);
			response[index++] = value & 0xFF;
			break;
		case 4:
			response[index++] = (value & (0xFF << 24) >> 24);
			response[index++] = (value & (0xFF << 16) >> 16);
			response[index++] = (value & (0xFF << 8) >> 8);
			response[index++] = value & 0xFF;
			break;
		}
	}
	response[index++] = numActions;
	for(int i = 0; i < numActions; i++) {
		uint32_t value = actionStatuses[i].value;
		response[index++] = actionStatuses[i].ID;
		switch(actionStatuses[i].size) {
		case 0:
			break;
		case 1:
		        response[index++] = value & 0xFF;
			break;	
		case 2:
			response[index++] = (value & (0xFF << 8) >> 8);
			response[index++] = value & 0xFF;
			break;
		case 3:
			response[index++] = (value & (0xFF << 16) >> 16);
			response[index++] = (value & (0xFF << 8) >> 8);
			response[index++] = value & 0xFF;
			break;
		case 4:
			response[index++] = (value & (0xFF << 24) >> 24);
			response[index++] = (value & (0xFF << 16) >> 16);
			response[index++] = (value & (0xFF << 8) >> 8);
			response[index++] = value & 0xFF;
			break;
		}
	}
	
	response[MESSAGE_LENGTH_BYTE] = index;
	uint16_t finalSize = 0;
	for(int i = 0; i < index; i++) {
		if(response[i] == ESCAPE_INT) {
			responseBuffer[finalSize++] = ESCAPE_INT;
			responseBuffer[finalSize++] = ESCAPE_1;
		}
		else if(response[i] == 0) {
		  responseBuffer[finalSize++] = ESCAPE_INT;
		  responseBuffer[finalSize++] = ESCAPE_0;
		}
		else {
			responseBuffer[finalSize++] = response[i];
		}
		
	}
	responseBuffer[finalSize++] = ESCAPE_INT;
	responseBuffer[finalSize++] = ESCAPE_END_MSG;
	delete response;
	return finalSize;
}



void MessageHandler::handleResponse(uint8_t* message, uint8_t size) {
	//casually drops message
}
MessageHandler::~MessageHandler() {
}
MessageHandler::MessageHandler(Configuration& config, Brain& brain, SensorValues& sensors, RocketData& data, Logger& logger, void* transmitContext, void (*transmit_callback)(void*, std::string)) :
  config(config),
  brain(brain),
  sensors(sensors),
  data(data),
  logger(logger),
  transmit_callback(transmit_callback),
  transmitContext(transmitContext)
{
	assert(sizeof (float) == 4);//need float to be 32 bit
	address = DEFAULT_ADDRESS;

}
