#include <vector>
#include "ILogger.hpp"
#include "FileLogger.hpp"
#include "StreamLogger.hpp"
#include "LoggerDecorators.hpp"

int main() {
    std::vector<ILogger*> loggers;
    std::vector<std::string> messages;

    loggers.push_back(new FileLogger("log.txt"));
    loggers.push_back(new ConstantHeaderDecorator(
        new StreamLogger(std::cout), "[INFO] "));
    loggers.push_back(new TimestampHeaderDecorator(
        new FileLogger("timestamp_log.txt")));

    messages.push_back("System started");
    messages.push_back("Processing data...");
    messages.push_back("Shutting down");

    for (std::vector<std::string>::iterator it = messages.begin(); 
         it != messages.end(); ++it) {
        for (std::vector<ILogger*>::iterator logger = loggers.begin(); 
             logger != loggers.end(); ++logger) {
            (*logger)->write(*it);
        }
    }

    for (std::vector<ILogger*>::iterator it = loggers.begin(); 
         it != loggers.end(); ++it) {
        delete *it;
    }

    return 0;
}