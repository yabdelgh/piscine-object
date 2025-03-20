#ifndef LOGGER_DECORATORS_HPP
#define LOGGER_DECORATORS_HPP

#include "ILogger.hpp"
#include <ctime>
#include <sstream>
#include <string>

class LoggerDecorator : public ILogger {
protected:
    ILogger* logger_;

public:
    LoggerDecorator(ILogger* logger) : logger_(logger) {}
    virtual ~LoggerDecorator() {
        delete logger_;
    }
};

class ConstantHeaderDecorator : public LoggerDecorator {
private:
    std::string header_;

public:
    ConstantHeaderDecorator(ILogger* logger, const std::string& header)
        : LoggerDecorator(logger), header_(header) {}

    virtual void write(const std::string& message) {
        logger_->write(header_ + message);
    }
};

class TimestampHeaderDecorator : public LoggerDecorator {
public:
    TimestampHeaderDecorator(ILogger* logger) : LoggerDecorator(logger) {}

    virtual void write(const std::string& message) {
        logger_->write(getCurrentTimestamp() + " " + message);
    }

private:
    static std::string getCurrentTimestamp() {
        time_t rawtime;
        struct tm* timeinfo;
        char buffer[80];

        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        return std::string(buffer);
    }
};

#endif