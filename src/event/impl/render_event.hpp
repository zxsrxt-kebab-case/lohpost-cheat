//
// Created by zxsrxt on 07.06.2025.
//

#ifndef RENDER_EVENT_HPP
#define RENDER_EVENT_HPP
#include "../event_t.hpp"
#include <imgui.h>

class render_event : public event_t
{
public:

    explicit render_event(const std::string &name) : event_t(name) {}
};

#endif //RENDER_EVENT_HPP
