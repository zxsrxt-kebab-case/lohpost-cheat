//
// Created by zxsrxt on 05.06.2025.
//

#include "c_component.hpp"
#include "../common.hpp"

c_transform *c_component::get_transform()
{
    return reinterpret_cast< c_transform * ( * )( c_component* ) >( il2cpp_icall::resolve( "UnityEngine.Component::get_transform" ) )( this );
}
