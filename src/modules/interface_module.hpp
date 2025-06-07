//
// Created by zxsrxt on 07.06.2025.
//

#ifndef INTERFACE_MODULE_HPP
#define INTERFACE_MODULE_HPP
#include "../event/event_t.hpp"

class i_module
{
public:
    virtual ~i_module() = default;

    virtual void on_event(event_t& event) = 0;
    virtual void on_tick() = 0;
    virtual void on_render() = 0;
    virtual void on_enable() = 0;
    virtual void on_disable() = 0;
};


#endif //INTERFACE_MODULE_HPP
