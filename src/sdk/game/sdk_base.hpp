//
// Created by zxsrxt on 25.06.2025.
//

#ifndef SDK_BASE_HPP
#define SDK_BASE_HPP

#include "../il2cpp/il2cpp_assembly/il2cpp_assembly.hpp"
#include "../il2cpp/il2cpp_class/il2cpp_class.hpp"

class sdk_base
{
public:
    virtual ~sdk_base() = default;

protected:

    virtual const char* _get_namespace() { return ""; }
    virtual const char* _get_name() { return ""; }

    il2cpp_class* get_class()
    {
        return il2cpp_assembly::open("Assembly-CSharp")->image()->get_class(_get_namespace(), _get_name());
    }
};

#endif //SDK_BASE_HPP
