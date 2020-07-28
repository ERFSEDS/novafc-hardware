#include "Logger.h"
#include <iostream>
#include <string>

Logger::Logger(void)
{
	loggerLevel = DEBUG;
	loggerState = FLASH;
}

void Logger::SetLogLevel(LoggerLevel level)
{
	loggerLevel = level;
}

void Logger::SetLogState(LoggerState state)
{
	loggerState = state;
}

void Logger::Debug(std::string message)
{
	if (loggerLevel <= DEBUG)
	{
		switch (loggerState)
		{
		case FLASH:
			std::cout << "[DEBUG]: Flash: " << message << std::endl;
			break;
		case USB:
			std::cout << "[DEBUG]: USB: " << message << std::endl;
			break;
		}
	}
}

void Logger::Info(std::string message)
{
	if (loggerLevel <= INFO)
	{
		switch (loggerState)
		{
		case FLASH:
			std::cout << "[INFO]: Flash: " << message << std::endl;
			break;
		case USB:
			std::cout << "[INFO]: USB: " << message << std::endl;
			break;
		}
	}
}

void Logger::Event(std::string message)
{
	if (loggerLevel <= EVENT)
	{
		switch (loggerState)
		{
		case FLASH:
			std::cout << "[EVENT]: Flash: " << message << std::endl;
			break;
		case USB:
			std::cout << "[EVENT]: USB: " << message << std::endl;
			break;
		}
	}
}

void Logger::Warning(std::string message)
{
	if (loggerLevel <= WARNING)
	{
		switch (loggerState)
		{
		case FLASH:
			std::cout << "[WARNING]: Flash: " << message << std::endl;
			break;
		case USB:
			std::cout << "[WARNING]: USB: " << message << std::endl;
			break;
		}
	}
}

void Logger::Error(std::string message)
{
	if (loggerLevel <= ERROR)
	{
		switch (loggerState)
		{
		case FLASH:
			std::cout << "[ERROR]: Flash: " << message << std::endl;
			break;
		case USB:
			std::cout << "[ERROR]: USB: " << message << std::endl;
			break;
		}
	}
}

void Logger::Fatal(std::string message)
{
	if (loggerLevel <= FATAL)
	{
		switch (loggerState)
		{
		case FLASH:
			std::cout << "[FATAL]: Flash: " << message << std::endl;
			break;
		case USB:
			std::cout << "[FATAL]: USB: " << message << std::endl;
			break;
		}
	}
}
