#pragma once
#include <string>

#define DEFAULT_USB_LOG_LEVEL 		(EVENT)
#define DEFAULT_FLASH_LOG_LEVEL		(EVENT)


enum LoggerLevel
{
	DEBUG = 0,
	INFO = 1,
	EVENT = 2,
	WARNING = 3,
	ERROR = 4,
	FATAL = 5
};

enum LoggerOuts
{
	USB = 0,
	FLASH = 1
};


class Logger
{
	public:
  void const Debug(std::string);
		void const Info(std::string);
       	void const Event(std::string);
		void const Warning(std::string);
		void const Error(std::string);
		void const Fatal(std::string);
		void SetLogLevelUSB(LoggerLevel level);
		void SetLogLevelFLASH(LoggerLevel level);
	
  Logger(void* flashContext,
	 void (*flash_write) (std::string),
		       void* transmitContext,
	 void (*transmit) (std::string));
private:
		LoggerLevel loggerLevelUSB;
		LoggerLevel loggerLevelFLASH;
  void (*transmit_callback) (std::string);
  void (*flash_write_callback) (std::string);
  void * transmitContext;
  void * flashContext;
};

