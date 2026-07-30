#ifndef GPIO_H
#define GPIO_H

#include <Arduino.h>

namespace GPIO
{
    void begin();
    void write(uint8_t pin, bool state);
    bool read(uint8_t pin);
}

#endif