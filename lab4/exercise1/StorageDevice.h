#ifndef LAB4_STORAGEDEVICE_H
#define LAB4_STORAGEDEVICE_H
#include "Device.h"

class StorageDevice : public virtual Device {
protected:
    double capacityGB;
    double usedGB;

public:
    StorageDevice(const std::string &name, const std::string &model,
                  double capacityGB);

    bool write(double sizeGB);

    void erase();

    double usedPercent() const;
};

#endif //LAB4_STORAGEDEVICE_H
