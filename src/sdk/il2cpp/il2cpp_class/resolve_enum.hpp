//
// Created by zxsrxt on 25.06.2025.
//

#ifndef RESOLVE_ENUM_HPP
#define RESOLVE_ENUM_HPP
#include <cstdint>

enum resolve_enum : uint32_t
{
    field_static,
    field_public,
    field_private,
    field_protected,
    field_internal,
    field_readonly,
    field_enum,
    field_array,
    field_pointer,
    field_boolean,
    field_integer,
    field_float,
    field_string,
    field_vector2,
    field_vector3,
    field_vector4,
};

#endif //RESOLVE_ENUM_HPP
