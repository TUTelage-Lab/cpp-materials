#ifndef LAB4_DOG_H
#define LAB4_DOG_H
#include "Pet.h"


class Dog : public Pet {
private:
    std::string breed;

public:
    Dog(const std::string& name, int age, const std::string& owner, const std::string& breed);

    ~Dog();

    void describe() const;
};


#endif //LAB4_DOG_H
