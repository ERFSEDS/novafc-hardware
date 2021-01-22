#pragma once
#include "Configuration.hpp"
#include "CommonDefines.hpp"
#include <string>
class LowLevelSimulator {
public:
  LowLevelSimulator();
  static void arm_callback(void * context, bool arm);
  static void fire_callback(void * context, int channel);
  static void flash_write_callback(void* context, std::string str);
  static void transmit_callback(void* context, std::string str);

  void arm_callback_i(bool arm);
  void fire_callback_i(int channel);
  void flash_write_callback_i(std::string str);
  void transmit_callback_i(std::string str);
  
  void setArmed(bool armed);
  void setFired(int index, bool status);
  bool getArmed();
  bool getFired(int index);

private:
  bool armed;
  bool fired[NUMBER_OF_PYROS];
};
