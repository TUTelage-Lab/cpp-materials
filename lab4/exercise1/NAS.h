#ifndef LAB4_NAS_H
#define LAB4_NAS_H
#include "NetworkDevice.h"
#include "StorageDevice.h"

class NAS : public NetworkDevice, public StorageDevice {
    int raidLevel;

public:
    NAS(const std::string &name, const std::string &model,
        const std::string &ipAddress, int bandwidthMbps,
        double capacityGB, int raidLevel);

    void status() const override;

    double powerConsumption() const override;
};

#endif //LAB4_NAS_H
