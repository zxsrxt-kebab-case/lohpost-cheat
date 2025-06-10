//
// Created by zxsrxt on 07.06.2025.
//

#ifndef ESPMODULE_HPP
#define ESPMODULE_HPP

#include "../module_t.hpp"

class esp_module : public module_t
{
public:
    void on_render() override;

    void on_event(event_t& event) override {}
    void on_tick() override {}
    void on_enable() override {}
    void on_disable() override {}

    esp_module(std::string name) : module_t(name)
    {

    }
};



#endif //ESPMODULE_HPP
