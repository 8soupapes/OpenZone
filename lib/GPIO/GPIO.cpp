#include "GPIO.h"

namespace GPIO
{
    void begin()
    {
    }

    void write(uint8_t pin, bool state)
    {
        digitalWrite(pin, state);
    }

    bool read(uint8_t pin)
    {
        return digitalRead(pin);
    }
}