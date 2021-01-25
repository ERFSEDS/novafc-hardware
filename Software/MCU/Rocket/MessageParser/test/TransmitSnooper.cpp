#include "TransmitSnooper.hpp"
#include <iostream>

TransmitSnooper::TransmitSnooper(bool active, void* handoffContext, void (*transmit_callback)(void*, std::string)) :
  snooping(active),
  context(handoffContext),
  transmit_callback(transmit_callback),
  expectedMsg(nullptr),
  expectedSize(0),
  messageMatch(false) {
}

void TransmitSnooper::snoop(bool snooping) {
  this->snooping = snooping;
}

void TransmitSnooper::snoopCallback(void* context, std::string msg) {
  reinterpret_cast<TransmitSnooper*>(context)->snoop_callback_i(msg);
}

void TransmitSnooper::setExpectedResponse(uint8_t *msg, size_t size) {
  expectedMsg = msg;
  expectedSize = size;
  messageMatch = false; //if they check right after this the message did not come which is not a match
}

bool TransmitSnooper::matchedExpected(){
  return messageMatch;
}
void TransmitSnooper::snoop_callback_i(std::string msg) {
  if(!snooping) {
    transmit_callback(context, msg);
    return;
  }

  uint8_t* msgPtr = (uint8_t*)(msg.c_str());
  std::cout << "snoop: <";
  for(int i = 0; i < msg.length(); i++) {
    std::cout << (int)msgPtr[i] << ", ";
  }
  std::cout <<">" << std::endl;
  if( (expectedMsg != nullptr) && (expectedSize > 0) ) {
    messageMatch = true;
    if(expectedSize != msg.length()) {
      std::cout << "Messages are different sizes" <<std::endl;
      std::cout << "Expected Size = " << expectedSize << std::endl;
      std::cout << "Actual Size = " << msg.length() << std::endl;
      messageMatch = false;
      return;
    }
    for(int i = 0; i < expectedSize; i++) {
      if(expectedMsg[i] != msgPtr[i]) {
	std::cout << "Message Byte "  << i << " does not match" << std::endl;
	std::cout << "expected: " << expectedMsg[i] << std::endl;
	std::cout << "actual: " << msgPtr[i] << std::endl;
	messageMatch = false;
      }
    }
  }
}
