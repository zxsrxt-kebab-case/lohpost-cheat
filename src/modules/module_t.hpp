//
// Created by zxsrxt on 07.06.2025.
//

#ifndef MODULE_HPP
#define MODULE_HPP

#include <string>

#include "interface_module.hpp"

class module_t : public i_module
{
public:
    std::string name;
    bool enabled;

    explicit module_t(std::string name) : name(name), enabled(false) {}

    bool is_enabled() const { return enabled; }

    void set_enabled(bool enabled)
    {
        this->enabled = enabled;
        if (this->enabled)
            on_enable();
        else
            on_disable();
    }
    std::string get_name() const { return name; }
};



#endif //MODULE_HPP
