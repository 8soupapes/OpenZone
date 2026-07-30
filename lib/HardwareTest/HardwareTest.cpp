#include "HardwareTest.h"

#include <Arduino.h>

#include "Inputs.h"
#include "Logger.h"

void HardwareTest::begin()
{
    Logger::info("Hardware Test");

    Inputs::begin();
}

void HardwareTest::loop()
{
    Inputs::update();

    for (uint8_t i = 1; i <= 16; i++)
    {
        if (Inputs::changed(i))
        {
            Serial.printf("IN%02u : %s\n",
                          i,
                          Inputs::get(i) ? "ON" : "OFF");
        }
    }

    delay(20);
}