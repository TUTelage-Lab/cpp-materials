#ifndef LAB4_PET_H
#define LAB4_PET_H
#include "Animal.h"


class Pet : public Animal {
protected:
    std::string owner;

public:
    Pet(const std::string& name, int age, const std::string& owner);

    ~Pet();

    void describe() const;
};


#endif //LAB4_PET_H
