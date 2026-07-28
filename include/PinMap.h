#ifndef PINMAP_H
#define PINMAP_H

#include <Arduino.h>

namespace PinMap
{
    //==================================================
    // KC868-A16 V1.6.3
    // Les GPIO seront validés progressivement
    //==================================================

    // ---------- Sorties MOSFET ----------
    constexpr uint8_t OutputPins[16] =
    {
        255,255,255,255,
        255,255,255,255,
        255,255,255,255,
        255,255,255,255
    };

    // ---------- Entrées optocouplées ----------
    constexpr uint8_t InputPins[16] =
    {
        255,255,255,255,
        255,255,255,255,
        255,255,255,255,
        255,255,255,255
    };

    // ---------- Bus OneWire ----------
    constexpr uint8_t OneWirePin = 255;

    // ---------- RS485 ----------
    constexpr uint8_t RS485_TX = 255;
    constexpr uint8_t RS485_RX = 255;

    // ---------- Ethernet W5500 ----------
    constexpr uint8_t ETH_CS  = 255;
    constexpr uint8_t ETH_INT = 255;

    // ---------- SPI ----------
    constexpr uint8_t SPI_MOSI = 23;
    constexpr uint8_t SPI_MISO = 19;
    constexpr uint8_t SPI_SCK  = 18;
}

#endif