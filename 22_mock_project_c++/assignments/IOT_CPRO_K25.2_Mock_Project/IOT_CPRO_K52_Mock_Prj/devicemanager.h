#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "device.h"
#include <vector>

class deviceManager
{
private:
    static std::unique_ptr<deviceManager> instance;
    std::vector<std::unique_ptr<Device>> devices;
    deviceManager();
public:
    static deviceManager& getInstance();

    // delete copy constructor
    deviceManager(const deviceManager&) = delete;
    // delete assignment operator
    deviceManager& operator=(const deviceManager&) = delete;

    // public methods addDevice, removeDevice, getDevices are used by application
    void addDevice(std::unique_ptr<Device> dev);
    const bool isDeviceIdExist(const std::string& id);
    void removeDevice(const std::string& id);
    const std::vector<std::unique_ptr<Device>>& getDevices();
};

#endif // DEVICEMANAGER_H
