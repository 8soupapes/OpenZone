#ifndef GPIO_H
#define GPIO_H

#include <Arduino.h>

class GPIO
{
public:

    static void output(uint8_t pin);

    static void input(uint8_t pin);

    static void write(uint8_t pin, bool state);

    static bool read(uint8_t pin);

};

#endif