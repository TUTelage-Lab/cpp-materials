#ifndef LAB4_NETWORKDEVICE_H
#define LAB4_NETWORKDEVICE_H
#include "Device.h"

class NetworkDevice : public virtual Device {
protected:
    std::string ipAddress;
    int bandwidthMbps;

public:
    NetworkDevice(const std::string &name, const std::string &model,
                  const std::string &ipAddress, int bandwidthMbps);

    void connect() const;

    void disconnect() const;
};

#endif //LAB4_NETWORKDEVICE_H
