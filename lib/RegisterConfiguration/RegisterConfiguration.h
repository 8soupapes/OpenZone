#ifndef REGISTERCONFIGURATION_H
#define REGISTERCONFIGURATION_H

#include <Arduino.h>

struct RegisterConfig
{
    uint8_t id;

    uint8_t outputOpen;

    uint8_t outputClose;

    uint16_t openingTimeMs;

    uint16_t closingTimeMs;
};

extern const RegisterConfig RegisterConfigs[];

constexpr uint8_t RegisterCount = 8;

namespace RegisterConfiguration
{
    void begin();
}

#endif