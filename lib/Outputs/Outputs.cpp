#include "Outputs.h"

#include "PCF8574.h"
#include "PinMap.h"

static PCF8574 out1(PinMap::PCF_OUT1, true);
static PCF8574 out2(PinMap::PCF_OUT2, true);

static bool outputState[16] = {false};

namespace Outputs
{

void begin()
{
    out1.begin();
    out2.begin();

    allOff();
}

bool set(uint8_t output, bool state)
{
    if (output < 1 || output > 16)
        return false;

    outputState[output - 1] = state;

    if (output <= 8)
        return out1.writePin(output - 1, state);

    return out2.writePin(output - 9, state);
}

bool get(uint8_t output)
{
    if (output < 1 || output > 16)
        return false;

    return outputState[output - 1];
}

void toggle(uint8_t output)
{
    set(output, !get(output));
}

void allOff()
{
    for (uint8_t i = 1; i <= 16; i++)
    {
        set(i, false);
    }
}

void allOn()
{
    for (uint8_t i = 1; i <= 16; i++)
    {
        set(i, true);
    }
}

}