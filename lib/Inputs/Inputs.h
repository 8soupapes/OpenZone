#ifndef INPUTS_H
#define INPUTS_H

#include <Arduino.h>

namespace Inputs
{
    void begin();

    void update();

    bool get(uint8_t input);

    uint16_t state();

    bool changed(uint8_t input);

    bool risingEdge(uint8_t input);

    bool fallingEdge(uint8_t input);
}

#endif