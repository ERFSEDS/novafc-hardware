#pragma once
#include <string>

#define DEFAULT_USB_LOG_LEVEL 		(INFO)
#define DEFAULT_FLASH_LOG_LEVEL		(INFO)
 
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
		static void Debug(std::string message);
		static void Info(std::string message);
		static void Event(std::string message);
		static void Warning(std::string message);
		static void Error(std::string message);
		static void Fatal(std::string message);
		static void SetLogLevelUSB(LoggerLevel level);
		static void SetLogLevelFLASH(LoggerLevel level);
	

	private:
		Logger();//private constructor
		~Logger();//private decosntructor
		
		LoggerLevel loggerLevelUSB;
		LoggerLevel loggerLevelFLASH;
		static Logger INSTANCE;
	public:
		Logger(const Logger &conf) = delete; //copy constructor is not allowed

	private:
		static Logger &GET_INSTANCE();
		void Debug_I(std::string message);
		void Info_I(std::string message);
		void Event_I(std::string message);
		void Warning_I(std::string message);
		void Error_I(std::string message);
		void Fatal_I(std::string message);
		void SetLogLevelUSB_I(LoggerLevel level);
		void SetLogLevelFLASH_I(LoggerLevel level);



};

