//
// Created by zxsrxt on 07.06.2025.
//

#ifndef PLAYER_TICK_EVENT_HPP
#define PLAYER_TICK_EVENT_HPP
#include <string>

#include "../event_t.hpp"
#include "../../sdk/game/character/newcharactercontroller.hpp"

class player_tick_event : public event_t
{
public:
    new_character_controller* m_controller;

    explicit player_tick_event(const std::string &name, new_character_controller* player) : event_t(name), m_controller(player)
    {}
};

#endif //PLAYER_TICK_EVENT_HPP
