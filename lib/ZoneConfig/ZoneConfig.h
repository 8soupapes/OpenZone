#ifndef ZONECONFIG_H
#define ZONECONFIG_H

#include <Arduino.h>

struct ZoneConfig
{
    uint8_t id;

    const char* name;

    float setpoint;

    uint8_t temperatureSensor;

    uint8_t registerId;
};

extern const ZoneConfig ZoneConfigs[];

constexpr uint8_t ZoneCount = 8;

#endif