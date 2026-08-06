#include "ZoneManager.h"

Zone* ZoneManager::_zones[ZoneManager::MAX_ZONES];

uint8_t ZoneManager::_count = 0;

void ZoneManager::begin()
{
}

void ZoneManager::update()
{
    for (uint8_t i = 0; i < _count; i++)
    {
        _zones[i]->update();
    }
}

bool ZoneManager::addZone(Zone* zone)
{
    if (_count >= MAX_ZONES)
    {
        return false;
    }

    _zones[_count++] = zone;

    return true;
}

uint8_t ZoneManager::count()
{
    return _count;
}

Zone* ZoneManager::zone(uint8_t index)
{
    if (index >= _count)
    {
        return nullptr;
    }

    return _zones[index];
}