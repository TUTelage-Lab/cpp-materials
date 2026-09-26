#ifndef LAB2_AUDIT_H
#define LAB2_AUDIT_H
#include <string>

class Warehouse;

class Audit {
private:
    std::string name;

public:
    explicit Audit(const std::string &name) : name(name) {
    }

    void inspect(const Warehouse &warehouse) const;
};


#endif //LAB2_AUDIT_H
