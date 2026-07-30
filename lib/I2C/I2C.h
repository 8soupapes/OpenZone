#ifndef I2C_H
#define I2C_H

#include <Arduino.h>

namespace I2C
{
    void begin();

    bool devicePresent(uint8_t address);

    bool writeByte(uint8_t address, uint8_t data);

    bool readByte(uint8_t address, uint8_t &data);

    bool writeByte(uint8_t address, uint8_t value);
    
    bool readByte(uint8_t address, uint8_t &value);

    void scan();
}

#endif