#include "Logger.hpp"


Logger::Logger(void* flashContext
		       FLASH_RETURN_TYPE (*flash_write) FLASH_ARGS,
		       void* transmitContext,
	       TRANSMIT_RETURN_TYPE (*transmit) TRANSMIT_ARGS) {
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

void const Logger::Debug(const char * msg, const size_t size)
{
	if (loggerLevelUSB <= DEBUG) {
		(*transmit_callback)(msg, size);
	}
	if (loggerLevelFLASH <= DEBUG) {
		(*flash_write_callback)(msg, size);
	}
}

void const Logger::Info(const char * msg, const size_t size)
{
	if (loggerLevelUSB <= INFO) {
		(*transmit_callback)(msg, size);
	}
	if (loggerLevelFLASH <= INFO) {
		(*flash_write_callback)(msg, size);
	}
}

void const Logger::Event(const char * msg, const size_t size)
{
	if (loggerLevelUSB <= EVENT) {
		(*transmit_callback)(msg, size);
	}
	if (loggerLevelFLASH <= EVENT) {
		(*flash_write_callback)(msg, size);
	}
}

void const Logger::Warning(const char * msg, const size_t size)
{
	if (loggerLevelUSB <= WARNING) {
		(*transmit_callback)(msg, size);
	}
	if (loggerLevelFLASH <= WARNING) {
		(*flash_write_callback)(msg, size);
	}
}

void const Logger::Error(const char * msg, const size_t size)
{
	if (loggerLevelUSB <= ERROR) {
		(*transmit_callback)(msg, size);
	}
	if (loggerLevelFLASH <= ERROR) {
		(*flash_write_callback)(msg, size);
	}
}

void const Logger::Fatal(const char * msg, const size_t size)
{
	if (loggerLevelUSB <= FATAL) {
		(*transmit_callback)(msg, size);
	}
	if (loggerLevelFLASH <= FATAL) {
		(*flash_write_callback)(msg, size);
	}
}
