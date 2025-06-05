//
// Created by zxsrxt on 05.06.2025.
//

#include "gui.hpp"
#include "../sdk/game/newcharactercontroller.hpp"
#include "../sdk/unity/camera/c_camera.hpp"
#include "../../deps/imgui/imgui.h"
#include "../sdk/il2cpp/il2cpp.hpp"

namespace gui
{
    std::vector<new_character_controller*> players;

    void run()
    {
        static bool enabledsss = false;

        ImGui::Begin("pisun");
        ImGui::Text("%d players", players.size( ) );
        ImGui::Checkbox("enabledss", &enabledsss);

        ImGui::End();
        if (enabledsss)
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

        players.clear( );
    }

    void (*o_player_update)(new_character_controller* controller);
    void player_update(new_character_controller* controller)
    {
        if (std::ranges::find(players, controller) == players.end())
        {
            players.push_back(controller);
        }
        o_player_update(controller);
    }
    void (*o_shot_update)(c_component* controller);
    void shot_update(c_component* controller)
    {
        controller->get_transform()->set_position({0, 0, 0});
        o_shot_update(controller);
    }

    void single()
    {
        il2cpp_assembly::open("Assembly-CSharp")->image()->get_class("Source.Game.Client.Movement", "NewClientCharacterController")->
        get_method("Update", 0)->hook<&player_update>(&o_player_update);
        il2cpp_assembly::open("Assembly-CSharp")->image()->get_class("Source.Game.Abstract.Ballistics.Projectiles", "MovingProjectile")->
        get_method("Update", 0)->hook<&shot_update>(&o_shot_update);
    }




}