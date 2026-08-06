#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <Arduino.h>

enum class TemperatureSensorType
{
    Unknown,
    DS18B20,
    Zigbee,
    Midea,
    Virtual
};

class TemperatureSensor
{
public:

    virtual ~TemperatureSensor() = default;

    virtual void begin() = 0;

    virtual void update() = 0;

    virtual float temperature() const = 0;

    virtual bool isConnected() const = 0;

    virtual TemperatureSensorType type() const = 0;
};

#endif