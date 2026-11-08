#include "ConfigMap.h"
#include <stdexcept>

ConfigMap::ConfigMap() : size(0) {
}

ConfigMap::ConfigMap(const ConfigMap &other) : size(other.size) {
    for (int i = 0; i < size; i++) {
        keys[i] = other.keys[i];
        values[i] = other.values[i];
    }
}

ConfigMap &ConfigMap::operator=(const ConfigMap &other) {
    if (this == &other) {
        return *this;
    }
    size = other.size;
    for (int i = 0; i < size; i++) {
        keys[i] = other.keys[i];
        values[i] = other.values[i];
    }
    return *this;
}

std::string &ConfigMap::operator[](const std::string &key) {
    for (int i = 0; i < size; i++) {
        if (keys[i] == key) {
            return values[i];
        }
    }
    if (size >= CAPACITY) {
        throw std::overflow_error("ConfigMap is full");
    }
    keys[size] = key;
    values[size] = "";
    return values[size++];
}

std::ostream &operator<<(std::ostream &os, const ConfigMap &cfg) {
    for (int i = 0; i < cfg.size; i++) {
        os << cfg.keys[i] << " = " << cfg.values[i] << "\n";
    }
    return os;
}
