#include "board.h"

#define OUTPUT1 16

void Board::begin()
{
    pinMode(OUTPUT1, OUTPUT);

    digitalWrite(OUTPUT1, LOW);
}

void Board::setOutput(uint8_t channel, bool state)
{
    switch(channel)
    {
        case 1:
            digitalWrite(OUTPUT1, state);
            break;
    }
}

bool Board::getInput(uint8_t channel)
{
    return false;
}