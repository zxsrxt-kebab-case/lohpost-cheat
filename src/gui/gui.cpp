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
}
