//
// Created by zxsrxt on 07.06.2025.
//

#include "eventmanager.hpp"

#include <ranges>

#include "modulemanager.hpp"

#include "../event/impl/player_tick_event.hpp"
#include "../event/impl/render_event.hpp"

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
        auto callback = *it;

        callback.m_callback(event);

        if (callback.m_type == event_callback::event_type_e::once)
            m_callbacks.erase(it);
    }

    for (const auto &val: module_manager::get()->m_modules | std::views::values)
    {
        if (!val->is_enabled())
            continue;

        val->on_event(event);

        if (auto player_tick = dynamic_cast<player_tick_event*>(&event))
        {
            val->on_tick();
        }
        if (auto player_tick = dynamic_cast<render_event*>(&event))
        {
            val->on_render();
        }
    }
}
