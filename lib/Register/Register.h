#ifndef REGISTER_H
#define REGISTER_H

#include <Arduino.h>

enum class RegisterState
{
    Unknown,

    Stopped,

    Opening,

    Closing,

    Open,

    Closed
};

class Register
{
public:

    Register();

    void begin();

    void update();

    // Commandes

    void open();

    void close();

    void stop();

    // Configuration

    void setId(uint8_t id);

    uint8_t id() const;

    void setOutputs(uint8_t outputOpen,
                    uint8_t outputClose);

    void setOpeningTime(uint32_t timeMs);

    void setClosingTime(uint32_t timeMs);

    // Informations

    RegisterState state() const;

    uint8_t position() const;

    bool isOpen() const;

    bool isClosed() const;

private:

    static constexpr uint32_t DEFAULT_TRAVEL_TIME = 120000;

    static constexpr uint8_t DEFAULT_POSITION = 0;
    
    uint8_t _id;

    uint8_t _outputOpen;

    uint8_t _outputClose;

    uint32_t _openingTimeMs;

    uint32_t _closingTimeMs;

    uint8_t _position;

    RegisterState _state;

    unsigned long _movementStart;
};

#endif