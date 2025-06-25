//
// Created by zxsrxt on 24.06.2025.
//

#ifndef ON_MENU_EVENT_HPP
#define ON_MENU_EVENT_HPP

#include "../event_t.hpp"

class on_menu_event : public event_t
{
public:

    explicit on_menu_event(const std::string &name) : event_t(name) {}
};

#endif //ON_MENU_EVENT_HPP
