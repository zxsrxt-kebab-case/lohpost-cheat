//
// Created by zxsrxt on 05.06.2025.
//

#include "gui.hpp"

#include "../sdk/unity/camera/c_camera.hpp"
#include "../../deps/imgui/imgui.h"
#include "../sdk/il2cpp/il2cpp.hpp"
#include "../variables/variables.hpp"
#include "../ent_system/entsystem.hpp"

namespace gui
{

    void run()
    {
        static auto& vars = variables::get();
        ImGui::Begin("pisun");
        ImGui::Text("%d players", ent_system::get()->m_controllers.size( ) );
        ImGui::Checkbox("esp enable", &vars->esp_enabled);

        ImGui::End();
        /*if (enabledsss)
        {
            auto camera = c_camera::get_main();
            auto draw = ImGui::GetBackgroundDrawList();
            for (auto player : players)
            {
                if (!player) continue;

                auto pos = player->get_transform()->get_position();
                auto ws = camera->w2s(pos);
                if (!ws.checker) continue;

                draw->AddLine({1920 / 2, 0}, ws.pos, ImColor(255, 255, 255));
            }
        }

        players.clear( );*/
    }


    void (*o_shot_update)(c_component* controller);
    void shot_update(c_component* controller)
    {
        controller->get_transform()->set_position({0, 0, 0});
        o_shot_update(controller);
    }

    void single()
    {
        il2cpp_assembly::open("Assembly-CSharp")->image()->get_class("Source.Game.Abstract.Ballistics.Projectiles", "MovingProjectile")->
        get_method("Update", 0)->hook<&shot_update>(&o_shot_update);
    }




}