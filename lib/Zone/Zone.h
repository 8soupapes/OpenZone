#ifndef ZONE_H
#define ZONE_H

#include <Arduino.h>

#include "TemperatureSensor.h"
#include "Register.h"

class Zone
{
public:

    Zone();

    void begin();
    void update();

    // Configuration

    void setId(uint8_t id);
    uint8_t id() const;

    void setName(const String& name);
    const String& name() const;

    void setSetpoint(float value);
    float setpoint() const;

    void setTemperatureSensor(TemperatureSensor* sensor);
    TemperatureSensor* temperatureSensor() const;

    void setRegister(Register* reg);
    Register* reg() const;

    // Informations

    float temperature() const;

private:

    uint8_t _id;

    String _name;

    float _setpoint;

    TemperatureSensor* _temperatureSensor;

    Register* _register;
};

#endif