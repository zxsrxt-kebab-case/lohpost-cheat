//
// Created by zxsrxt on 07.06.2025.
//

#include "espmodule.hpp"

#include "../../sdk/unity/camera/c_camera.hpp"
#include "../../ent_system/entsystem.hpp"

void esp_module::on_render()
{
    auto* camera = c_camera::get_main();
    auto* draw = ImGui::GetBackgroundDrawList();
    for (auto* player : ent_system::get()->m_controllers)
    {
        if (!player) continue;

        auto pos = player->get_transform()->get_position();
        auto ws = camera->w2s(pos);
        if (!ws.checker) continue;

        draw->AddLine({1920 / 2, 0}, ws.pos, ImColor(255, 255, 255));
    }
}
