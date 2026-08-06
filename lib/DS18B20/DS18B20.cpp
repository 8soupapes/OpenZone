#include "DS18B20.h"

#include <Arduino.h>
#include <OneWire.h>

#include <math.h>
#include <string.h>

#include "OneWireBus.h"

DS18B20::DS18B20()
{
    _bus = 0;

    memset(_address, 0, sizeof(_address));

    _connected = false;

    _temperature = NAN;

    _lastRead = 0;

    _state = DS18B20State::Idle;
}

void DS18B20::begin()
{
}

void DS18B20::setBus(uint8_t bus)
{
    _bus = bus;
}

bool DS18B20::setAddress(const uint8_t address[8])
{
    memcpy(_address, address, 8);

    _connected = true;

    return true;
}

void DS18B20::update()
{
    OneWire* ow = OneWireBus::bus(_bus);

    if (ow == nullptr)
    {
        return;
    }

    switch (_state)
    {
        case DS18B20State::Idle:
        {
            ow->reset();

            ow->select(_address);

            ow->write(0x44);

            _lastRead = millis();

            _state = DS18B20State::Converting;

            break;
        }

        case DS18B20State::Converting:
        {
            if (millis() - _lastRead < 750)
            {
                return;
            }

            uint8_t data[9];

            ow->reset();

            ow->select(_address);

            ow->write(0xBE);

            for (uint8_t i = 0; i < 9; i++)
            {
                data[i] = ow->read();
            }

            if (OneWire::crc8(data, 8) != data[8])
            {
                _connected = false;

                _state = DS18B20State::Idle;

                return;
            }

            int16_t raw = ((int16_t)data[1] << 8) | data[0];

            _temperature = raw / 16.0f;

            _connected = true;

            _state = DS18B20State::Idle;

            break;
        }
    }
}

bool DS18B20::isConnected() const
{
    return _connected;
}

float DS18B20::temperature() const
{
    return _temperature;
}

TemperatureSensorType DS18B20::type() const
{
    return TemperatureSensorType::DS18B20;
}