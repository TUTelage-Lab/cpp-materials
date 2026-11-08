#include <iostream>
#include "NetworkDevice.h"

NetworkDevice::NetworkDevice(const std::string &name, const std::string &model,
                             const std::string &ipAddress, int bandwidthMbps)
    : Device(name, model), ipAddress(ipAddress), bandwidthMbps(bandwidthMbps) {
}

void NetworkDevice::connect() const {
    std::cout << name << ": connected — IP " << ipAddress << ", bandwidth " << bandwidthMbps << " Mbps\n";
}

void NetworkDevice::disconnect() const {
    std::cout << name << ": disconnected\n";
}
