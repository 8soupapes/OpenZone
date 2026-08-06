#include "ZoneLoader.h"

#include "Logger.h"

#include "Zone.h"
#include "ZoneManager.h"

#include "ZoneConfig.h"

#include "TemperatureManager.h"
#include "RegisterManager.h"

static Zone zones[ZoneCount];

namespace ZoneLoader
{

void begin()
{
    Logger::info("--------------------------------");
    Logger::info("Loading zones...");
    Logger::info("--------------------------------");

    for (uint8_t i = 0; i < ZoneCount; i++)
    {
        zones[i].setId(ZoneConfigs[i].id);

        zones[i].setName(ZoneConfigs[i].name);

        zones[i].setSetpoint(ZoneConfigs[i].setpoint);

        zones[i].setTemperatureSensor(
            TemperatureManager::sensor(
                ZoneConfigs[i].temperatureSensor));

        zones[i].setRegister(
            RegisterManager::reg(
                ZoneConfigs[i].registerId));

        ZoneManager::addZone(&zones[i]);

        Logger::info(
            String("Zone ")
            + zones[i].name()
            + " loaded");
    }

    Logger::info(
        String(ZoneManager::count())
        + " zone(s) loaded");

    Logger::info("--------------------------------");
}

}