#pragma once
#include <cinttypes>
#include "RocketData.hpp"
#include "Logger.hpp"
#include "Brain.hpp"
#include "SensorValues.hpp"

#define MESSAGE_VERSION		1

#define BOARD_MAJOR_VERSION 1
#define BOARD_MINOR_VERSION 0
#define SOFTWARE_MAJOR_VERSION 1
#define SOFTWARE_MINOR_VERSION 0

#define BOARD_VERSION		((BOARD_MAJOR_VERSION << 8) | (BOARD_MINOR_VERSION))
#define SOFTWARE_VERSION	((SOFTWARE_MAJOR_VERSION << 8) | (SOFTWARE_MINOR_VERSION))
#define BUFFER_SIZE 		256
#define DEFAULT_ADDRESS		56
#define BROADCAST_ADDRESS	255

#define COMMAND_TYPE		0
#define RESPONSE_TYPE		1

//bytes that need to be checked before handle
#define MESSAGE_VERSION_BYTE	0
#define MESSAGE_LENGTH_BYTE		1
#define COMMAND_RESPONSE_BYTE	2
#define SRC_ADDRESS_BYTE		3
#define DEST_ADDRESS_BYTE		4
#define MESSAGE_DATA_START		5


//fields
#define FIELD_SET				1
#define FIELD_GET				0
#define FIELD_PRESSURE			0
#define FIELD_ACCELERATION  	        1
#define FIELD_ANGULAR_VELOCITY          2
#define FIELD_ALTITUDE                  3
#define FIELD_ORIENTATION               4
#define FIELD_ROCKET_STATE              5
#define FIELD_PYRO_CHANNEL              6
#define FIELD_ALTITUDE_DETERMINATION    7
#define FIELD_IGNITION_THRESHOLD        8
#define FIELD_CUTOFF_THRESHOLD          9
#define FIELD_TEST_SIMULATION           10
#define FIELD_BOARD_TYPE		11
#define FIELD_ADDRESS			12
#define FIELD_SOFTWARE_VERSION	        13
#define FIELD_HARDWARE_VERSION          14
#define FIELD_TWO_STAGE                 15
#define FIELD_UPPER_TIME_STEP 16

//actions
#define ACTION_COPY_FLASH		0
#define ACTION_FIRE_PYRO		1
#define ACTION_ARM				2
#define ACTION_DISARM			3
#define ACTION_PYRO_CORRECT             4  //not really an action but it fits better here
#define ACTION_SIM_STEP                 5

//General command
#define STATUS_SUCCESS			1
#define STATUS_FAIL				0

//escapeChars
#define ESCAPE_INT				1
#define ESCAPE_END_MSG			0
#define ESCAPE_1				2
#define ESCAPE_0 1


#define BOARD_TYPE 			1


struct CommandStatus {
  uint8_t ID;
  uint8_t setget;
  uint8_t value[16];
  uint8_t size;
};

class MessageHandler {
public:
  void parseMessage(uint8_t* message, uint16_t arraySize);
  void sendCommand(uint8_t* message, uint8_t size); 
		
private:
  uint16_t formatResponse(CommandStatus * fieldStatuses, int numFields, CommandStatus * actionStatuses, int numActions, uint8_t srcAddress, uint8_t * responseBuffer);
  void handleCommand(uint8_t* message, uint8_t msgSize);
  void handleResponse(uint8_t* message, uint8_t msgSize);
  uint8_t address;
  Configuration& config;
  Brain& brain;
  StateMachine& state;
  SensorValues& sensors;
  RocketData& data;
  void (*transmit_callback) (void*, std::string);
  void* transmitContext;
  Logger& logger;
public:
  MessageHandler(Configuration& config, Brain& brain, SensorValues& sensors, RocketData& data, Logger& logger, StateMachine& state, void* transmitContext, void (*transmit_callback)(void*, std::string));
  ~MessageHandler();
		
};

