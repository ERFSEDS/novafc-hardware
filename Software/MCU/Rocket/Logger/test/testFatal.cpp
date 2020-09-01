#include <iostream>
#include "Logger.hpp"


//Should print [ERROR]: Test Error
int main() {
	Logger::SetLogLevelUSB(ERROR);
	Logger::Error("Test Error");
	return 0;
}
