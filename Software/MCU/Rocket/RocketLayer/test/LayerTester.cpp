#include "LayerTester.hpp"
#include "RocketLayer.hpp"
#include "MessageHandler.hpp"
#include "Cartesian.hpp"
#include <iostream>
#include <cinttypes>
#include "LowLevelSimulator.hpp"
#include <string>
#include <sstream>
#include <random> 
class MessageSnooper {
public:
  MessageSnooper(void (*transmitCallback)(void*, std::string), void* context) :
    transmitCallback(transmitCallback), context(context){
  }
  static void transmit_callback(void* context, std::string message) {
    reinterpret_cast<MessageSnooper*>(context)->transmit_callback_i(message);
  }
  std::vector<uint8_t> getMessageBytes() {
    return messageBytes;
  }
private:
  void transmit_callback_i(std::string message) {
    messageBytes.clear();
    for(const char &c : message) {
      messageBytes.push_back( (int)(c) );
    }
    transmitCallback(context, message);
  }
  std::vector<uint8_t> messageBytes;
  void (*transmitCallback)(void*, std::string);
  void* context;
};
RocketLayerTester::RocketLayerTester(std::string inputFile) {
  this->inputFile.open(inputFile);
}
bool RocketLayerTester::runSimulation() {
  int subSampleRate = 100;
  uint8_t configBytes[75];//I set this through messsages doesnt matter
  LowLevelSimulator board;
  MessageSnooper snooper(&(LowLevelSimulator::transmit_callback), (void*)(&board));
  RocketLayer rocket(&(LowLevelSimulator::arm_callback), (void*)(&board),
		     &(LowLevelSimulator::fire_callback), (void*)(&board),
		     &(LowLevelSimulator::flash_write_callback), (void*)(&board),
		     &(MessageSnooper::transmit_callback), (void*)(&snooper),
		     configBytes, 0.1, {0, 9.81, 0}, 101);
  MessageHandler handler(1);

  //configuration message
  Message message;
  FieldMessage pyroZero;
  FieldMessage pyroOne;
  FieldMessage pyroTwo;
  FieldMessage setOneStage;
  FieldMessage setAccelOnly;
  FieldMessage setUpperTimeStep;

  ActionMessage armAction;

  //this is to test the stage feature, because the rocket data is from a 1 stage rocket the state
  //machine will still be treated like a 1 stage rocket
  pyroZero.type = pyroChannel;
  pyroZero.set = true;
  pyroZero.valueInt = 0;
  pyroZero.pyro = {NO_FIRE, (int)(STAGE1COAST), NO_FIRE, 5.0, true};

  pyroOne.type = pyroChannel;
  pyroOne.set = true;
  pyroOne.valueInt = 1;
  pyroOne.pyro = {PAST_APOGEE, 0, NONE, 0, false};

  pyroTwo.type = pyroChannel;
  pyroTwo.set = true;
  pyroTwo.valueInt = 2;
  pyroTwo.pyro = {ALTITUDE_BELOW, 200, PAST_APOGEE, 0, false};

  setOneStage.type = twoStage;
  setOneStage.set = true;
  setOneStage.valueInt = 0;

  setAccelOnly.type = altitudeDetermination;
  setAccelOnly.set = true;
  setAccelOnly.valueInt = ACCELEROMETER_ONLY;

  setUpperTimeStep.type = upperStageTimeStepms;
  setUpperTimeStep.set = true;
  setUpperTimeStep.value = 10;

  armAction.type = arm;

  message.fields.push_back(pyroZero);
  message.fields.push_back(pyroOne);
  message.fields.push_back(pyroTwo);
  message.fields.push_back(setOneStage);
  message.fields.push_back(setAccelOnly);
  message.fields.push_back(setUpperTimeStep);

  message.actions.push_back(armAction);

  float accelNoiseMean = 0;
  float accelNoiseSTD = 3;//this is crazy high noise
  float gyroNoiseMean = 0.2 * M_PI / 180.0; //stores in radians input is degrees
  float gyroNoiseSTD = 0.1 * M_PI / 180.0;//stores in radians input is degrees
  std::vector<uint8_t> messageBytes = handler.generateMessage(message);
  std::cout << "Configuration message generated. Size: " << messageBytes.size() << std::endl;

  std::cout << "{";
  for(auto byte = messageBytes.begin(); byte != messageBytes.end(); byte++) {
    std::cout << (int)(*byte);
  }
  std::cout << "}" << std::endl;
  
  uint8_t bytes[messageBytes.size()];
  std::copy(messageBytes.begin(), messageBytes.end(), bytes);
  
  rocket.handleMessage(bytes, messageBytes.size());
  try {
    //If I dont fix this terrible code when youre seeing this send me a message - Nathan R
    std::cout << "Starting Simulation" << std::endl;
    bool success = true;
    std::string line;
    inputFile>>line;
		
    std::vector<float> arguements;
    //this->split(line, arguements);
    //TODO check these to ensure consistency
    float timeStep, stepNum, accelX, accelY, accelZ, gyroX, gyroY, gyroZ, pressure, trueAltitude, trueAngle;
		
    float altitudeVal, angleVal;
    bool first = true;
    int i = 0;
    float lastAltitude = -1;
    float trueTimeApogee = -1;
    float timeApogee = -1;
		
		
    float truePyroTime[NUMBER_OF_PYROS];
    float pyroTime[NUMBER_OF_PYROS];
    for(int i = 0; i < NUMBER_OF_PYROS; i++) {
      pyroTime[i] = -1;
    }
    for(int i = 0; i < NUMBER_OF_PYROS; i++) {
      truePyroTime[i] = -1;
    }

    while(!inputFile.eof()) {
      inputFile>>line;
      arguements.clear();
      this->split(line, arguements);
      timeStep = arguements.at(0);
      stepNum = arguements.at(1);
      accelX = arguements.at(2);
      accelY = arguements.at(3) + 9.81;
      accelZ = arguements.at(4);
      gyroX = arguements.at(5);
      gyroY = arguements.at(6);
      gyroZ = arguements.at(7);
      pressure = arguements.at(8);
      trueAltitude = arguements.at(9);
      trueAngle = arguements.at(10);

      //insertNoise(&accelX, accelNoiseMean, accelNoiseSTD);
      //insertNoise(&accelY, accelNoiseMean, accelNoiseSTD);
      //insertNoise(&accelZ, accelNoiseMean, accelNoiseSTD);
			

      //insertNoise(&gyroX, gyroNoiseMean, gyroNoiseSTD);
      //insertNoise(&gyroY, gyroNoiseMean, gyroNoiseSTD);
      //insertNoise(&gyroZ, gyroNoiseMean, gyroNoiseSTD);
      if (i >= subSampleRate) {
	Cartesian acceleration = {accelX, accelY, accelZ};
	Cartesian gyro = {gyroX, gyroY, gyroZ};
	if((int)(timeStep*10) == 10*timeStep) {
	  std::cout << "time step: " << timeStep <<std::endl;
	}
	rocket.updateAcceleration(acceleration);
	rocket.updateRotation(gyro);
				
	rocket.updatePressure(pressure);
	//Cartesian val = sensors.getAcceleration(); prety sure this isnt used.....
				
	rocket.update();

	//get state from Message
	Message getStatus;
	FieldMessage getAltitude;
	FieldMessage getAngle;

	getAltitude.type = altitude;
	getAltitude.set = false;

	getAngle.type = orientation;
	getAngle.set = false;

	getStatus.fields.push_back(getAltitude);
	getStatus.fields.push_back(getAngle);

	messageBytes = handler.generateMessage(getStatus);

	uint8_t bytes[messageBytes.size()];
	std::copy(messageBytes.begin(), messageBytes.end(), bytes);
	rocket.handleMessage(bytes, messageBytes.size());
	getStatus = handler.handlerResponse(snooper.getMessageBytes());
	altitudeVal = getStatus.fields[0].value;
	float * orientation = getStatus.fields[1].quanternion;

	float angle = acos(1 - (2 * orientation[1] * orientation[1]) - (2 * orientation[2] * orientation[2]));// I think this math is right?
	
	//This is stuff so you can see where the rocket state module is at when its passing data, does not fail the test(unless there is a math error resulting in no altitude
	float altitudeError = std::abs(altitudeVal - trueAltitude)/trueAltitude; 
	float angleError = std::abs(angle - trueAngle)/trueAngle;
	float altitudeDifference = std::abs(altitudeVal - trueAltitude);
	float angleDifference = std::abs(angle - trueAngle);
	if(altitudeVal != altitudeVal) { //checks for NAN
	  std::cout << "ALtitude is NAN" << std::endl;
	  success = false;
	}
				
	if( (altitudeError > ACCEPTABLE_ALTITUDE_ERROR) && (altitudeDifference > ACCEPTABLE_ALTITUDE_ERROR_ABS) ) {
	  std::cout << "Time is: " << timeStep << std::endl;
	  std::cout << "Altitude outside acceptable bounds" <<std::endl;
	  std::cout << "True Altitude: " << trueAltitude << std::endl;
	  std::cout << "Measured Altitude: " << altitude << std::endl;
	  success = false;
	  std::cout << std::endl;
	}
	if( (angleError > ACCEPTABLE_ANGLE_ERROR) && (angleDifference > ACCEPTABLE_ANGLE_ERROR_ABS)) {
	  std::cout << "Time is: " << timeStep << std::endl;
	  std::cout << "Angle outside acceptable bounds" <<std::endl;
	  std::cout << "True Angle: " << trueAngle << std::endl;
	  std::cout << "Measured Angle: " << (angle * (180/M_PI)) << " degrees" << std::endl;
	  success = false;
	  std::cout << std::endl;
	}
	i=1;
				
				
	//BRAIN STUFF
	//check each pyro
	std::stringstream events("");
	for(int i = 0; i < NUMBER_OF_PYROS; i++) {
	  if(board.getFired(i) && (pyroTime[i] == -1)) {
	    pyroTime[i] = timeStep;
	    events <<"Pyro " << i << " fired--"; 
	    std::cout << "Pyro " << i << " fired at " << timeStep << std::endl;
	  }
	} 
				
	//determine the true times it should run
	//sets pyro 0 to fire at apogee,
	if( (lastAltitude > trueAltitude) && (truePyroTime[1] == -1) ) {
	  truePyroTime[1] = timeStep;
	  events << "Pyro 1 should have fired--";
	  std::cout << "Pyro 1 should fire at " << timeStep << std::endl;
	} 
	//pyro 1 to fire at 200m and past apogee, 
	if( (trueAltitude < 200) && (lastAltitude > trueAltitude) && (truePyroTime[2] == -1) ) {
	  truePyroTime[2] = timeStep;
	  events << "Pyro 2 should have fired--";
	  std::cout << "Pyro 2 should fire at " << timeStep << std::endl;
	} 
			
      }
      else {
	i++;
      }
      lastAltitude=trueAltitude;
    }
		
    for(int i = 0; i < NUMBER_OF_PYROS; i++) {
      if(std::abs(truePyroTime[i] - pyroTime[i]) > ACCEPTABLE_TIME_PYRO_ERROR) {
	success =false;
      }
      std::cout << "Pyro " << i << " outside of acceptable range:" << std::endl;
      std::cout << "Desired: " << truePyroTime[i] << std::endl;
      std::cout << "Actual: " << pyroTime[i] << std::endl;
    }
    return success;
  }
  catch(std::out_of_range) {
    std::cout << "out of range error" << std::endl;
    return false;
  }
}

void RocketLayerTester::split(std::string const &str, std::vector<float> &out)
{
	size_t start;
	size_t end = 0;
	std::string valueString = "";
	float value;
	while ((start = str.find_first_not_of(',', end)) != std::string::npos)
	{
		end = str.find(',', start);
		valueString = str.substr(start, end - start);
		try { 
			value = std::stof(valueString);
		}
		catch(const std::out_of_range e) {
			value = 0.0;
		}
		out.push_back(value);
	}
}

void RocketLayerTester::insertNoise(float * value, float mean, float stdDev) {
    std::random_device rd;
	std::default_random_engine numberGenerator (rd());
    std::normal_distribution<float> distN(mean, stdDev); 
    *value += distN(numberGenerator);
}
