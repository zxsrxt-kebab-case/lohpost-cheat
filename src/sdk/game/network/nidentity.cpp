//
// Created by zxsrxt on 06.06.2025.
//

#include "nidentity.hpp"

bool n_identity::is_local()
{
    return *reinterpret_cast<bool*>(reinterpret_cast<uintptr_t>(this) + 0x1A);
}
std::uint32_t n_identity::net_id()
{
    return *reinterpret_cast<std::uint32_t*>(reinterpret_cast<uintptr_t>(this) + 0x28);
}

