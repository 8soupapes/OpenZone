#include "RegisterConfiguration.h"

#include "Logger.h"
#include "Register.h"
#include "RegisterManager.h"

const RegisterConfig RegisterConfigs[] =
{
    {1,  1,  2, 120000, 120000},
    {2,  3,  4, 120000, 120000},
    {3,  5,  6, 120000, 120000},
    {4,  7,  8, 120000, 120000},
    {5,  9, 10, 120000, 120000},
    {6, 11, 12, 120000, 120000},
    {7, 13, 14, 120000, 120000},
    {8, 15, 16, 120000, 120000}
};

static Register registers[RegisterCount];

namespace RegisterConfiguration
{

void begin()
{
    Logger::info("--------------------------------");
    Logger::info("Loading registers...");
    Logger::info("--------------------------------");

    for (uint8_t i = 0; i < RegisterCount; i++)
    {
        registers[i].setId(RegisterConfigs[i].id);

        registers[i].setOutputs(
            RegisterConfigs[i].outputOpen,
            RegisterConfigs[i].outputClose);

        registers[i].setOpeningTime(
            RegisterConfigs[i].openingTimeMs);

        registers[i].setClosingTime(
            RegisterConfigs[i].closingTimeMs);

        RegisterManager::addRegister(&registers[i]);

        Logger::info(
            String("Register ")
            + RegisterConfigs[i].id
            + " loaded");
    }

    Logger::info(
        String(RegisterManager::count())
        + " register(s) loaded");

    Logger::info("--------------------------------");
}

}