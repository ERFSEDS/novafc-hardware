#include "LowLevelSimulator.hpp"
#include <iostream> //TODO REMOVE THIS


LowLevelSimulator::LowLevelSimulator(bool printMessage) :armed(false), fired{false}, printMessage(printMessage) {
}
void LowLevelSimulator::arm_callback(void * context, bool arm) {
  reinterpret_cast<LowLevelSimulator*>(context)->arm_callback_i(arm);
}
void LowLevelSimulator::fire_callback(void * context, int channel) {
  reinterpret_cast<LowLevelSimulator*>(context)->fire_callback_i(channel);
}
void LowLevelSimulator::flash_write_callback(void* context, std::string message) {
  reinterpret_cast<LowLevelSimulator*>(context)->flash_write_callback_i(message);
}
void LowLevelSimulator::transmit_callback(void* context, std::string message) {
  reinterpret_cast<LowLevelSimulator*>(context)->transmit_callback_i(message);
}


void LowLevelSimulator::arm_callback_i(bool arm) {
  armed = arm;
}
void LowLevelSimulator::fire_callback_i(int channel) {
  if( (channel < 0) || (channel >= NUMBER_OF_PYROS) ) {
    std::cout << "Pyro out of bounds: " << channel << std::endl;
    return;
  }
  std::cout << "Pyro " << channel << "fired" << std::endl;
  fired[channel] = true;
  
}
void LowLevelSimulator::flash_write_callback_i(std::string message) {
  if(printMessage) {
    std::cout << "[FLASH]: " << message << std::endl;
  }
}
void LowLevelSimulator::transmit_callback_i(std::string message) {
  if(printMessage) {
    std::cout << "[TRANSMIT]: " << message << std::endl;
  }
}


void LowLevelSimulator::setArmed(bool armed) {
  this->armed = armed;
}
void LowLevelSimulator::setFired(int index, bool status) {
  if( (index < 0) || (index >= NUMBER_OF_PYROS) ) {
    std::cout << "Index out of range" << std::endl;
  }
  fired[index] = status;
}
bool LowLevelSimulator::getArmed() {
  return armed;
}
bool LowLevelSimulator::getFired(int index) {
  return fired[index];
}
