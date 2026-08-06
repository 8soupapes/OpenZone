#include "OpenZone.h"

#include "board.h"

#include "TemperatureLoader.h"

#include "ZoneLoader.h"

#include "ClimateController.h"

#include "TemperatureManager.h"

namespace OpenZone
{

void begin()
{
    Board::begin();

    TemperatureLoader::begin();

    ZoneLoader::begin();

    ClimateController::begin();
}

void update()
{
    TemperatureManager::update();

    ClimateController::update();
}

}