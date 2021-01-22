#include "Logger.hpp"
#include "LowLevelSimulator.hpp"


int main() {
  LowLevelSimulator sim;
  Logger logger( (void*)(&sim),
		&(LowLevelSimulator::flash_write_callback),
		 (void*)(&sim),
		 &(LowLevelSimulator::transmit_callback));
  
  logger.SetLogLevelUSB(DEBUG);
  logger.Error("Test Error");
  return 0;
}
