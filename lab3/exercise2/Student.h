#ifndef LAB3_EX2_STUDENT_H
#define LAB3_EX2_STUDENT_H
#include <string>

namespace ex2 {
    class Course;

    class Student {
    private:
        std::string name, facultyNumber;

    public:
        Student(const std::string &name, const std::string &facultyNumber);

        const std::string &getName() const;

        const std::string &getFacultyNumber() const;

        friend void transfer(Student &, Course &from, Course &to);
    };
} // namespace ex2

#endif //LAB3_EX2_STUDENT_H
