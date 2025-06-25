//
// Created by zxsrxt on 05.06.2025.
//

#ifndef PLAYERDATA_HPP
#define PLAYERDATA_HPP

#include "../sdk_base.hpp"
#include "../../unity/il2cpp_string/il2cpp_string.hpp"

struct vec3_t;

class player_data : sdk_base
{
public:
    const char* _get_namespace() override { return ""; }
    const char* _get_name() override { return "KKNCDCLKBDD"; }

    bool is_local();
    il2cpp_string* get_name();
    int health();
    int team();
    vec3_t& lerp_pos( );
};



#endif
