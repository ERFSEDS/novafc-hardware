#include "Logger.h"
#include <iostream>
#include <string>

Logger::Logger(void)
{
    loggerState = DEBUG;
}

void Logger::SetLogLevel(LoggerLevel level)
        {
            loggerState = level;
        }

void Logger::Debug(std::string message)
    {
        if (loggerState <= DEBUG)
        {
            std::cout << "[DEBUG]: " << message << std::endl;
        }
    }

void Logger::Info(std::string message)
    {
        if (loggerState <= INFO)
        {
            std::cout << "[INFO]: " << message << std::endl;
        }
    }

void Logger::Event(std::string message)
    {
        if (loggerState <= EVENT)
        {
            std::cout << "[EVENT]: " << message << std::endl;
        }
    }

void Logger::Warning(std::string message)
    {
        if (loggerState <= WARNING)
        {
            std::cout << "[WARNING]: " << message << std::endl;
        }
    }

void Logger::Error(std::string message)
    {
        if (loggerState <= ERROR)
        {
            std::cout << "[ERROR]: " << message << std::endl;
        }
    }

void Logger::Fatal(std::string message)
    {
        if (loggerState <= FATAL)
        {
            std::cout << "[FATAL]: " << message << std::endl;
        }
    }



