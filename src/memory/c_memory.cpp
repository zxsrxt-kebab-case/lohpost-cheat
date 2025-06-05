//
// Created by zxsrxt on 05.06.2025.
//

#include "c_memory.hpp"
#include <windows.h>

void c_memory::init()
{
    game_address = reinterpret_cast<uintptr_t>(GetModuleHandle("GameAssembly.dll"));
}
uintptr_t c_memory::get_address() const
{
    return game_address;
}
