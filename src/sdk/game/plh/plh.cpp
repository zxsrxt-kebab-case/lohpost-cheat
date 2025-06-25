//
// Created by zxsrxt on 25.06.2025.
//

#include "plh.hpp"

#include "../common.hpp"

il2cpp_array<player_data *> *plh::players()
{
    ENTRY_POINT
    return *reinterpret_cast<il2cpp_array<player_data *> **>(this_class->get_static_fields() + 0x10);
}
