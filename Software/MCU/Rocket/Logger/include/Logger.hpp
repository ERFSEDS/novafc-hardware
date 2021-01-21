#pragma once
#include <string>

#define DEFAULT_USB_LOG_LEVEL 		(EVENT)
#define DEFAULT_FLASH_LOG_LEVEL		(EVENT)
#define FLASH_RETURN_TYPE void
#define FLASH_ARGS (void *, const char *, const size_t)
#define TRANSMIT_RETURN_TYPE void
#define TRANSMIT_ARGS (void *, const char *, const size_t)

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
		void const Debug(const char * msg, const size_t size);
		void const Info(const char * msg, const size_t size);
		void const Event(const char * msg, const size_t size);
		void const Warning(const char * msg, const size_t size);
		void const Error(const char * msg, const size_t size);
		void const Fatal(const char * msg, const size_t size);
		void SetLogLevelUSB(LoggerLevel level);
		void SetLogLevelFLASH(LoggerLevel level);
	
		Logger(void* flashContext
		       FLASH_RETURN_TYPE (*flash_write) FLASH_ARGS,
		       void* transmitContext,
		       TRANSMIT_RETURN_TYPE (*transmit) TRANSMIT_ARGS);
private:
		LoggerLevel loggerLevelUSB;
		LoggerLevel loggerLevelFLASH;
  TRANSMIT_RETURN_TYPE (*transmit_callback) TRANSMIT_ARGS;
  FLASH_RETURN_TYPE (*flash_write_callback) FLASH_ARGS;
  void * transmitContext;
  void * flashContext;
};

