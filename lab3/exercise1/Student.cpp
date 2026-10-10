#include "Student.h"
#include <iostream>

namespace ex1 {
    Student::Student(const std::string &name, const std::string &facultyNumber, int capacity)
        : name(name), facultyNumber(facultyNumber), capacity(capacity) {
        grades = new double[capacity];
        gradeCount = 0;
    }

    Student::~Student() {
        delete[] grades;
    }

    void Student::addGrade(double grade) {
        if (gradeCount >= capacity) {
            std::cout << "Cannot add grade: capacity reached.\n";
            return;
        }
        grades[gradeCount++] = grade;
    }

    int Student::findBestIndex() const {
        int bestIndex = 0;
        for (int i = 1; i < gradeCount; i++) {
            if (grades[i] > grades[bestIndex]) bestIndex = i;
        }
        return bestIndex;
    }

    double &Student::getBest() {
        return grades[findBestIndex()];
    }

    const double &Student::getByIndex(int index) const {
        return grades[index];
    }

    double Student::getAverage() const {
        double average = 0.0;
        for (int i = 0; i < gradeCount; i++) average += grades[i];
        return average / gradeCount;
    }

    void Student::print() const {
        std::cout << "Information for student: \n"
                << name << " | FN: " << facultyNumber << "\n"
                << "Best grade: " << grades[findBestIndex()] << "\n"
                << "Average grades: " << getAverage() << "\n"
                << "Grades: ";
        for (int i = 0; i < gradeCount; i++) std::cout << grades[i] << " ";
        std::cout << "\n\n";
    }
} // namespace ex1
