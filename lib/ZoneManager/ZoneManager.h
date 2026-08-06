#ifndef ZONEMANAGER_H
#define ZONEMANAGER_H

#include <Arduino.h>

#include "Zone.h"

class ZoneManager
{
public:

    static constexpr uint8_t MAX_ZONES = 16;

    static void begin();

    static void update();

    static bool addZone(Zone* zone);

    static uint8_t count();

    static Zone* zone(uint8_t index);

private:

    static Zone* _zones[MAX_ZONES];

    static uint8_t _count;
};

#endif