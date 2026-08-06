#ifndef ZONECONFIG_H
#define ZONECONFIG_H

#include <Arduino.h>

struct ZoneConfig
{
    uint8_t id;

    const char* name;

    uint8_t openOutput;
    uint8_t closeOutput;

    uint16_t travelTime;

    bool reverseOutputs;
};

extern const ZoneConfig ZoneConfigs[];

constexpr uint8_t ZONE_COUNT = 8;

#endif