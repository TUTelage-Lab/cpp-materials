#ifndef LAB5_CONFIGMAP_H
#define LAB5_CONFIGMAP_H

#include <iostream>
#include <string>

class ConfigMap {
    static const int CAPACITY = 32;
    std::string keys[CAPACITY];
    std::string values[CAPACITY];
    int size;

public:
    ConfigMap();

    ConfigMap(const ConfigMap &other);

    ConfigMap &operator=(const ConfigMap &other);

    std::string &operator[](const std::string &key);

    friend std::ostream &operator<<(std::ostream &os, const ConfigMap &cfg);
};

#endif //LAB5_CONFIGMAP_H
