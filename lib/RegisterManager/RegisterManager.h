#ifndef REGISTERMANAGER_H
#define REGISTERMANAGER_H

#include <Arduino.h>

#include "Register.h"

class RegisterManager
{
public:

    static constexpr uint8_t MAX_REGISTERS = 16;

    static void begin();

    static void update();

    static bool addRegister(Register* reg);

    static Register* reg(uint8_t index);

    static uint8_t count();

private:

    static Register* _registers[MAX_REGISTERS];

    static uint8_t _count;
};

namespace TemperatureManager
{
    void begin();

    void update();

    bool addSensor(TemperatureSensor* sensor);

    uint8_t count();

    TemperatureSensor* sensor(uint8_t index);
}

#endif