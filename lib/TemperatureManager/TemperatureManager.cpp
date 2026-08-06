#include "TemperatureManager.h"

TemperatureSource TemperatureManager::_sources[MAX_TEMPERATURE_SOURCES];

uint8_t TemperatureManager::_count = 0;

void TemperatureManager::begin()
{
    _count = 0;
}

int TemperatureManager::registerSource(const String& name,
                                       TemperatureSourceType type)
{
    if (_count >= MAX_TEMPERATURE_SOURCES)
    {
        return -1;
    }

    _sources[_count].name = name;
    _sources[_count].type = type;
    _sources[_count].value = NAN;
    _sources[_count].valid = false;
    _sources[_count].timestamp = 0;

    return _count++;
}

void TemperatureManager::setValue(int id,
                                  float value)
{
    if (id < 0 || id >= _count)
    {
        return;
    }

    _sources[id].value = value;
    _sources[id].valid = true;
    _sources[id].timestamp = millis();
}

float TemperatureManager::value(int id)
{
    if (id < 0 || id >= _count)
    {
        return NAN;
    }

    return _sources[id].value;
}

bool TemperatureManager::valid(int id)
{
    if (id < 0 || id >= _count)
    {
        return false;
    }

    return _sources[id].valid;
}

const String& TemperatureManager::name(int id)
{
    static String empty;

    if (id < 0 || id >= _count)
    {
        return empty;
    }

    return _sources[id].name;
}

uint8_t TemperatureManager::count()
{
    return _count;
}