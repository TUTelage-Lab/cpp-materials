#include "Course.h"
#include "Student.h"
#include <iostream>

namespace ex2 {
    Course::Course(const std::string &title, int maxStudents)
        : title(title), maxStudents(maxStudents), currentStudents(0) {
        students = new Student *[maxStudents];
    }

    Course::~Course() {
        delete[] students;
    }

    void Course::enroll(Student &s) {
        if (currentStudents >= maxStudents) {
            std::cout << "Course [" << title << "] is full.\n";
            return;
        }
        students[currentStudents++] = &s;
    }

    Student &Course::getEnrolled(int i) {
        return *students[i];
    }

    const Student &Course::getEnrolled(int i) const {
        return *students[i];
    }

    void transfer(Student &s, Course &from, Course &to) {
        int idx = -1;
        for (int i = 0; i < from.currentStudents; i++) {
            if (from.students[i] == &s) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            std::cout << s.getName() << " is not enrolled in " << from.title << ".\n";
            return;
        }
        for (int i = idx; i < from.currentStudents - 1; i++) {
            from.students[i] = from.students[i + 1];
        }
        from.currentStudents--;

        to.enroll(s);
        std::cout << s.getName() << " transferred from [" << from.title << "] to [" << to.title << "].\n";
    }

    void printReport(const Course &c) {
        const double fill = c.maxStudents > 0
                                ? 100.0 * c.currentStudents / c.maxStudents
                                : 0.0;
        std::cout << c.title << "\n"
                << "  Enrolled: " << c.currentStudents << " / " << c.maxStudents << "\n"
                << "  Fill:     " << fill << "%\n";
        for (int i = 0; i < c.currentStudents; i++)
            std::cout << "    - " << c.students[i]->getName()
                    << " (" << c.students[i]->getFacultyNumber() << ")\n";
    }
} // namespace ex2
