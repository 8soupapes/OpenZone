#include "ClimateController.h"

#include "Logger.h"

#include "ZoneManager.h"
#include "Zone.h"

#include "Register.h"

void ClimateController::begin()
{
    Logger::info("--------------------------------");
    Logger::info("Climate Controller");
    Logger::info("--------------------------------");
}

void ClimateController::update()
{
    for (uint8_t i = 0; i < ZoneManager::count(); i++)
    {
        Zone* zone = ZoneManager::zone(i);

        if (zone == nullptr)
        {
            continue;
        }

        TemperatureSensor* sensor = zone->temperatureSensor();

        Register* reg = zone->reg();

        if (sensor == nullptr || reg == nullptr)
        {
            continue;
        }

        float temperature = sensor->temperature();

        float setpoint = zone->setpoint();

        if (temperature < setpoint)
        {
            reg->open();
        }
        else
        {
            reg->close();
        }
    }
}