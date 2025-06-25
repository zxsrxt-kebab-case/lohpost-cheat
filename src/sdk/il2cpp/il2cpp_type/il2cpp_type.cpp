//
// Created by zxsrxt on 25.06.2025.
//

#include "il2cpp_type.hpp"

#include "../common.hpp"

uint32_t il2cpp_type::get_type()
{
    return reinterpret_cast<uint32_t(*)(il2cpp_type*)>(IAPI("il2cpp_type_get_type"))(this);
}
