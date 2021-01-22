#include "Logger.hpp"


Logger::Logger(void* flashContext,
	       void (*flash_write) (void*, std::string),
	       void* transmitContext,
	       void  (*transmit) (void*, std::string)) {
  this->transmitContext = transmitContext;
  this->flashContext = flashContext;
  this->transmit_callback = transmit;
  this->flash_write_callback = flash_write;
}

void Logger::SetLogLevelUSB(const LoggerLevel level) {
	this->loggerLevelUSB = level;
}

void Logger::SetLogLevelFLASH(const LoggerLevel level) {
	this->loggerLevelFLASH = level;
}

void const Logger::Debug(std::string message)
{
	if (loggerLevelUSB <= DEBUG) {
	  (*transmit_callback)(transmitContext, message);
	}
	if (loggerLevelFLASH <= DEBUG) {
	  (*flash_write_callback)(flashContext,message);
	}
}

void const Logger::Info(std::string message)
{
	if (loggerLevelUSB <= INFO) {
	  (*transmit_callback)(transmitContext, message);
	}
	if (loggerLevelFLASH <= INFO) {
	  (*flash_write_callback)(flashContext, message);
	}
}

void const Logger::Event(std::string message)
{
	if (loggerLevelUSB <= EVENT) {
	  (*transmit_callback)(transmitContext, message);
	}
	if (loggerLevelFLASH <= EVENT) {
	  (*flash_write_callback)(flashContext, message);
	}
}

void const Logger::Warning(std::string message)
{
	if (loggerLevelUSB <= WARNING) {
	  (*transmit_callback)(transmitContext, message);
	}
	if (loggerLevelFLASH <= WARNING) {
	  (*flash_write_callback)(flashContext, message);
	}
}

void const Logger::Error(std::string message)
{
	if (loggerLevelUSB <= ERROR) {
	  (*transmit_callback)(transmitContext, message);
	}
	if (loggerLevelFLASH <= ERROR) {
	  (*flash_write_callback)(flashContext, message);
	}
}

void const Logger::Fatal(std::string message)
{
	if (loggerLevelUSB <= FATAL) {
	  (*transmit_callback)(transmitContext, message);
	}
	if (loggerLevelFLASH <= FATAL) {
	  (*flash_write_callback)(flashContext, message);
	}
}
