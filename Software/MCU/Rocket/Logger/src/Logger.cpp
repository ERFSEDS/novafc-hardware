#include "Logger.hpp"
#include <iostream>
#include <string>


Logger Logger::INSTANCE;

Logger::Logger(void)
{
	loggerLevelUSB = DEFAULT_USB_LOG_LEVEL;
	loggerLevelFLASH = DEFAULT_FLASH_LOG_LEVEL;
}
Logger::~Logger(void)
{

}

void Logger::SetLogLevelUSB_I(LoggerLevel level) {
	this->loggerLevelUSB = level;
}

void Logger::SetLogLevelFLASH_I(LoggerLevel level) {
	this->loggerLevelFLASH = level;
}

void Logger::Debug_I(std::string message)
{
	if (loggerLevelUSB <= DEBUG) {
		std::cout << "[DEBUG]: " << message << std::endl;
	}
	if (loggerLevelFLASH <= DEBUG) {
		//TODO Add flash simulator(write to file?)
	}
}

void Logger::Info_I(std::string message)
{
	if (loggerLevelUSB <= INFO) {
		std::cout << "[INFO]: " << message << std::endl;
	}
	if (loggerLevelFLASH <= INFO) {
		//TODO Add flash simulator(write to file?)
	}
}

void Logger::Event_I(std::string message)
{
	if (loggerLevelUSB <= EVENT) {
		std::cout << "[EVENT]: " << message << std::endl;
	}
	if (loggerLevelFLASH <= EVENT) {
		//TODO Add flash simulator(write to file?)
	}
}

void Logger::Warning_I(std::string message)
{
	if (loggerLevelUSB <= WARNING) {
		std::cout << "[WARNING]: " << message << std::endl;
	}
	if (loggerLevelFLASH <= WARNING) {
		//TODO Add flash simulator(write to file?)
	}
}

void Logger::Error_I(std::string message)
{
	if (loggerLevelUSB <= ERROR) {
		std::cout << "[ERROR]: " << message << std::endl;
	}
	if (loggerLevelFLASH <= ERROR) {
		//TODO Add flash simulator(write to file?)
	}
}

void Logger::Fatal_I(std::string message)
{
	if (loggerLevelUSB <= FATAL) {
		std::cout << "[FATAL]: " << message << std::endl;
	}
	if (loggerLevelFLASH <= FATAL) {
		//TODO Add flash simulator(write to file?)
	}
}

Logger &Logger::GET_INSTANCE() {
	return INSTANCE;
}


void Logger::Debug(std::string message) {
	Logger::GET_INSTANCE().Debug_I(message);
}
void Logger::Info(std::string message) {
	Logger::GET_INSTANCE().Info_I(message);
}
void Logger::Event(std::string message) {
	Logger::GET_INSTANCE().Event_I(message);
}
void Logger::Warning(std::string message) {
	Logger::GET_INSTANCE().Warning_I(message);
}
void Logger::Error(std::string message) {
	Logger::GET_INSTANCE().Error_I(message);
}
void Logger::Fatal(std::string message) {
	Logger::GET_INSTANCE().Fatal_I(message);
}
void Logger::SetLogLevelUSB(LoggerLevel level) {
	Logger::GET_INSTANCE().SetLogLevelUSB_I(level);
}
void Logger::SetLogLevelFLASH(LoggerLevel level) {
	Logger::GET_INSTANCE().SetLogLevelFLASH_I(level);
}
