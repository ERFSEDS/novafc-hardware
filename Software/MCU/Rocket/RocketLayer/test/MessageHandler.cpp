#include <exception>
#include "MessageHandler.hpp"
#include <iostream>
MessageHandler::MessageHandler(uint8_t address) : address(address) {

}
std::vector<uint8_t> MessageHandler::generateMessage(Message message, uint8_t destAddress) {
	std::vector<uint8_t> messageBytes; //initial size to make this more efficent
	messageBytes.push_back(MESSAGE_VERSION); 
	messageBytes.push_back(0); //this is length needs to be updated with correct value at the end
	messageBytes.push_back(COMMAND_TYPE);
	messageBytes.push_back(this->address);//src address
	messageBytes.push_back(destAddress);//destination address
	
	//Field Sections (TRUST Me this is much nicer than the MCU side lol
	//redoing this would be a good future project
	messageBytes.push_back(message.fields.size());
	for(auto field = message.fields.begin(); field != message.fields.end(); field++) {
		messageBytes.push_back( (int)(field->type) );
		messageBytes.push_back( (int)(field->set) );
		if(field->set) {
			switch(field->type) {// maybe I should use that union..... TODO
			case pressure: //use value
			case altitude: //use value
			case ignitionThreshold: //use value
			case cutoffThreshold: //use value
				if(field->set) {
					getFloat(messageBytes, field->value);
				}
				break;
			case acceleration: //use vector
			case angularVelocity: //use vector
				for(int i=0;i<3;i++) {
					getFloat(messageBytes, field->vector[i]);
				}
				break;
			case orientation://use quanternion
				for(int i=0;i<4;i++) {
					getFloat(messageBytes, field->quanternion[i]);
				}
				break;
			case rocketState: //use valueInt
			case altitudeDetermination: //use valueInt
			case boardType: //use valueInt
			case addrress: //use valueInt
			case softwareVersion: //use valueInt
			case hardwareVersion: //use valueInt
			case testSimulation: //use valueInt(0 for false 1 for true)
			case twoStage: //use valueInt(0 for false 1 for true)
				messageBytes.push_back( (int)(field->valueInt) );
				break;
			case pyroChannel: //use pyro
				messageBytes.push_back( (int)(field->valueInt) );
				messageBytes.push_back( (int)(field->pyro.configOne) );
				getFloat(messageBytes, field->pyro.valueOne);
				messageBytes.push_back( (int)(field->pyro.configTwo) );
				getFloat(messageBytes, field->pyro.valueOne);
				messageBytes.push_back( (int)(field->pyro.tiltLock) );
				break;
			}
		}
		else {
			switch(field->type) {
			case pyroChannel: //use pyro
				messageBytes.push_back( (int)(field->valueInt) );
				break;
			}
		}
	}
	//Field Sections (TRUST Me this is much nicer than the MCU side lol
	//redoing this would be a good future project
	messageBytes.push_back(message.actions.size());
	for(auto action = message.actions.begin(); action != message.actions.end(); action++) {
		messageBytes.push_back( (int)(action->type) );
		switch(action->type) {
		case firePyro:
		case pyroCorrect:
			messageBytes.push_back( (int)(action->value) );
		}
	}
	messageBytes.at(MESSAGE_LENGTH_BYTE) = messageBytes.size();
	
	
	std::vector<uint8_t> msg;
	for(auto byte = messageBytes.begin(); byte != messageBytes.end(); byte++) {
		switch(*byte) {
		case 0:
			msg.push_back(ESCAPE_INT);
			msg.push_back(ESCAPE_0);
			break;
		case 1:
			msg.push_back(ESCAPE_INT);
			msg.push_back(ESCAPE_1);
			break;
		default:
			msg.push_back(*byte);
		}
	}
	msg.push_back(ESCAPE_INT);
	msg.push_back(ESCAPE_END_MSG);
	return msg;
}
Message MessageHandler::handlerResponse(std::vector<uint8_t> msg) {//TODO refactor to use an iterator, would make this cleaner and more efficent
	Message message;
	uint8_t version = msg.at(0);
	uint8_t length = msg.at(1);
	uint8_t commandResponse = msg.at(2);
	uint8_t srcAddress = msg.at(3);
	uint8_t destAddress= msg.at(4);
	msg.erase(msg.begin());
	msg.erase(msg.begin());
	msg.erase(msg.begin());
	msg.erase(msg.begin());
	msg.erase(msg.begin());
	
	if(version != MESSAGE_VERSION) {
		throw "Incorrect Version";
	}
	if(commandResponse != RESPONSE_TYPE) {
		throw "cant handle commands to me";
	}
	if(destAddress != this->address) {
		return message; //not for me
	}
	
	int numFields = (int)msg.at(0);
	msg.erase(msg.begin());
	for(int i = 0; i < numFields; i++) {
		FieldMessage field;
		field.type = (Fields)(int)msg.at(0);
		msg.erase(msg.begin());
		field.set = (int)msg.at(0);
		msg.erase(msg.begin());
		if(field.set == FIELD_SET) {
			field.valueInt = (int)msg.at(0);
			msg.erase(msg.begin());
		}
		else {
			switch(field.type) {// maybe I should use that union..... TODO
			case pressure: //use value
			case altitude: //use value
			case ignitionThreshold: //use value
			case cutoffThreshold: //use value
				field.value = getFloat(msg);
				msg.erase(msg.begin());
				msg.erase(msg.begin());
				msg.erase(msg.begin());
				msg.erase(msg.begin());
				break;
			case acceleration: //use vector
			case angularVelocity: //use vector
				for(int i=0;i<3;i++) {
					field.vector[i] = getFloat(msg);
					msg.erase(msg.begin());
					msg.erase(msg.begin());
					msg.erase(msg.begin());
					msg.erase(msg.begin());
				}
				break;
			case orientation://use quanternion
				for(int i=0;i<4;i++) {
					field.quanternion[i] = getFloat(msg);
					msg.erase(msg.begin());
					msg.erase(msg.begin());
					msg.erase(msg.begin());
					msg.erase(msg.begin());
				}
				break;
			case rocketState: //use valueInt
			case altitudeDetermination: //use valueInt
			case boardType: //use valueInt
			case addrress: //use valueInt
			case softwareVersion: //use valueInt
			case hardwareVersion: //use valueInt
			case testSimulation: //use valueInt(0 for false 1 for true)
			case twoStage: //use valueInt(0 for false 1 for true)
				field.valueInt = msg.at(0);
				msg.erase(msg.begin());
				break;
			case pyroChannel: //use pyro
				field.pyro.configOne = (PyroConfig)(int)msg.at(0);
				field.pyro.valueOne = getFloat(msg, 1);
				field.pyro.configTwo = (PyroConfig)(int)msg.at(5);
				field.pyro.valueTwo = getFloat(msg, 6);
				field.pyro.tiltLock = (int)msg.at(10);
				for(int i = 0; i < 11; i++) {
					msg.erase(msg.begin());
				}
				break;
			}
		}
		message.fields.push_back(field);
	}
	
	int numActions = msg.at(0);
	msg.erase(msg.begin());
	for(int i = 0; i < numActions; i++) {
		ActionMessage action;
		action.type = (Actions)(int)msg.at(0);
		msg.erase(msg.begin());
		action.returnStatus= msg.at(0);
		msg.erase(msg.begin());
	}
	return message;
}
float MessageHandler::getFloat(std::vector<uint8_t> message, int offset) {
  uint32_t bytes = (message.at(offset) << 24) +
    (message.at(offset+1) << 16) +
    (message.at(offset+2) << 8 ) +
    (message.at(offset+3));
  return *(reinterpret_cast<float*>(&bytes));
}
void MessageHandler::getFloat(std::vector<uint8_t> message, float valueF) {
  uint32_t* value = reinterpret_cast<uint32_t*>(&valueF);
  message.push_back((*value & (0xFF << 24)) >> 24);
  message.push_back((*value & (0xFF << 16)) >> 16);
  message.push_back((*value & (0xFF << 8)) >> 8);
  message.push_back(*value & (0xFF));
}
