//
// Created by zxsrxt on 05.06.2025.
//

#ifndef C_TRANSFORM_HPP
#define C_TRANSFORM_HPP

#include "../structs/vec3.hpp"
#include "../structs/vec4.hpp"

class c_transform
{
public:
    vec3_t get_position( );
    vec4_t get_rotation( );
    vec3_t get_forward( );
    vec3_t get_right( );
    vec3_t get_up( );
};



#endif //C_TRANSFORM_HPP
