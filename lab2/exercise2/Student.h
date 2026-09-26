#ifndef LAB2_STUDENT_H
#define LAB2_STUDENT_H
#include <string>

class Course;

class Student {
private:
    std::string name;
    std::string facultyNumber;

public:
    Student(const std::string &name, const std::string &facultyNumber);

    friend void enroll(Student &student, Course &course);
};


#endif //LAB2_STUDENT_H
