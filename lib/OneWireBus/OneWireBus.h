#ifndef ONEWIREBUS_H
#define ONEWIREBUS_H

#include <Arduino.h>

#include <OneWire.h>

namespace OneWireBus
{
    void begin();

    void scan();

    uint8_t count();

    uint8_t deviceCount(uint8_t bus);

    bool getAddress(uint8_t bus,
                    uint8_t index,
                    uint8_t address[8]);

    OneWire* bus(uint8_t index);
}

#endif