#ifndef LAB4_DEVICE_H
#define LAB4_DEVICE_H
#include <string>

class Device {
protected:
    std::string name;
    std::string model;

public:
    Device(const std::string &name, const std::string &model);

    virtual void status() const = 0;

    virtual double powerConsumption() const = 0;

    void describe() const;

    virtual ~Device() = default;
};

#endif //LAB4_DEVICE_H
