#include <iostream>
#include "Logger.hpp"


//Should print [ERROR]: Test Error
int main() {
	Logger::SetLogLevelUSB(DEBUG);
	Logger::Debug("Test DEBUG");
	return 0;
}
