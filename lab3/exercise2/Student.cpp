#include "Student.h"

namespace ex2 {
    Student::Student(const std::string &name, const std::string &facultyNumber)
        : name(name), facultyNumber(facultyNumber) {
    }

    const std::string &Student::getName() const {
        return name;
    }

    const std::string &Student::getFacultyNumber() const {
        return facultyNumber;
    }
} // namespace ex2
