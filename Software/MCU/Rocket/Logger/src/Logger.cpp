#include "Logger.hpp"


Logger Logger::INSTANCE;

Logger::Logger(void) :	loggerLevelUSB(DEFAULT_USB_LOG_LEVEL),
						loggerLevelFLASH(DEFAULT_FLASH_LOG_LEVEL),
						transmit_callback(nullptr),
						flash_write_callback(nullptr)
{
}
Logger::~Logger(void)
{

}

void Logger::setTransmitCallback_I(TRANSMIT_CALLBACK) {
	this->transmit_callback = transmit_callback;
}
void Logger::setFlashWriteCallback_I(FLASH_WRITE_CALLBACK) {
	this->flash_write_callback = flash_write_callback;
}
void Logger::SetLogLevelUSB_I(const LoggerLevel level) {
	this->loggerLevelUSB = level;
}

void Logger::SetLogLevelFLASH_I(const LoggerLevel level) {
	this->loggerLevelFLASH = level;
}

void const Logger::Debug_I(const char * msg, const size_t size)
{
	if (loggerLevelUSB <= DEBUG) {
		(*transmit_callback)(msg, size);
	}
	if (loggerLevelFLASH <= DEBUG) {
		(*flash_write_callback)(msg, size);
	}
}

void const Logger::Info_I(const char * msg, const size_t size)
{
	if (loggerLevelUSB <= INFO) {
		(*transmit_callback)(msg, size);
	}
	if (loggerLevelFLASH <= INFO) {
		(*flash_write_callback)(msg, size);
	}
}

void const Logger::Event_I(const char * msg, const size_t size)
{
	if (loggerLevelUSB <= EVENT) {
		(*transmit_callback)(msg, size);
	}
	if (loggerLevelFLASH <= EVENT) {
		(*flash_write_callback)(msg, size);
	}
}

void const Logger::Warning_I(const char * msg, const size_t size)
{
	if (loggerLevelUSB <= WARNING) {
		(*transmit_callback)(msg, size);
	}
	if (loggerLevelFLASH <= WARNING) {
		(*flash_write_callback)(msg, size);
	}
}

void const Logger::Error_I(const char * msg, const size_t size)
{
	if (loggerLevelUSB <= ERROR) {
		(*transmit_callback)(msg, size);
	}
	if (loggerLevelFLASH <= ERROR) {
		(*flash_write_callback)(msg, size);
	}
}

void const Logger::Fatal_I(const char * msg, const size_t size)
{
	if (loggerLevelUSB <= FATAL) {
		(*transmit_callback)(msg, size);
	}
	if (loggerLevelFLASH <= FATAL) {
		(*flash_write_callback)(msg, size);
	}
}

Logger &Logger::GET_INSTANCE() {
	return INSTANCE;
}


void const Logger::Debug(const char * msg, const size_t size) {
	Logger::GET_INSTANCE().Debug_I(msg, size);
}
void const Logger::Info(const char * msg, const size_t size) {
	Logger::GET_INSTANCE().Info_I(msg, size);
}
void const Logger::Event(const char * msg, const size_t size) {
	Logger::GET_INSTANCE().Event_I(msg, size);
}
void const Logger::Warning(const char * msg, const size_t size) {
	Logger::GET_INSTANCE().Warning_I(msg, size);
}
void const Logger::Error(const char * msg, const size_t size) {
	Logger::GET_INSTANCE().Error_I(msg, size);
}
void const Logger::Fatal(const char * msg, const size_t size) {
	Logger::GET_INSTANCE().Fatal_I(msg, size);
}
void Logger::SetLogLevelUSB(LoggerLevel level) {
	Logger::GET_INSTANCE().SetLogLevelUSB_I(level);
}
void Logger::SetLogLevelFLASH(LoggerLevel level) {
	Logger::GET_INSTANCE().SetLogLevelFLASH_I(level);
}
void Logger::setTransmitCallback(TRANSMIT_CALLBACK) {
	Logger::GET_INSTANCE().setTransmitCallback_I(transmit_callback);	
}
void Logger::setFlashWriteCallback(FLASH_WRITE_CALLBACK) {
	Logger::GET_INSTANCE().setFlashWriteCallback_I(flash_write_callback);
}
