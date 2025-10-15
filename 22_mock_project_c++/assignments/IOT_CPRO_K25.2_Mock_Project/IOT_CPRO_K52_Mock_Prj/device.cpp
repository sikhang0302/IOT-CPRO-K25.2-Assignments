#include "device.h"

// variables for randoom generation
bool Device::isGenSeed = false;
std::default_random_engine Device::gen;
std::uniform_real_distribution<double> Device::distribution{0.0, 100.0};


// Device Class Implementation
Device::Device(std::string name, std::string id, std::string location): _devName(name), _devId(id), _devLocation(location){
    if(!isGenSeed)
    {
        srand(time(0));
        isGenSeed = true;
        qDebug() << "Gen Seed for first time call Device Constructor";
    }
    qDebug() << "Device Constructor Called";
};

const std::string Device::getDevName()
{
    return _devName;
}

const std::string Device::getDevId()
{
    return _devId;
}

const std::string Device::getDevLocation()
{
    return _devLocation;
}

// TemperatureSensor Class Implementation
TemperatureSensor::TemperatureSensor(const std::string& name, const std::string& id, const std::string& location):Device(name,id,location) {
    qDebug() << "TemperatureSensor Constructor Called";
}

const int TemperatureSensor::getDevType() {
    return Device::TEMPERATURE_SENSOR;
}

const std::string TemperatureSensor::getValue() {
    return std::to_string(Device::distribution(gen));
}

// PressureSensor Class Implementation
PressureSensor::PressureSensor(const std::string& name, const std::string& id, const std::string& location) : Device(name, id, location) {
    qDebug() << "PressureSensor Constructor Called";
}

const int PressureSensor::getDevType() {
    return Device::PRESSURE_SENSOR;
}
const std::string PressureSensor::getValue() {
    return std::to_string(Device::distribution(gen));
}

const bool Device::toggleDev() {
    if (!_devToggle) {
        _devToggle = true;
    } else {
        _devToggle = false;
    }
    return _devToggle;
}

const bool Device::getToggle() {
    return _devToggle;
}

// HumiditySensor Class Implementation
HumiditySensor::HumiditySensor(const std::string& name, const std::string& id, const std::string& location) : Device(name, id, location) {
    qDebug() << "HumiditySensor Constructor Called";
}

const int HumiditySensor::getDevType() {
    return Device::HUMIDITY_SENSOR;
}
const std::string HumiditySensor::getValue() {
    return std::to_string(Device::distribution(gen));
}

// LightSwitch Class Implementation
LightSwitch::LightSwitch(const std::string& name, const std::string& id, const std::string& location) : Device(name, id, location) {
    qDebug() << "LightSwitch Constructor Called";
}

const int LightSwitch::getDevType() {
    return Device::LIGHT_SWITCH;
}

const std::string LightSwitch::getValue() {
    _lightState = getToggle();
    return _lightState ? "ON" : "OFF";
}

// DeviceFactory Implementation
std::unique_ptr<Device> DeviceFactory::createDevice(std::string name,std::string id, std::string location, int type)
{
    if (name.empty()) {
        qDebug() << "Device Name cannot be empty";
    }

    if (id.empty()) {
        qDebug() << "Device ID cannot be empty";
    }

    if (location.empty()) {
        qDebug() << "Device Location cannot be empty";
    }

    if (!(name.empty()) && !(id.empty()) && !(location.empty())) {
        switch(type)
        {
        case Device::TEMPERATURE_SENSOR:
            return std::make_unique<TemperatureSensor>(name,id,location);
            break;
        case Device::PRESSURE_SENSOR:
            return std::make_unique<PressureSensor>(name, id, location);
            break;
        case Device::HUMIDITY_SENSOR:
            return std::make_unique<HumiditySensor>(name, id, location);
            break;
        case Device::LIGHT_SWITCH:
            return std::make_unique<LightSwitch>(name, id, location);
            break;
        default:
            qDebug() << "Invalid Device Type";
            return nullptr;
        }
    }

    return nullptr;
}
