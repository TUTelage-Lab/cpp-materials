#ifndef LAB2_WAREHAUSE_H
#define LAB2_WAREHAUSE_H
#include <string>

#include "Audit.h"

class Warehouse {
private:
    std::string name;
    int itemCount;
    double totalValue;

public:
    Warehouse(const std::string &name, int itemCount, double totalValue);

    friend void Audit::inspect(const Warehouse &warehouse) const;
};


#endif //LAB2_WAREHAUSE_H
