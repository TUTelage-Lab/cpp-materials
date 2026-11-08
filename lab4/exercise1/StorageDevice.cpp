#include <iostream>
#include "StorageDevice.h"

StorageDevice::StorageDevice(const std::string &name, const std::string &model,
                             double capacityGB)
    : Device(name, model), capacityGB(capacityGB), usedGB(0) {
}

bool StorageDevice::write(double sizeGB) {
    if (usedGB + sizeGB > capacityGB) {
        std::cout << name << ": write failed — not enough space (" << (capacityGB - usedGB) << "GB free)\n";
        return false;
    }
    usedGB += sizeGB;
    std::cout << name << ": wrote " << sizeGB << "GB — used " << usedGB << "/" << capacityGB << "GB\n";
    return true;
}

void StorageDevice::erase() {
    usedGB = 0;
    std::cout << name << ": storage erased\n";
}

double StorageDevice::usedPercent() const {
    return (usedGB / capacityGB) * 100.0;
}
