#ifndef __ILOGGER_HPP__
#define __ILOGGER_HPP__

#include <string>

class ILogger {
public:
    virtual ~ILogger() {}
    virtual void write(const std::string& message) = 0;
};

#endif
