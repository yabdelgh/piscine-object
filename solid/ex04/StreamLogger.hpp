#ifndef __STREAM_LOGGER_HPP__
#define __STREAM_LOGGER_HPP__

#include "ILogger.hpp"
#include <iostream>

class StreamLogger : public ILogger {
private:
    std::ostream& stream_;
public:
    StreamLogger(std::ostream& stream) : stream_(stream) {}

    void write(const std::string& message) {
        stream_ << message << std::endl;
    }
};

#endif