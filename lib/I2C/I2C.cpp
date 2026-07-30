#include "I2C.h"

#include <Wire.h>

#include "PinMap.h"
#include "Logger.h"

namespace I2C
{

void begin()
{
    Wire.begin(PinMap::I2C_SDA, PinMap::I2C_SCL);

    Logger::info("I2C initialized");
}

bool devicePresent(uint8_t address)
{
    Wire.beginTransmission(address);

    return (Wire.endTransmission() == 0);
}

bool writeByte(uint8_t address, uint8_t data)
{
    Wire.beginTransmission(address);
    Wire.write(data);

    return (Wire.endTransmission() == 0);
}

bool readByte(uint8_t address, uint8_t &data)
{
    if (Wire.requestFrom(address, (uint8_t)1) != 1)
        return false;

    data = Wire.read();

    return true;
}

void scan()
{
    Logger::info("--------------------------------");
    Logger::info("Scanning I2C bus...");
    Logger::info("--------------------------------");

    uint8_t found = 0;

    for (uint8_t addr = 0x03; addr <= 0x77; addr++)
    {
        if (devicePresent(addr))
        {
            Serial.printf("[I2C] Device found at 0x%02X\n", addr);
            found++;
        }
    }

    Serial.printf("[I2C] %u device(s) found\n", found);
}

}