#include "Zone.h"

Zone::Zone()
{
    _id = 0;

    _name = "";

    _setpoint = 20.0f;

    _temperatureSensor = nullptr;

    _register = nullptr;
}

void Zone::begin()
{
}

void Zone::update()
{
}

void Zone::setId(uint8_t id)
{
    _id = id;
}

uint8_t Zone::id() const
{
    return _id;
}

void Zone::setName(const String& name)
{
    _name = name;
}

const String& Zone::name() const
{
    return _name;
}

void Zone::setSetpoint(float value)
{
    _setpoint = value;
}

float Zone::setpoint() const
{
    return _setpoint;
}

void Zone::setTemperatureSensor(TemperatureSensor* sensor)
{
    _temperatureSensor = sensor;
}

TemperatureSensor* Zone::temperatureSensor() const
{
    return _temperatureSensor;
}

void Zone::setRegister(Register* reg)
{
    _register = reg;
}

Register* Zone::reg() const
{
    return _register;
}

float Zone::temperature() const
{
    if (_temperatureSensor == nullptr)
    {
        return NAN;
    }

    return _temperatureSensor->temperature();
}