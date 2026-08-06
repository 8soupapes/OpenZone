#ifndef TEMPERATUREMANAGER_H
#define TEMPERATUREMANAGER_H

#include <Arduino.h>

static constexpr uint8_t MAX_TEMPERATURE_SOURCES = 32;

enum class TemperatureSourceType
{
    Unknown,
    DS18B20,
    Zigbee,
    Midea,
    Virtual
};

struct TemperatureSource
{
    String name;

    TemperatureSourceType type;

    float value;

    bool valid;

    unsigned long timestamp;
};

class TemperatureManager
{
public:

    static void begin();

    static int registerSource(const String& name,
                              TemperatureSourceType type);

    static void setValue(int id,
                         float value);

    static float value(int id);

    static bool valid(int id);

    static const String& name(int id);

    static uint8_t count();

private:

    static TemperatureSource _sources[MAX_TEMPERATURE_SOURCES];

    static uint8_t _count;
};

#endif