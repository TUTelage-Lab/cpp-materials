#ifndef LAB4_ANIMAL_H
#define LAB4_ANIMAL_H
#include <string>


class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(const std::string& name, int age);

    ~Animal();

    void describe() const;
};


#endif //LAB4_ANIMAL_H
