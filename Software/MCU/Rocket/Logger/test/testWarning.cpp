#include <iostream>
#include "Logger.hpp"


//Should print [ERROR]: Test Error
int main() {
	Logger::SetLogLevelUSB(WARNING);
	Logger::Warning("Test WARNING");
	return 0;
}
