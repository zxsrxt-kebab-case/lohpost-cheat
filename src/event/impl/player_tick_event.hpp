//
// Created by zxsrxt on 07.06.2025.
//

#ifndef PLAYER_TICK_EVENT_HPP
#define PLAYER_TICK_EVENT_HPP
#include <string>

#include "../event_t.hpp"
#include "../../sdk/game/player_data/player_data.hpp"

class player_tick_event : public event_t
{
public:

    explicit player_tick_event(const std::string &name) : event_t(name)
    {}
};

#endif //PLAYER_TICK_EVENT_HPP
