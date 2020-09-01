#include <iostream>
#include "Logger.hpp"


//Should print [ERROR]: Test Error
int main() {
	Logger::SetLogLevelUSB(EVENT);
	Logger::Event("Test Event");
	return 0;
}
