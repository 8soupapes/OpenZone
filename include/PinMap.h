#ifndef PINMAP_H
#define PINMAP_H

#include <Arduino.h>

namespace PinMap
{
    //==================================================
    // KC868-A16 V1.6.3
    //==================================================

    // Les 16 sorties et 16 entrées sont pilotées
    // par des PCF8574 via le bus I2C.
    // Les tableaux restent présents pour garder
    // une API identique sur les autres cartes.

    constexpr uint8_t OutputPins[16] =
    {
        255,255,255,255,
        255,255,255,255,
        255,255,255,255,
        255,255,255,255
    };

    constexpr uint8_t InputPins[16] =
    {
        255,255,255,255,
        255,255,255,255,
        255,255,255,255,
        255,255,255,255
    };

    // OneWire
    constexpr uint8_t OneWirePin = 255;

    // RS485
    constexpr uint8_t RS485_TX = 255;
    constexpr uint8_t RS485_RX = 255;

    // Ethernet W5500
    constexpr uint8_t ETH_CS  = 255;
    constexpr uint8_t ETH_INT = 255;

    // SPI
    constexpr uint8_t SPI_MOSI = 23;
    constexpr uint8_t SPI_MISO = 19;
    constexpr uint8_t SPI_SCK  = 18;

    // I2C
    constexpr uint8_t I2C_SDA = 4;
    constexpr uint8_t I2C_SCL = 5;

    // ---------- PCF8574 ----------
    constexpr uint8_t PCF_OUT1 = 0x24;
    constexpr uint8_t PCF_OUT2 = 0x25;

    constexpr uint8_t PCF_IN1  = 0x21;
    constexpr uint8_t PCF_IN2  = 0x22;
    
    constexpr uint8_t ONEWIRE1 = 32;
    constexpr uint8_t ONEWIRE2 = 33;
    constexpr uint8_t ONEWIRE3 = 14;
    
}

#endif