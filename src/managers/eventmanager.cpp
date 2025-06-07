//
// Created by zxsrxt on 07.06.2025.
//

#include "eventmanager.hpp"

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
    std::vector<event_callback> to_remove;
    for (auto callback : m_callbacks)
    {
        callback.m_callback(event);

        if (callback.m_type == event_callback::event_type_e::once)
            to_remove.push_back(callback);
    }
    for (auto& removal : to_remove)
        remove_callback(removal);

    for (auto& module : module_manager::get()->modules)
    {
        if (!module.is_enabled())
            continue;

        module.on_event(event);

        if (auto player_tick = dynamic_cast<player_tick_event*>(&event))
        {
            module.on_tick();
        }
        if (auto player_tick = dynamic_cast<render_event*>(&event))
        {
            module.on_render();
        }
    }
}
