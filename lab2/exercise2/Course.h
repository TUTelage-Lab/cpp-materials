#ifndef LAB2_COURSE_H
#define LAB2_COURSE_H
#include <string>

#include "Registrar.h"

class Student;

class Course {
private:
    std::string title;
    short maxStudents, currentStudents;

public:
    Course(const std::string &title, short maxStudents, short currentStudents);

    friend void Registrar::printReport(const Course &course);

    friend void enroll(Student &student, Course &course);
};


#endif //LAB2_COURSE_H
