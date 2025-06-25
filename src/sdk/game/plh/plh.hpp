//
// Created by zxsrxt on 25.06.2025.
//

#ifndef PLH_HPP
#define PLH_HPP

#include "../sdk_base.hpp"
#include "../../../singleton/singleton.hpp"
#include "../../unity/il2cpp_array/il2cpp_array.hpp"
#include "../player_data/player_data.hpp"

class plh : sdk_base, public singleton<plh>
{
    const char* _get_namespace() override { return ""; }
    const char* _get_name() override { return "PLH"; }
public:
    il2cpp_array<player_data*>* players();
};



#endif //PLH_HPP
