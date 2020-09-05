#pragma once
#define MESSAGE_VERSION		1
#define BOARD_TYPE 			1
#define BOARD_VERSION		17 //1.0	
#define SOFTWARE_VERSION	17 //1.0

#define BUFFER_SIZE 		256
#define DEFAULT_ADDRESS		56
#define BROADCAST_ADDRESS	255

#define COMMAND_TYPE		0
#define RESPONSE_TYPE		1

//bytes that need to be checked before handle
#define MESSAGE_VERSION_BYTE	0
#define MESSAGE_LENGTH_BYTE		1
#define COMMAND_RESPONSE_BYTE	2
#define BOARD_TYPE_BYTE			3
#define ADDRESS_BYTE			4
#define MESSAGE_DATA_START		5


//fields
#define FIELD_SET				1
#define FIELD_GET				0
#define FIELD_PRESSURE			0
#define FIELD_ACCELERATION_X	1
#define FIELD_ACCELERATION_Y	2
#define FIELD_ACCELERATION_Z	3
#define FIELD_ROTATION_X		4
#define FIELD_ROTATION_Y		5
#define FIELD_ROTATION_Z		6
#define FIELD_ALTITUDE			7
#define FIELD_ANGLE_X			8
#define FIELD_ANGLE_Y			9
#define FIELD_ANGLE_Z			10
#define FIELD_ROCKET_STATE		11
#define FIELD_LED_1				12
#define FIELD_LED_2				13
#define FIELD_BUZZER			14
#define FIELD_SOFTWARE_VERSION	15
#define FIELD_HARDWARE_VERSION	16
#define FIELD_ADDRESS			17

//actions
#define ACTION_COPY_FLASH		0
#define ACTION_FIRE_PYRO		1
#define ACTION_ARM				2
#define ACTION_DISARM			3


//General command
#define STATUS_SUCCESS			1
#define STATUS_FAIL				0

//escapeChars
#define ESCAPE_INT				0
#define ESCAPE_0				1


#include <cinttypes>
//this class is really just a container

struct CommandStatus {
	uint8_t ID;
	uint32_t value;
	uint8_t size;//0 means ignore value, 1 means only bottom byte .. so on
};

class MessageHandler {
		uint8_t address;
	public:
		static void parseMessage(uint8_t* message, uint16_t arraySize);
		static void sendCommand(uint8_t* message, uint8_t size); //rework into command options
		
	private:
		static void sendMessage(uint8_t* response,  uint8_t msgSize);
		static void formatResponse(CommandStatus * fieldStatuses, int numFields, CommandStatus * actionStatuses, int numActions);
		static void handleCommand(uint8_t* message, uint8_t msgSize);
		static void handleResponse(uint8_t* message, uint8_t msgSize);
		
	public:
		MessageHandler(const MessageHandler &messageHandler) = delete;
	private:
		static MessageHandler INSTANCE;
		MessageHandler();
		~MessageHandler();
		
};
