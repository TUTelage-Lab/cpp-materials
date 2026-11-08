#include <iostream>
#include "Device.h"

Device::Device(const std::string &name, const std::string &model)
    : name(name), model(model) {
}

void Device::describe() const {
    std::cout << name << " [" << model << "] — power: " << powerConsumption() << "W\n";
}
