#ifndef DS18B20_H
#define DS18B20_H

#include <Arduino.h>

#include "TemperatureSensor.h"

enum class DS18B20State
{
    Idle,
    Converting
};

class DS18B20 : public TemperatureSensor
{
public:

    DS18B20();

    void begin() override;

    void update() override;

    void setBus(uint8_t bus);

    bool setAddress(const uint8_t address[8]);

    bool isConnected() const override;

    float temperature() const override;

    TemperatureSensorType type() const override;

private:

    uint8_t _bus;

    uint8_t _address[8];

    bool _connected;

    float _temperature;

    unsigned long _lastRead;

    DS18B20State _state;
};

#endif