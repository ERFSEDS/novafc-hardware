#pragma once
#include <cinttypes>
#include <vector>

#define MESSAGE_VERSION		1

#define BOARD_MAJOR_VERSION 1
#define BOARD_MINOR_VERSION 0
#define SOFTWARE_MAJOR_VERSION 1
#define SOFTWARE_MINOR_VERSION 0

#define BUFFER_SIZE 			256
#define DEFAULT_BOARD_ADDRESS	56
#define BROADCAST_ADDRESS		255

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


#define NUMBER_OF_STATES 9
#define DEFAULT_START_STATE (UNARMED)
enum State
{
	UNARMED = 0,
	READY = 1,
	STAGE1POWERED = 2,
	STAGE1COAST = 3,
	STAGE2POWERED = 4,
	STAGE2COAST = 5,
	DESCENT = 6,
	LANDED = 7,
	RESET = 8
	
};


enum AltitudeDeterminination {
	ACCELEROMETER_ONLY=0,
	BAROMETER_ONLY=1,
	BOTH=2
};
enum PyroConfig {
	VELOCITY_ABOVE = 0,
	VELOCITY_BELOW = 1,
	ACCELERATION_BELOW = 2,
	ACCELERATION_ABOVE = 3,
	ALTITUDE_ABOVE = 4,
	ALTITUDE_BELOW = 5,
	TIME_DELAY = 6,
	PAST_APOGEE = 7,
	STATE = 8,//value is state desired(it will be cast to int)
	NONE = 9,	//this condition is always met
	NO_FIRE = 10//this condition is never met
};

struct Pyro {
	PyroConfig configOne;
	float valueOne;
	PyroConfig configTwo;
	float valueTwo;
	bool tiltLock;
	
	bool operator==(const Pyro& pyro){
	  if ( (configOne == pyro.configOne) &&
	       (valueOne == pyro.valueOne) &&
	       (configTwo == pyro.configTwo) &&
	       (valueTwo == pyro.valueTwo) &&
	       (tiltLock == pyro.tiltLock)) {
	    return true;
	  }
	  return false;
	}
};


enum Fields {
	pressure = 0, //use value
	acceleration = 1, //use vector
	angularVelocity = 2,//use vector
	altitude = 3, //use value
	orientation =4,//use quanternion
	rocketState =5, //use valueInt
	pyroChannel=6, //use valueInt(for pyroNum) and pyro
	altitudeDetermination=7,//use valueInt
	ignitionThreshold=8, //use value
	cutoffThreshold=9, //use value
	testSimulation=10, //use valueInt(0 for false 1 for true)
	boardType=11,//use valueInt
	addrress=12, //use valueInt
	softwareVersion=13, //use valueInt
	hardwareVersion=14, //use valueInt
	twoStage=15 //use valueInt(0 for false 1 for true)
};
enum Actions {
	copyFlashToSD=0,
	firePyro=1,
	arm=2,
	disarm=3,
	pyroCorrect=4,
	stepSimulation=5
};

struct FieldMessage{ //was going to be fancy and make a union but then I decided to keep it simple just set the right value
	Fields type;
	bool set; // if false will get
	float value;
	int valueInt;
	float vector[3];
	float quanternion[4];
	Pyro pyro;
};

struct ActionMessage { //same as above
	Actions type;
	int value; 
	int returnStatus;
};
struct Message {
	std::vector<FieldMessage> fields;
	std::vector<ActionMessage> actions;
};
class MessageHandler {
public:
	MessageHandler(uint8_t address);
	std::vector<uint8_t> generateMessage(Message message, uint8_t address=0x56);
	Message handlerResponse(std::vector<uint8_t> msg);
	
private:
	void getFloat(std::vector<uint8_t> message, float valueF);
	float getFloat(std::vector<uint8_t> message, int offset=0);
	uint8_t address;
};
