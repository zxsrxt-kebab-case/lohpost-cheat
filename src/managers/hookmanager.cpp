//
// Created by zxsrxt on 25.06.2025.
//

#include "hookmanager.hpp"

#include "../hooks/player_hook/playerhook.hpp"

void hook_manager::hook()
{
    for (const auto& [name, hook] : hooks)
    {
        if (hook->get_hooked())
            continue;

        hook->install();
        hook->get_hooked() = true;
    }
}
void hook_manager::initialize()
{
    add_hook<player_hook>("player");
}

