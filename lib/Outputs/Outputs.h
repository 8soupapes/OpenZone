#ifndef OUTPUTS_H
#define OUTPUTS_H

#include <Arduino.h>

namespace Outputs
{
    void begin();

    bool set(uint8_t output, bool state);

    bool get(uint8_t output);
    void toggle(uint8_t output);

    void allOff();
    void allOn();
}

#endif