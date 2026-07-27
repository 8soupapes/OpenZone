#include "GPIO.h"

void GPIO::output(uint8_t pin)
{
    pinMode(pin, OUTPUT);
}

void GPIO::input(uint8_t pin)
{
    pinMode(pin, INPUT);
}

void GPIO::write(uint8_t pin, bool state)
{
    digitalWrite(pin, state);
}

bool GPIO::read(uint8_t pin)
{
    return digitalRead(pin);
}