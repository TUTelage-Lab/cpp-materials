#ifndef LAB3_EX2_COURSE_H
#define LAB3_EX2_COURSE_H
#include <string>

namespace ex2 {
    class Student;

    class Course {
    private:
        std::string title;
        int maxStudents = 0, currentStudents = 0;
        Student **students = nullptr;

    public:
        Course(const std::string &, int);

        ~Course();

        void enroll(Student &);

        Student &getEnrolled(int);

        const Student &getEnrolled(int) const;

        friend void transfer(Student &, Course &from, Course &to);

        friend void printReport(const Course &);
    };
} // namespace ex2

#endif //LAB3_EX2_COURSE_H
