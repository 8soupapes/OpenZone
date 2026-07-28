#include <Arduino.h>

#include "board.h"
#include "Version.h"
#include "Config.h"

#include <Logger.h>

void Board::begin()
{
    Logger::begin();

    Logger::info("--------------------------------");
    Logger::info(PROJECT_NAME);
    Logger::info(PROJECT_VERSION);
    Logger::info(PROJECT_BOARD);
    Logger::info("--------------------------------");

    Logger::info("Chip  : " + String(ESP.getChipModel()));
    Logger::info("CPU   : " + String(ESP.getCpuFreqMHz()) + " MHz");
    Logger::info("Flash : " + String(ESP.getFlashChipSize() / 1024 / 1024) + " MB");
    Logger::info("Heap  : " + String(ESP.getFreeHeap() / 1024) + " KB");
}