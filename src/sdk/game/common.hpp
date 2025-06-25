//
// Created by zxsrxt on 11.06.2025.
//

#include <type_traits>

#ifndef COMMON_HPP
#define COMMON_HPP

#define declare_member_v(type, name, field) type& name() { return *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(this) + field); }

#define declare_member(type, name, field) type name() { return *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(this) + field); }

#define ENTRY_POINT \
    static il2cpp_class* this_class = nullptr; \
    if(!this_class) \
        this_class = get_class();\

#define get_this_field(flags, index) \
    ENTRY_POINT \
    static auto fld = this_class->get_field(flags, index);

#endif //COMMON_HPP
