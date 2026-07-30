#ifndef PCF8574_H
#define PCF8574_H

#include <Arduino.h>

class PCF8574
{
public:

    PCF8574(uint8_t address, bool activeLow = false);

    bool begin();

    bool write(uint8_t value);
    bool read(uint8_t &value);

    bool writePin(uint8_t pin, bool state);
    bool readPin(uint8_t pin);

private:

    uint8_t _address;
    uint8_t _state;
    bool _activeLow;
};

#endif