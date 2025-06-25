//
// Created by zxsrxt on 05.06.2025.
//

#include "gui.hpp"

#include <imgui.h>
#include "../variables/variables.hpp"
#include "../ent_system/entsystem.hpp"
#include "../event/impl/on_menu_event.hpp"
#include "../event/impl/on_render_event.hpp"
#include "../managers/eventmanager.hpp"
#include "../managers/modulemanager.hpp"

namespace gui
{
    void run()
    {
        static auto& ent = ent_system::get();
        ImGui::Begin("piska");
        if (auto c = ent->get_controllers( ))ImGui::Text("%d players", c->m_size );

        for (auto&[fst, snd] : module_manager::get()->get_modules())
        {
            if (ImGui::CollapsingHeader(fst.c_str()))
            {
                ImGui::Checkbox(("Enable " + fst).c_str(), &snd->get_enabled());

                if (snd->is_enabled())
                {
                    snd->on_menu();
                }
            }
        }

        ImGui::End();

        auto event = on_render_event("render_event");
        event_manager::get()->on_event(event);
    }
}
