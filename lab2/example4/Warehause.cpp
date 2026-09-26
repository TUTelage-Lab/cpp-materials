#include <iostream>
#include <ostream>

#include "Warehouse.h"

Warehouse::Warehouse(const std::string &name, int itemCount, double totalValue) {
    this->name = name;
    this->itemCount = itemCount;
    this->totalValue = totalValue;
}

void Audit::inspect(const Warehouse &warehouse) const {
    /*
     * TODO: whoese `this` is `this`:
     * this->name
     * and it
     * this->name
     */
    std::cout << "Inspector: " << this->name << std::endl;
    std::cout << "Warehouse: " << warehouse.name << std::endl;
    std::cout << "Item Count: " << warehouse.itemCount << std::endl;
    std::cout << "Total Value: " << warehouse.totalValue << std::endl;
}
