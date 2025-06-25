//
// Created by zxsrxt on 25.06.2025.
//

#include "updater_module.hpp"

#include "../../../ent_system/entsystem.hpp"
#include "../../../sdk/game/plh/plh.hpp"

void updater_module::on_tick()
{
    static const auto& ent = ent_system::get();
    const auto players = plh::get()->players();
    if (!players)
        return;

    const auto it = std::ranges::find_if(*players, [&](player_data* player)
    {
        if (!player || player->health() < 1)
            return false;

        return player->is_local();
    });

    ent->set_controller(it == players->end() ? nullptr : *it);
    ent->set_controllers(players);
}
