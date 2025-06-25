//
// Created by zxsrxt on 07.06.2025.
//

#ifndef ESPMODULE_HPP
#define ESPMODULE_HPP

#include <complex>

#include "../../module_t.hpp"

class esp_module : public module_t
{
public:

    bool box = false, health = false, name = false, skeleton = false;

    void on_render() override;
    void on_menu() override;

    explicit esp_module(const std::string& name) : module_t(name)
    {
    }
};



#endif //ESPMODULE_HPP
