//
// Created by zxsrxt on 07.06.2025.
//

#include "eventmanager.hpp"

#include <ranges>

#include "modulemanager.hpp"
#include "../event/impl/on_menu_event.hpp"

#include "../event/impl/player_tick_event.hpp"
#include "../event/impl/on_render_event.hpp"

void event_manager::add_callback(const event_callback &callback)
{
    m_callbacks.push_back(callback);
}

void event_manager::remove_callback(const event_callback &callback)
{
    auto it = std::remove(m_callbacks.begin(), m_callbacks.end(), callback);
    m_callbacks.erase(it, m_callbacks.end());
}

void event_manager::on_event(event_t& event)
{
    for (auto it = m_callbacks.begin(); it != m_callbacks.end(); ++it)
    {
        const auto& callback = *it;

        callback.m_callback(event);

        if (callback.m_type == event_callback::event_type_e::once)
            m_callbacks.erase(it);
    }

    for (const auto &module: module_manager::get()->get_modules() | std::views::values)
    {
        if (!module->is_enabled())
            continue;

        if (event.get_cancel())
            continue;

        module->on_event(event);

        if (auto player_tick = dynamic_cast<player_tick_event*>(&event))
        {
            module->on_tick();
        }
        if (auto render_event = dynamic_cast<on_render_event*>(&event))
        {
            module->on_render();
        }
        if (auto menu_event = dynamic_cast<on_menu_event*>(&event))
        {
            module->on_menu();
        }
    }
}
