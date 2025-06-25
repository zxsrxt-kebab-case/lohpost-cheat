//
// Created by zxsrxt on 07.06.2025.
//

#include "esp_module.hpp"

#include "../../../sdk/unity/camera/c_camera.hpp"
#include "../../../ent_system/entsystem.hpp"

void esp_module::on_render()
{
    static const auto& ent = ent_system::get();
    auto local_player = ent->get_controller();
    if (!ent) return;

    auto local_team = local_player->team();

    auto* camera = c_camera::get_main();
    auto* draw = ImGui::GetBackgroundDrawList();
    for (player_data* player : *ent->get_controllers())
    {
        if (!player) continue;

        if (player->is_local())
            continue;
        if (player->team() == local_team)
            continue;
        if (player->health() < 1)
            continue;

        auto pos = player->lerp_pos();
        auto ws = camera->w2s(pos);
        if (!ws.checker) continue;

        draw->AddLine({1920 / 2, 0}, ws.pos, ImColor(255, 255, 255));
    }
}
void esp_module::on_menu()
{
    ImGui::Checkbox("box", &box);
    ImGui::Checkbox("health", &health);
    ImGui::Checkbox("name", &name);
    ImGui::Checkbox("skeletone", &skeleton);
}

