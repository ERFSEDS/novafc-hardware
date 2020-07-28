#pragma once
#include <string>

enum LoggerLevel
{
	DEBUG = 0,
	INFO = 1,
	EVENT = 2,
	WARNING = 3,
	ERROR = 4,
	FATAL = 5
};

enum LoggerState
{
	USB = 0,
	FLASH = 1
};


class Logger
{
private:
	LoggerLevel loggerLevel;
	LoggerState loggerState;
public:
	Logger();
	void Debug(std::string message);
	void Info(std::string message);
	void Event(std::string message);
	void Warning(std::string message);
	void Error(std::string message);
	void Fatal(std::string message);
	void SetLogLevel(LoggerLevel level);
	void SetLogState(LoggerState state);
};

