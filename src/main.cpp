#include <Arduino.h>

#include "Logger.h"

void setup()
{
    Logger::begin();

    Logger::info("--------------------------------");
    Logger::info("OpenZone");
    Logger::info("Booting...");
    Logger::info("--------------------------------");
}

void loop()
{

}