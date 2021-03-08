#include "LayerTester.hpp"
#include "RocketLayer.hpp"
#include "MessageHandler.hpp"
#include "Cartesian.hpp"
#include <iostream>
RocketLayerTester::RocketLayerTester(std::string inputFile,
				     int (*checkPyros)(void*, SensorData),
				     void* pyroCheckerContext,
				     Messages * messages,
				     int numMessages) {
  this->inputFile.open(inputFile);
}
RocketLayerTester::runSimulation() {
  uint8_t configBytes[75];//I set this through messsages doesnt matter
  LowLevelSimulator board;
  RocketLayer rocket(&(LowLevelSimulator::arm_callback), (void*)(&board),
		     &(LowLevelSimulator::fire_callback), (void*)(&board),
		     &(LowLevelSimulator::flash_write_callback), (void*)(&board),
		     &(LowLevelSimulator::transmit_callback), (void*)(&board),
		     configBytes, 0.1, {0, 9.81, 0}, 101);
  MessageHandler handler(1);

  //configuration message
  Message message;
  FieldMessage pyroZero;
  FieldMessage pyroOne;
  FieldMessage pyroTwo;
  FieldMessage setOneStage;
  FieldMessage setAccelOnly;

  ActionMessage arm;

  //this is to test the stage feature, because the rocket data is from a 1 stage rocket the state
  //machine will still be treated like a 1 stage rocket
  pyroZero.type = pyroChannel;
  pyroZero.set = true;
  pyroZero.valueInt = 0;
  pyroZero.pyro = {STATE, (int)(STAGE1COAST), TIME_DELAY, 5.0, true};// five seconds after burnout

  pyroOne.type = pyroChannel;
  pyroOne.set = true;
  pyroOne.valueInt = 2;
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

  arm.type = arm;

  message.fields.push_back(pyroZero);
  message.fields.push_back(pyroOne);
  message.fields.push_back(pyroTwo);
  message.fields.push_back(setOneStage);
  message.fields.push_back(setAccelOnly);

  message.actions.push_pack(arm);

  std::vector<uint8_t> messageBytes = generateMessage(message);
  std::cout << "Configuration message generated. Size: " << messageBytes.size() << std::endl;

  uint8_t bytes[messageBytes.size()];
  std::copy(messageBytes.begin(), messageBytes.end(), bytes);
  
  rocket.handleMessage(bytes, messageBytes.size());
  try {
    //If I dont fix this terrible code when youre seeing this send me a message - Nathan R
    std::cout << "Starting Simulation" << std::endl;
    bool success = true;
    std::string line;
    fileIn>>line;
		
    std::vector<float> arguements;
    //this->split(line, arguements);
    //TODO check these to ensure consistency
    float timeStep, stepNum, accelX, accelY, accelZ, gyroX, gyroY, gyroZ, pressure, trueAltitude, trueAngle;
		
    float altitude, angle;
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
		
    while(!fileIn.eof()) {
      fileIn>>line;
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
			
      insertNoise(&accelX, accelNoiseMean, accelNoiseSTD);
      insertNoise(&accelY, accelNoiseMean, accelNoiseSTD);
      insertNoise(&accelZ, accelNoiseMean, accelNoiseSTD);
			

      insertNoise(&gyroX, gyroNoiseMean, gyroNoiseSTD);
      insertNoise(&gyroY, gyroNoiseMean, gyroNoiseSTD);
      insertNoise(&gyroZ, gyroNoiseMean, gyroNoiseSTD);
      Cartesian acceleration = {accelX, accelY, accelZ};
      Cartesian gyro = {gyroX, gyroY, gyroZ};
			
      if (i >= subSampleRate) {
	if((int)(timeStep*10) == 10*timeStep) {
	  std::cout << "time step: " << timeStep <<std::endl;
	}
	this->rocket.updateAcceleration(acceleration);
	this->rocket.updateRotation(gyro);
				
	this->rocket.updatePressure(pressure);
	//Cartesian val = sensors.getAcceleration(); prety sure this isnt used.....
				
	this->rocket.update();
	altitude = rocket.getAltitude(); 
	angle = rocket.getAngleFromVertical();
				
	Cartesian vec = rocket.getAcceleration();
	//This is stuff so you can see where the rocket state module is at when its passing data, does not fail the test(unless there is a math error resulting in no altitude
	float altitudeError = std::abs(altitude - trueAltitude)/trueAltitude; 
	float angleError = std::abs(angle - trueAngle)/trueAngle;
	float altitudeDifference = std::abs(altitude - trueAltitude);
	float angleDifference = std::abs(angle - trueAngle);
	if(altitude != altitude) { //checks for NAN
	  std::cout << "ALtitude is NAN" << std::endl;
	  success = false;
	}
				
	if( (altitudeError > ACCEPTABLE_ALTITUDE_ERROR) && (altitudeDifference > ACCEPTABLE_ALTITUDE_ERROR_ABS) ) {
	  std::cout << "Time is: " << timeStep << std::endl;
	  std::cout << "Altitude outside acceptable bounds" <<std::endl;
	  std::cout << "True Altitude: " << trueAltitude << std::endl;
	  std::cout << "Measured Altitude: " << altitude << std::endl;
	  std::cout << std::endl;
	}
	if( (angleError > ACCEPTABLE_ANGLE_ERROR) && (angleDifference > ACCEPTABLE_ANGLE_ERROR_ABS)) {
	  std::cout << "Time is: " << timeStep << std::endl;
	  std::cout << "Angle outside acceptable bounds" <<std::endl;
	  std::cout << "True Angle: " << trueAngle << std::endl;
	  std::cout << "Measured Angle: " << (angle * (180/M_PI)) << " degrees" << std::endl;
	  std::cout << std::endl;
	}
	i=1;
				
				
	//BRAIN STUFF
				
	this->brain.check();
	//check each pyro
	std::stringstream events("");
	for(int i = 0; i < NUMBER_OF_PYROS; i++) {
	  if(pyros[i] && (pyroTime[i] == -1)) {
	    pyroTime[i] = timeStep;
	    events <<"Pyro " << i << " fired--"; 
	    std::cout << "Pyro " << i << " fired at " << timeStep << std::endl;
	  }
	} 
				
	//determine the true times it should run
	//sets pyro 0 to fire at apogee,
	if( (lastAltitude > trueAltitude) && (truePyroTime[0] == -1) ) {
	  truePyroTime[0] = timeStep;
	  events << "Pyro 0 should have fired--";
	  std::cout << "Pyro 0 should fire at " << timeStep << std::endl;
	} 
	//pyro 1 to fire at 200m and past apogee, 
	if( (trueAltitude < 200) && (lastAltitude > trueAltitude) && (truePyroTime[1] == -1) ) {
	  truePyroTime[1] = timeStep;
	  events << "Pyro 1 should have fired--";
	  std::cout << "Pyro 1 should fire at " << timeStep << std::endl;
	} 
				
	this->fileOut << timeStep << ", " << altitude << ", " << trueAltitude << ", " <<  altitudeError << ", " << angle << ", " << angleError << events.str() << std::endl;
      }
      else {
	i++;
      }
      lastAltitude=trueAltitude;
    }
    this->fileOut.close();
		
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
