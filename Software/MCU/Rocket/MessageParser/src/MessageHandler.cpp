#include "MessageHandler.hpp"
#include <cassert>
#include "Common.hpp"
//TODO put all the get value from array and put value in bytes to account for big and little endian differences
//TODO we should probably try catch the reading of the messages there is a lot of assumed casting
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
    fieldStatuses[i].setget = setGet;
    fieldStatuses[i].size = 0;
    switch(fieldId) {
    case FIELD_PRESSURE:
      if(setGet == FIELD_SET) {
	float value = getFloat(message, index);
	index = index + 4;
	sensors.setCPressure_test(value);
	fieldStatuses[i].value[0] = 0;
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	setFloat(sensors.getCPressure(), fieldStatuses[i].value, 0);
	fieldStatuses[i].size = 4;
      }
      break;
    case FIELD_ACCELERATION:
      if(setGet == FIELD_SET) {
	Cartesian acceleration;
	acceleration.x = getFloat(message, index);
	index = index + 4;
	acceleration.y = getFloat(message, index);
	index = index + 4;
	acceleration.z = getFloat(message, index);
	index = index + 4;
	sensors.setAcceleration_test(acceleration);
	fieldStatuses[i].value[0] = 0;
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	Cartesian acceleration = sensors.getAcceleration();
	setFloat(acceleration.x, fieldStatuses[i].value, 0);
	setFloat(acceleration.y, fieldStatuses[i].value, 4);
	setFloat(acceleration.z, fieldStatuses[i].value, 8);
	fieldStatuses[i].size = 12;
      }
      break;
    case FIELD_ANGULAR_VELOCITY:
      if(setGet == FIELD_SET) {
	Cartesian angularVelocity;
	angularVelocity.x = getFloat(message, index);
	index = index + 4;
	angularVelocity.y = getFloat(message, index);
	index = index + 4;
	angularVelocity.z = getFloat(message, index);
	index = index + 4;
	sensors.setAngularVelocity_test(angularVelocity);
	fieldStatuses[i].value[0] = 0;
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	Cartesian angularVelocity = sensors.getAngularVelocity();
	setFloat(angularVelocity.x, fieldStatuses[i].value, 0);
	setFloat(angularVelocity.y, fieldStatuses[i].value, 4);
	setFloat(angularVelocity.z, fieldStatuses[i].value, 8);
	fieldStatuses[i].size = 12;
      }
      break;
    case FIELD_ALTITUDE:
      if(setGet == FIELD_SET) {
	logger.Warning("Attempted to set altitude");
	fieldStatuses[i].value[0] = 1;
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	setFloat(data.getAltitude(), fieldStatuses[i].value, 0);
	fieldStatuses[i].size = 4;
      }
      break;
    case FIELD_ORIENTATION:
      if(setGet == FIELD_SET) {
	logger.Warning("Attempted to set orientation");
	fieldStatuses[i].value[0] = 1;
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	Quanternion angle = data.getAngle();
	setFloat(angle.a, fieldStatuses[i].value, 0);
	setFloat(angle.i, fieldStatuses[i].value, 4);
	setFloat(angle.j, fieldStatuses[i].value, 8);
	setFloat(angle.k, fieldStatuses[i].value, 12);
	fieldStatuses[i].size = 16;
      }
      break;
    case FIELD_ROCKET_STATE:
      if(setGet == FIELD_SET) {
	logger.Warning("Attempted to set rocket state");
	fieldStatuses[i].value[0] = 1;
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	logger.Warning("Remove this");
	fieldStatuses[i].value[0] = (uint8_t)state.getCurrentState();
	fieldStatuses[i].size = 1;
      }
      break;
    case FIELD_PYRO_CHANNEL:
      if(setGet == FIELD_SET) {
	int pyroNum = message[index++];
	PyroConfig configOne = static_cast<PyroConfig>((int)message[index++]);
	float valueOne = getFloat(message, index);
	index += 4;
	PyroConfig configTwo = static_cast<PyroConfig>((int)message[index++]);
	float valueTwo = getFloat(message, index);
	index += 4;
	bool tiltLock = static_cast<bool>(message[index++]);
	config.setPyro(pyroNum, tiltLock, configOne, valueOne, configTwo, valueTwo);
	fieldStatuses[i].value[0] = 0;
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	int pyroNum = message[index++];
	Pyro pyro = *config.getPyro(pyroNum);
	fieldStatuses[i].value[0] = static_cast<uint8_t>(pyro.configOne);
	setFloat(pyro.valueOne, fieldStatuses[i].value, 1);
	fieldStatuses[i].value[5] = static_cast<uint8_t>(pyro.configTwo);
	setFloat(pyro.valueTwo, fieldStatuses[i].value, 6);
	fieldStatuses[i].value[10] = static_cast<uint8_t>(pyro.tiltLock);
	
	fieldStatuses[i].size = 4;
	
      }
      break;
    case FIELD_ALTITUDE_DETERMINATION:
      if(setGet == FIELD_SET) {
	AltitudeDeterminination determination = static_cast<AltitudeDeterminination>(message[index++]);
	config.setAltitudeDetermination(determination);
	fieldStatuses[i].value[0] = 0;
	fieldStatuses[i].size = 1;
      }
      else if(setGet == FIELD_GET) {
	fieldStatuses[i].value[0] = static_cast<uint8_t>(config.getAltitudeDetermination());
	fieldStatuses[i].size = 1;
      }
      break;
    case FIELD_IGNITION_THRESHOLD:	     
      if(setGet == FIELD_SET) {
	float ignitionThreshold = getFloat(message, index);
	index+=4;
	config.setIgnitionThreshold(ignitionThreshold);
	fieldStatuses[i].value[0] = 0;
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	setFloat(config.getIgnitionThreshold(), fieldStatuses[i].value, 0);
	fieldStatuses[i].size = 4; 
      }
      break;
    case FIELD_CUTOFF_THRESHOLD:
      if(setGet == FIELD_SET) {
	float cutoffThreshold = getFloat(message, index);
	index +=4;
	config.setCutoffThreshold(cutoffThreshold);
	fieldStatuses[i].value[0] = 0;
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	setFloat(config.getCutoffThreshold(), fieldStatuses[i].value, 0);
	fieldStatuses[i].size = 4; 
      }
      break;
    case FIELD_TEST_SIMULATION:
      if(setGet == FIELD_SET) {
	bool simulation = static_cast<bool>(message[index++]);
	config.setTest(simulation);
	fieldStatuses[i].value[0] = 0;
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	fieldStatuses[i].value[0] = static_cast<uint8_t>(config.getTest());
	fieldStatuses[i].size = 1; 
      }
      break;
    case FIELD_ADDRESS:
      if(setGet == FIELD_SET) {
	uint8_t address = message[index++];
	logger.Event(std::string("Address set to ") + std::to_string(address));
	this->address = address;
	fieldStatuses[i].value[0] = 1; 
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	fieldStatuses[i].value[0] = address; 
	fieldStatuses[i].size = 1; 
      }
      break;
    case FIELD_SOFTWARE_VERSION:
      if(setGet == FIELD_SET) {
	logger.Warning("Tried to set software Version");
	fieldStatuses[i].value[0] = 1;
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	fieldStatuses[i].value[0] = (SOFTWARE_VERSION & (0xFF << 8)) >> 8;
	fieldStatuses[i].value[1] = SOFTWARE_VERSION & (0xFF);
	fieldStatuses[i].size = 2; 
      }
      break;
    case FIELD_HARDWARE_VERSION:
      if(setGet == FIELD_SET) {
	logger.Warning("Tried to set Hardware Version");
	fieldStatuses[i].value[0] = 1;
	fieldStatuses[i].size = 1; 
      }
      else if(setGet == FIELD_GET) {
	fieldStatuses[i].value[0] = (BOARD_VERSION & (0xFF << 8)) >> 8;
	fieldStatuses[i].value[1] = BOARD_VERSION & (0xFF);
	fieldStatuses[i].size = 2; 
      }
      break;
    case FIELD_TWO_STAGE:
      if(setGet == FIELD_SET) {
	bool twoStage = message[index++];
	config.setTwoStageRocket(twoStage);
	fieldStatuses[i].value[0] = 0;
	fieldStatuses[i].size = 1;
      }
      else if(setGet == FIELD_GET) {
	fieldStatuses[i].value[0] = (uint8_t)config.getTwoStageRocket();
	fieldStatuses[i].size = 1;
      }
      break;
    case FIELD_UPPER_TIME_STEP:
      if(setGet == FIELD_SET) {
	float upperTimeStep = getFloat(message, index);
	index +=4;
	config.setUpperTimeStepms(upperTimeStep);
	fieldStatuses[i].value[0] = 0;
	fieldStatuses[i].size = 1;
      }
      else if(setGet == FIELD_GET) {
	setFloat(config.getUpperTimeStepms(), fieldStatuses[i].value, 0);
	fieldStatuses[i].size = 4; 

      }
      break;
    }
  }	

  uint8_t numActions = message[index++];
  CommandStatus actionStatuses[numActions];
  for(int i = 0; i < numActions; i++) {
    uint8_t actionID = message[index++];
    actionStatuses[i].ID = actionID;
    actionStatuses[i].value[0] = 1; //default is success
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
    case ACTION_PYRO_CORRECT:
      break;
    case ACTION_SIM_STEP:
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
    response[index++] = fieldStatuses[i].ID;
    response[index++] = fieldStatuses[i].setget;
    for(int j = 0; j < fieldStatuses[i].size; j++) {
      response[index++] = fieldStatuses[i].value[j];
    }
  }
  response[index++] = numActions;
  for(int i = 0; i < numActions; i++) {
    response[index++] = actionStatuses[i].ID;
    for(int j = 0; j < actionStatuses[i].size; j++) {
      response[index++] = actionStatuses[i].value[j];
    }
  }
	
  response[MESSAGE_LENGTH_BYTE] = index;
  uint16_t finalSize = 0;
  for(int i = 0; i < index; i++) {
    if(response[i] == 1) {
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


//its formatted big endian
// [0]       [1]  [2]  [3]
// highest   high low lowest

void MessageHandler::handleResponse(uint8_t* message, uint8_t size) {
  //casually drops message
}
MessageHandler::~MessageHandler() {
}
MessageHandler::MessageHandler(Configuration& config, Brain& brain, SensorValues& sensors, RocketData& data, Logger& logger, StateMachine& state, void* transmitContext, void (*transmit_callback)(void*, std::string)) :
  config(config),
  brain(brain),
  sensors(sensors),
  data(data),
  logger(logger),
  state(state),
  transmit_callback(transmit_callback),
  transmitContext(transmitContext)
{
  assert(sizeof (float) == 4);//need float to be 32 bit
  address = DEFAULT_ADDRESS;

}






