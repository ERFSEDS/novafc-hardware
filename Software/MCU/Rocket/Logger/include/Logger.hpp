#pragma once
#include <string>

#define DEFAULT_USB_LOG_LEVEL 		(EVENT)
#define DEFAULT_FLASH_LOG_LEVEL		(EVENT)
#define FLASH_WRITE_CALLBACK 	void (*flash_write_callback)(const char *, const size_t )
#define TRANSMIT_CALLBACK		void (*transmit_callback)(const char * , const size_t )


/*
	If you plan to use the logger you need to create transmit and flash write callback functions in order for the logger to know how to log
	this structure is here that way we can test the logger and get messages from it on a computer and then upload to a mcu and just change the input function
*/
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
		static void const Debug(const char * msg, const size_t size);
		static void const Info(const char * msg, const size_t size);
		static void const Event(const char * msg, const size_t size);
		static void const Warning(const char * msg, const size_t size);
		static void const Error(const char * msg, const size_t size);
		static void const Fatal(const char * msg, const size_t size);
		static void SetLogLevelUSB(LoggerLevel level);
		static void SetLogLevelFLASH(LoggerLevel level);
	
		static Logger& GET_INSTANCE();
		
		static void setTransmitCallback(TRANSMIT_CALLBACK);
		static void setFlashWriteCallback(FLASH_WRITE_CALLBACK);
	private:
		Logger();//private constructor
		~Logger();//private decosntructor
		
		LoggerLevel loggerLevelUSB;
		LoggerLevel loggerLevelFLASH;
		TRANSMIT_CALLBACK;
		FLASH_WRITE_CALLBACK;
		static Logger INSTANCE;
	public:
		Logger(const Logger &conf) = delete; //copy constructor is not allowed

	private:
		void setTransmitCallback_I(TRANSMIT_CALLBACK);
		void setFlashWriteCallback_I(FLASH_WRITE_CALLBACK);
		void const Debug_I(const char * msg, const size_t size);
		void const Info_I(const char * msg, const size_t size);
		void const Event_I(const char * msg, const size_t size);
		void const Warning_I(const char * msg, const size_t size);
		void const Error_I(const char * msg, const size_t size);
		void const Fatal_I(const char * msg, const size_t size);
		void SetLogLevelUSB_I(LoggerLevel level);
		void SetLogLevelFLASH_I(LoggerLevel level);


};

