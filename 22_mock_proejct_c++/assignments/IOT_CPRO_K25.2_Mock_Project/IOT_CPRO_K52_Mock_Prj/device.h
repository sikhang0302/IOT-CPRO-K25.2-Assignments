#ifndef DEVICE_H
#define DEVICE_H

#include <String>
#include <QDebug>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time() to seed srand()
#include <bits/stdc++.h>
#include <random>
#include <memory>


class Device
{

private:
    std::string _devName;
    std::string _devId;
    std::string _devLocation;
    int _devType;
    bool _devToggle = false;
public:
    Device(std::string name, std::string id, std::string location);
    const std::string getDevName();
    const std::string getDevId();
    const std::string getDevLocation();
    virtual const int getDevType() = 0;
    virtual const std::string getValue() = 0;
    const bool toggleDev();
    const bool getToggle();

    enum {
        TEMPERATURE_SENSOR = 0 ,
        PRESSURE_SENSOR ,
        HUMIDITY_SENSOR ,
        LIGHT_SWITCH ,
        NUM_OF_SENSOR_TYPE
    };

    static bool isGenSeed;
    static std::default_random_engine gen;
    static std::uniform_real_distribution<double> distribution;
};


/* Class for Temperature Sensor */
class TemperatureSensor: public Device
{
private:

public:
    TemperatureSensor(const std::string& name, const std::string& id, const std::string& location);

    const int getDevType() override;
    const std::string getValue() override;
};


/* Class for Pressure Sensor */
class PressureSensor : public Device {
private:

public:
    PressureSensor(const std::string& name, const std::string& id, const std::string& location);

    const int getDevType() override;
    const std::string getValue() override;
};


/* Class for Humidity Sensor */
class HumiditySensor : public Device {
private:

public:
    HumiditySensor(const std::string& name, const std::string& id, const std::string& location);

   const int getDevType() override;
   const std::string getValue() override;
};


/* Class for Light Switch */
class LightSwitch : public Device {
private:
    bool _lightState;
public:
    LightSwitch(const std::string& name, const std::string& id, const std::string& location);

    const int getDevType() override;
    const std::string getValue() override;
};


/* Simple Factory */
class DeviceFactory {
public:
   static std::unique_ptr<Device> createDevice(std::string name,std::string id, std::string location, int type);
};

#endif // DEVICE_H
