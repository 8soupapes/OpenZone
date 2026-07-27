#ifndef BOARD_H
#define BOARD_H

#include <Arduino.h>

class Board
{
public:

    static void begin();

    static void setOutput(uint8_t channel, bool state);

    static bool getInput(uint8_t channel);

};

#endif