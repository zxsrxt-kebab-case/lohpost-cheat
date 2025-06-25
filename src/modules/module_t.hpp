//
// Created by zxsrxt on 07.06.2025.
//

#ifndef MODULE_HPP
#define MODULE_HPP

#include <string>
#include <utility>

#include "interface_module.hpp"

class module_t : public i_module
{
protected:
    std::string name;
    bool enabled;

public:
    explicit module_t(std::string name) : name(std::move(name)), enabled(false) {}

    [[nodiscard]] bool is_enabled() const { return enabled; }
    bool& get_enabled() { return enabled; }
    void set_enabled(bool enabled)
    {
        this->enabled = enabled;
        if (this->enabled)
            on_enable();
        else
            on_disable();
    }
    void on_render() override {}
    void on_menu() override {}
    void on_tick() override {}
    void on_disable() override {}
    void on_enable() override {}
    void on_event(event_t &event) override {}

    [[nodiscard]] std::string get_name() const { return name; }
};



#endif //MODULE_HPP
