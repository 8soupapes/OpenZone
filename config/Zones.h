#ifndef ZONES_H
#define ZONES_H

#include <Arduino.h>

struct ZoneConfig
{
    const char* name;

    uint8_t openOutput;
    uint8_t closeOutput;

    uint32_t travelTime;
};

constexpr ZoneConfig Zones[] =
{
    {
        "Salon",
        1,
        2,
        20000
    },

    {
        "Cuisine",
        3,
        4,
        20000
    },

    {
        "Chambre 1",
        5,
        6,
        20000
    },

    {
        "Chambre 2",
        7,
        8,
        20000
    },

    {
        "Chambre 3",
        9,
        10,
        20000
    },

    {
        "Bureau",
        11,
        12,
        20000
    },

    {
        "Salle de bain",
        13,
        14,
        20000
    },

    {
        "Entrée",
        15,
        16,
        20000
    }
};

constexpr uint8_t ZoneCount =
    sizeof(Zones) / sizeof(Zones[0]);

#endif