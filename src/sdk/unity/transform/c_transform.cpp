//
// Created by zxsrxt on 05.06.2025.
//

#include "c_transform.hpp"
#include "../common.hpp"

vec3_t c_transform::get_position()
{
    vec3_t ret;
    reinterpret_cast< void( * )( c_transform*, vec3_t* ) >( il2cpp_icall::resolve( "UnityEngine.Transform::get_position_Injected" ) )( this, &ret );
    return ret;
}
vec4_t c_transform::get_rotation( )
{
    vec4_t ret;
    reinterpret_cast< void( * )( c_transform*, vec4_t* ) >( il2cpp_icall::resolve( "UnityEngine.Transform::get_rotation_Injected" ) )( this, &ret );
    return ret;
}
vec3_t c_transform::get_forward( )
{
    static vec3_t forward = { 0, 0, 1 };
    return get_rotation( ) * forward;
}
vec3_t c_transform::get_right( )
{
    static vec3_t right = { 1, 0, 0 };
    return get_rotation( ) * right;
}
vec3_t c_transform::get_up( )
{
    static vec3_t up = { 0, 1, 0 };
    return get_rotation( ) * up;
}
void c_transform::set_position(vec3_t position)
{
    reinterpret_cast< void( * )( c_transform*, vec3_t* ) >( il2cpp_icall::resolve( "UnityEngine.Transform::set_position_Injected" ) )( this, &position );
}
void c_transform::set_rotation( vec4_t rotation )
{
    reinterpret_cast< void( * )( c_transform*, vec4_t* ) >( il2cpp_icall::resolve( "UnityEngine.Transform::set_rotation_Injected" ) )( this, &rotation );
}