#pragma once
#include "Configuraton.hpp"

class LowLevelSimulator {
public:
  LowLevelSimulator();
  static void arm_callback(void * context, bool arm);
  static void fire_callback(void * context, int channel);
  static void flash_write_callback(void* context, const char * msg, const size_t size);
  static void transmit_callback(void* context, const char * msg, const size_t size);

  void arm_callback_i(bool arm);
  void fire_callback_i(int channel);
  void flash_write_callback_i(const char * msg, const size_t size);
  void transmit_callback_i(const char *msg, const size_t size);
  
  void setArmed(bool armed);
  void setFired(int index, bool status);
  bool getArmed();
  bool getFired(int index);

private:
  bool armed;
  bool fired[NUMBER_OF_PYROS];
}
