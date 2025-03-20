#ifndef __FILE_LOGGER_HPP__
#define __FILE_LOGGER_HPP__

#include "ILogger.hpp"
#include <fstream>
#include <string>

class FileLogger : public ILogger {
private:
    std::ofstream file_;
public:
    FileLogger(const std::string& filename) {
        file_.open(filename.c_str());
    }

    virtual ~FileLogger() {
        file_.close();
    }

    void write(const std::string& message) {
        file_ << message << std::endl;
    }
};

#endif