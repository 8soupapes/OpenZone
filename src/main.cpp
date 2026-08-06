#include <Arduino.h>

#include "OpenZone.h"

void setup()
{
    OpenZone::begin();
}

void loop()
{
    OpenZone::update();
}