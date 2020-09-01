#include <iostream>
#include "Logger.hpp"


//Should print [ERROR]: Test Error
int main() {
	Logger::SetLogLevelUSB(INFO);
	Logger::Info("Test INFO");
	return 0;
}
