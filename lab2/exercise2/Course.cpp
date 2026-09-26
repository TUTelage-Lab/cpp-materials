#include "Course.h"

#include <iostream>
#include <ostream>

Course::Course(const std::string &title, short maxStudents, short currentStudents) {
    this->title = title;
    this->maxStudents = maxStudents;
    this->currentStudents = currentStudents;
}

void Registrar::printReport(const Course &course) {
    std::cout << course.title << std::endl;
    std::cout << "Capacity: " << course.currentStudents << "/" << course.maxStudents << std::endl;
    std::cout << "Capacity (%): " << (double)course.currentStudents / course.maxStudents * 100 << std::endl;
}
