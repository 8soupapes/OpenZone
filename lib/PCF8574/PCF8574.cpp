#include "PCF8574.h"

#include "I2C.h"

PCF8574::PCF8574(uint8_t address, bool activeLow)
{
    _address = address;
    _activeLow = activeLow;

    // Toutes les sorties relâchées au démarrage
    _state = 0xFF;
}

bool PCF8574::begin()
{
    return write(_state);
}

bool PCF8574::write(uint8_t value)
{
    _state = value;

    Serial.printf("[PCF8574 0x%02X] Write 0x%02X\n", _address, value);

    return I2C::writeByte(_address, value);
}

bool PCF8574::read(uint8_t &value)
{
    if (I2C::readByte(_address, value))
    {
        _state = value;
        return true;
    }

    return false;
}

bool PCF8574::writePin(uint8_t pin, bool state)
{
    if (pin > 7)
        return false;

    // Gestion automatique des sorties actives à l'état bas
    bool level = _activeLow ? !state : state;

    if (level)
        _state |= (1 << pin);
    else
        _state &= ~(1 << pin);

    return write(_state);
}

bool PCF8574::readPin(uint8_t pin)
{
    if (pin > 7)
        return false;

    uint8_t value;

    if (!read(value))
        return false;

    bool state = value & (1 << pin);

    return _activeLow ? !state : state;
}