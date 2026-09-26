#include <iostream>

#include "Time.h"

Time::Time() {
    std::cout << "Time object created with default values" << std::endl;
}

Time::~Time() {
    std::cout << "Time destroyed!" << std::endl;
}

void Time::setTime(short h, short m, short s) {
    if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
        std::cout << "Invalid time values!" << std::endl;
        exit(1);
    }
    hour = h;
    minute = m;
    second = s;
}

void Time::printTime() const {
    std::cout << "24h: "
            << (hour < 10 ? "0" : "") << hour << ":"
            << (minute < 10 ? "0" : "") << minute << ":"
            << (second < 10 ? "0" : "") << second
            << std::endl;

    short h12 = hour % 12;
    if (h12 == 0) {
        h12 = 12;
    }
    const char *suffix = (hour < 12) ? "AM" : "PM";
    std::cout << "12h: "
            << (h12 < 10 ? "0" : "") << h12 << ":"
            << (minute < 10 ? "0" : "") << minute << ":"
            << (second < 10 ? "0" : "") << second << " " << suffix
            << std::endl;
}
