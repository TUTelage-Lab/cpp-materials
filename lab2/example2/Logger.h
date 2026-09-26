#ifndef LAB2_LOGGER_H
#define LAB2_LOGGER_H
#include <iostream>
#include <ostream>
#include <string>


class Logger {
private:
    std::string prefix;

public:
    explicit Logger(const std::string &prefix) : prefix(prefix) {
    }

    void log(const std::string &message) {
        std::cout << "[" << prefix << "] " << message << std::endl;
    }

    void log(int code) {
        std::cout << "[" << prefix << "] Code: " << code << std::endl;
    }

    void log(const std::string &message, int code) {
        std::cout << "[" << prefix << "] " << message << " (code: " << code << ")" << std::endl;
    }

    void log(const std::string &message, double value) {
        std::cout << "[" << prefix << "] " << message << " = " << value << std::endl;
    }
};


#endif //LAB2_LOGGER_H
