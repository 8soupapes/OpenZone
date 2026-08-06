#include "HardwareTest.h"

#include "Logger.h"
#include "Outputs.h"

#include "Zone.h"
#include "ZoneConfig.h"

#include "ZoneManager.h"

void HardwareTest::begin()
{
    Logger::info("Hardware Test");

    Outputs::begin();

    ZoneManager::begin();
}

void HardwareTest::loop()
{
    ZoneManager::get(1)->open();
    delay(5000);

    ZoneManager::get(1)->stop();
    delay(2000);

    ZoneManager::get(1)->close();
    delay(5000);

    ZoneManager::get(1)->stop();
    delay(2000);
}