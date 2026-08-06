#include "OneWireBus.h"

#include <Arduino.h>
#include <OneWire.h>

#include "Logger.h"
#include "PinMap.h"

static constexpr uint8_t BUS_COUNT = 3;
static constexpr uint8_t MAX_DEVICES = 16;
static constexpr uint8_t ROM_SIZE = 8;

static OneWire bus1(PinMap::ONEWIRE1);
static OneWire bus2(PinMap::ONEWIRE2);
static OneWire bus3(PinMap::ONEWIRE3);

static OneWire* buses[BUS_COUNT] =
{
    &bus1,
    &bus2,
    &bus3
};

static const uint8_t busPins[BUS_COUNT] =
{
    PinMap::ONEWIRE1,
    PinMap::ONEWIRE2,
    PinMap::ONEWIRE3
};

static uint8_t deviceCount_[BUS_COUNT] = {0};

static uint8_t roms[BUS_COUNT][MAX_DEVICES][ROM_SIZE];

namespace OneWireBus
{
    

void begin()
{
    Logger::info("OneWire initialized");
    Logger::info(String(BUS_COUNT) + " OneWire bus available");
}

uint8_t count()
{
    return BUS_COUNT;
}

void scan()
{
    Logger::info("--------------------------------");
    Logger::info("Scanning OneWire buses...");
    Logger::info("--------------------------------");

    for (uint8_t bus = 0; bus < BUS_COUNT; bus++)
    {
        Serial.printf("\nBus %u (GPIO%d)\n",
                      bus + 1,
                      busPins[bus]);

        deviceCount_[bus] = 0;

        buses[bus]->reset_search();

        uint8_t address[ROM_SIZE];

        while (buses[bus]->search(address))
        {
            if (deviceCount_[bus] < MAX_DEVICES)
            {
                memcpy(roms[bus][deviceCount_[bus]], address, ROM_SIZE);
            }

            deviceCount_[bus]++;

            Serial.printf("  Sensor %u\n", deviceCount_[bus]);

            Serial.print("  ROM : ");

            for (uint8_t i = 0; i < ROM_SIZE; i++)
            {
                Serial.printf("%02X ", address[i]);
            }

            Serial.println();

            if (OneWire::crc8(address, 7) == address[7])
            {
                Serial.println("  CRC : OK");
            }
            else
            {
                Serial.println("  CRC : ERROR");
            }

            switch (address[0])
            {
                case 0x28:
                    Serial.println("  Family : DS18B20");
                    break;

                case 0x10:
                    Serial.println("  Family : DS18S20");
                    break;

                case 0x22:
                    Serial.println("  Family : DS1822");
                    break;

                default:
                    Serial.printf("  Family : Unknown (0x%02X)\n", address[0]);
                    break;
            }

            Serial.println();
        }

        if (deviceCount_[bus] == 0)
        {
            Serial.println("  No sensor");
        }
        else
        {
            Serial.printf("  Total : %u sensor(s)\n", deviceCount_[bus]);
        }
    }

    Logger::info("--------------------------------");
}

uint8_t deviceCount(uint8_t bus)
{
    if (bus >= BUS_COUNT)
    {
        return 0;
    }

    return deviceCount_[bus];
}

bool getAddress(uint8_t bus,
                uint8_t index,
                uint8_t address[ROM_SIZE])
{
    if (bus >= BUS_COUNT)
    {
        return false;
    }

    if (index >= deviceCount_[bus])
    {
        return false;
    }

    memcpy(address, roms[bus][index], ROM_SIZE);

    return true;
}

OneWire* bus(uint8_t index)
{
    if (index >= BUS_COUNT)
    {
        return nullptr;
    }

    return buses[index];
}
}