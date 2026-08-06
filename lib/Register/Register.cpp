#include "Register.h"

#include "Outputs.h"

Register::Register()
{
    _id = 0;

    _outputOpen = 0;
    _outputClose = 0;

    _openingTimeMs = DEFAULT_TRAVEL_TIME;
    _closingTimeMs = DEFAULT_TRAVEL_TIME;

    _position = DEFAULT_POSITION;

    _state = RegisterState::Unknown;

    _movementStart = 0;
}

void Register::begin()
{
}

void Register::update()
{
}

void Register::open()
{
    Outputs::set(_outputClose, false);
    Outputs::set(_outputOpen, true);

    _movementStart = millis();

    _state = RegisterState::Opening;
}

void Register::close()
{
    Outputs::set(_outputOpen, false);
    Outputs::set(_outputClose, true);

    _movementStart = millis();

    _state = RegisterState::Closing;
}

void Register::stop()
{
    Outputs::set(_outputOpen, false);
    Outputs::set(_outputClose, false);

    _state = RegisterState::Stopped;
}

void Register::setId(uint8_t id)
{
    _id = id;
}

uint8_t Register::id() const
{
    return _id;
}

void Register::setOutputs(uint8_t outputOpen,
                          uint8_t outputClose)
{
    _outputOpen = outputOpen;
    _outputClose = outputClose;
}

void Register::setOpeningTime(uint32_t timeMs)
{
    _openingTimeMs = timeMs;
}

void Register::setClosingTime(uint32_t timeMs)
{
    _closingTimeMs = timeMs;
}

RegisterState Register::state() const
{
    return _state;
}

uint8_t Register::position() const
{
    return _position;
}

bool Register::isOpen() const
{
    return _state == RegisterState::Open;
}

bool Register::isClosed() const
{
    return _state == RegisterState::Closed;
}