//
// Created by zxsrxt on 06.06.2025.
//

#ifndef PLAYERHOOK_HPP
#define PLAYERHOOK_HPP
#include <string>

#include "../base_hook.hpp"

class player_hook : public base_hook
{
public:
    void install() override;
    explicit player_hook(const std::string& name) : base_hook(name) {};
};

#endif //PLAYERHOOK_HPP
