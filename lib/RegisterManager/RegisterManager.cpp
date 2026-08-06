#include "RegisterManager.h"

Register* RegisterManager::_registers[RegisterManager::MAX_REGISTERS];

uint8_t RegisterManager::_count = 0;

void RegisterManager::begin()
{
}

void RegisterManager::update()
{
    for(uint8_t i=0;i<_count;i++)
    {
        _registers[i]->update();
    }
}

bool RegisterManager::addRegister(Register* reg)
{
    if(_count>=MAX_REGISTERS)
    {
        return false;
    }

    _registers[_count++] = reg;

    return true;
}

Register* RegisterManager::reg(uint8_t index)
{
    if(index>=_count)
    {
        return nullptr;
    }

    return _registers[index];
}

uint8_t RegisterManager::count()
{
    return _count;
}