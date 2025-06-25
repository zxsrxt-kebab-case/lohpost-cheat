//
// Created by zxsrxt on 06.06.2025.
//

#include "playerhook.hpp"

#include <iostream>
#include <ranges>

#include "../../sdk/game/player_data/player_data.hpp"
#include "../../ent_system/entsystem.hpp"
#include "../../event/impl/player_tick_event.hpp"
#include "../../managers/eventmanager.hpp"
#include "../../managers/modulemanager.hpp"
#include "../../sdk/il2cpp/il2cpp.hpp"
#include "../../variables/variables.hpp"

void (*o_player_update)(void* controller);
void player_update(void* controller)
{
    auto event = player_tick_event(std::string("player_tick"));
    event_manager::get()->on_event(event);

    o_player_update(controller);
}

void player_hook::install()
{
    il2cpp_assembly::open("Assembly-CSharp")->image()->get_class("", "PLH")->
    get_method("Update", 0)->hook<&player_update>(&o_player_update);
}
