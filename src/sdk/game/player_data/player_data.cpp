//
// Created by zxsrxt on 05.06.2025.
//

#include "player_data.hpp"

#include "../common.hpp"

bool player_data::is_local()
{
    /*constexpr static uint32_t flags = field_boolean | field_internal;
    get_this_field(flags, 1);
    return *reinterpret_cast<bool*>(reinterpret_cast<uintptr_t>(this) + fld->get_offset());*/ //SHIT
    return *reinterpret_cast<bool *>(reinterpret_cast<uintptr_t>(this) + 0x20);
}
il2cpp_string* player_data::get_name()
{
    /*constexpr static uint32_t flags = field_string | field_internal;
    get_this_field(flags, 1);
    return *reinterpret_cast<il2cpp_string**>(reinterpret_cast<uintptr_t>(this) + fld->get_offset());*/ //FUCKIKCKCKSKC
    return *reinterpret_cast<il2cpp_string **>(reinterpret_cast<uintptr_t>(this) + 0x18);
}
int player_data::health()
{
    return *reinterpret_cast<int *>(reinterpret_cast<uintptr_t>(this) + 0x50);
}
int player_data::team()
{
    return *reinterpret_cast<int *>(reinterpret_cast<uintptr_t>(this) + 0x38);
}
vec3_t& player_data::lerp_pos( )
{
    return *reinterpret_cast< vec3_t* >( reinterpret_cast<uintptr_t>(this) + 0xA8 );
}

