//
// Created by zxsrxt on 05.06.2025.
//

#include "gui.hpp"

#include <imgui.h>
#include "../sdk/il2cpp/il2cpp.hpp"
#include "../variables/variables.hpp"
#include "../ent_system/entsystem.hpp"
#include "../event/impl/render_event.hpp"
#include "../managers/eventmanager.hpp"
#include "../managers/modulemanager.hpp"

namespace gui
{

    void run()
    {
        static auto& vars = variables::get();
        ImGui::Begin("pisun");
        ImGui::Text("%d players", ent_system::get()->m_controllers.size( ) );

        for (auto& module : module_manager::get()->modules)
            ImGui::Checkbox(module->get_name().c_str(), &module->enabled);

        ImGui::End();

        auto event = render_event("render_event");
        event_manager::get()->on_event(event);
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
