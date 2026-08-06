#include "TemperatureLoader.h"

#include "Logger.h"

#include "OneWireBus.h"

#include "TemperatureManager.h"

#include "DS18B20.h"

static constexpr uint8_t MAX_SENSORS = 16;

static DS18B20 sensors[MAX_SENSORS];

namespace TemperatureLoader
{

void begin()
{
    Logger::info("--------------------------------");
    Logger::info("Loading temperature sensors...");
    Logger::info("--------------------------------");

    uint8_t sensorIndex = 0;

    for (uint8_t bus = 0; bus < OneWireBus::count(); bus++)
    {
        uint8_t count = OneWireBus::deviceCount(bus);

        for (uint8_t device = 0;
             device < count;
             device++)
        {
            if (sensorIndex >= MAX_SENSORS)
            {
                break;
            }

            uint8_t rom[8];

            if (!OneWireBus::getAddress(bus,
                                        device,
                                        rom))
            {
                continue;
            }

            sensors[sensorIndex].setBus(bus);

            sensors[sensorIndex].setAddress(rom);

            sensors[sensorIndex].begin();

            TemperatureManager::addSensor(
                &sensors[sensorIndex]);

            Logger::info(
                String("DS18B20 #")
                + sensorIndex
                + " loaded");

            sensorIndex++;
        }
    }

    Logger::info(
        String(sensorIndex)
        + " temperature sensor(s) loaded");

    Logger::info("--------------------------------");
}

}