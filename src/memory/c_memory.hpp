//
// Created by zxsrxt on 05.06.2025.
//

#ifndef C_MEMORY_HPP
#define C_MEMORY_HPP

#include "../singleton/singleton.hpp"


class c_memory : public singleton<c_memory>
{
private:
    uintptr_t game_address;

public:
    void init();
    decltype(game_address) get_address() const;
};



#endif //C_MEMORY_HPP
