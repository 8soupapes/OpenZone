#include "Inputs.h"

#include "PCF8574.h"
#include "PinMap.h"

// PCF8574 des entrées
static PCF8574 in1(PinMap::PCF_IN1);
static PCF8574 in2(PinMap::PCF_IN2);

// Etat courant et précédent des 16 entrées
static bool inputState[16] = {false};
static bool previousState[16] = {false};

// Les entrées de la KC868-A16 sont actives à l'état bas
static constexpr bool INPUT_ACTIVE_LOW = true;

namespace Inputs
{

void begin()
{
    in1.begin();
    in2.begin();

    update();
}

void update()
{
    uint8_t value;

    // -------- Entrées 1 à 8 --------
    if (in1.read(value))
    {
        for (uint8_t i = 0; i < 8; i++)
        {
            previousState[i] = inputState[i];

            bool state = value & (1 << i);

            if (INPUT_ACTIVE_LOW)
                state = !state;

            inputState[i] = state;
        }
    }

    // -------- Entrées 9 à 16 --------
    if (in2.read(value))
    {
        for (uint8_t i = 0; i < 8; i++)
        {
            previousState[i + 8] = inputState[i + 8];

            bool state = value & (1 << i);

            if (INPUT_ACTIVE_LOW)
                state = !state;

            inputState[i + 8] = state;
        }
    }
}

bool get(uint8_t input)
{
    if (input < 1 || input > 16)
        return false;

    return inputState[input - 1];
}
uint16_t state()
{
    uint16_t result = 0;

    for (uint8_t i = 0; i < 16; i++)
    {
        if (inputState[i])
            result |= (1 << i);
    }

    return result;
}

bool changed(uint8_t input)
{
    if (input < 1 || input > 16)
        return false;

    return inputState[input - 1] != previousState[input - 1];
}

bool risingEdge(uint8_t input)
{
    if (input < 1 || input > 16)
        return false;

    return (!previousState[input - 1] && inputState[input - 1]);
}

bool fallingEdge(uint8_t input)
{
    if (input < 1 || input > 16)
        return false;

    return (previousState[input - 1] && !inputState[input - 1]);
}

}