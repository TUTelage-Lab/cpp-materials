#ifndef LAB3_EX1_STUDENT_H
#define LAB3_EX1_STUDENT_H
#include <string>

namespace ex1 {
    class Student {
    private:
        std::string name, facultyNumber;
        double *grades = nullptr;
        int capacity = 0, gradeCount = 0;

        int findBestIndex() const;

    public:
        Student(const std::string &name, const std::string &facultyNumber, int capacity = 10);

        ~Student();

        void addGrade(double grade);

        double &getBest();

        const double &getByIndex(int index) const;

        double getAverage() const;

        void print() const;
    };
} // namespace ex1

#endif //LAB3_EX1_STUDENT_H
