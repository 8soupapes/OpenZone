#include <Arduino.h>

#include "board.h"
#include "HardwareTest.h"

void setup()
{
    Board::begin();
    HardwareTest::begin();
}

void loop()
{
    HardwareTest::loop();
}