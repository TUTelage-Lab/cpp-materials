#include <iostream>
#include "NAS.h"

NAS::NAS(const std::string &name, const std::string &model,
         const std::string &ipAddress, int bandwidthMbps,
         double capacityGB, int raidLevel)
    : Device(name, model),
      NetworkDevice(name, model, ipAddress, bandwidthMbps),
      StorageDevice(name, model, capacityGB),
      raidLevel(raidLevel) {
}

void NAS::status() const {
    std::cout << name << " [RAID " << raidLevel << "] — IP: " << ipAddress << " | storage: " << usedGB << "/" <<
            capacityGB << "GB (" << usedPercent() << "%) | power: " << powerConsumption() << "W\n";
}

double NAS::powerConsumption() const {
    return 10.0 + raidLevel * 5.0;
}
