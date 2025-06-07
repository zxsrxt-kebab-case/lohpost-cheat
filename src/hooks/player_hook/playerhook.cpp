//
// Created by zxsrxt on 06.06.2025.
//

#include "playerhook.hpp"

#include <ranges>

#include "../../sdk/game/character/newcharactercontroller.hpp"
#include "../../ent_system/entsystem.hpp"
#include "../../event/impl/player_tick_event.hpp"
#include "../../managers/eventmanager.hpp"
#include "../../managers/modulemanager.hpp"
#include "../../sdk/il2cpp/il2cpp.hpp"
#include "../../variables/variables.hpp"

void (*o_player_update)(new_character_controller* controller);
void player_update(new_character_controller* controller)
{
    if (variables::get()->esp_enabled)
    {
        static auto& ent = ent_system::get();
        if (auto& players = ent->m_controllers; std::ranges::find(players, controller) == players.end())
        {
            players.push_back(controller);
        }
        if (controller->identity()->is_local())
        {
            ent->m_controller = controller;
        }

        auto event = player_tick_event(std::string("player_tick"), controller);
        event_manager::get()->on_event(event);
    }
    o_player_update(controller);
}

void player_hook::hook()
{
    il2cpp_assembly::open("Assembly-CSharp")->image()->get_class("Source.Game.Client.Movement", "NewClientCharacterController")->
    get_method("Update", 0)->hook<&player_update>(&o_player_update);
}
