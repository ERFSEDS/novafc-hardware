#include <iostream>
#include "Logger.hpp"
#include <iostream>
#include <string>

#include "LowLevelSimulator.hpp"


int main() {
  LowLevelSimulator sim;
  Logger logger( &(LowLevelSimulator::flash_write_callback),
		 (void*)(&sim),
		 &(LowLevelSimulator::transmit_callback),
		 (void*)(&sim));
  
  logger.SetLogLevelUSB(DEBUG);
  logger.Debug("Test DEBUG", 11);
  return 0;
}
