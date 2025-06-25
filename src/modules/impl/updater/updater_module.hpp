//
// Created by zxsrxt on 25.06.2025.
//

#ifndef UPDATER_HPP
#define UPDATER_HPP
#include "../../module_t.hpp"

class updater_module : public module_t
{
public:
    void on_tick() override;

    explicit updater_module(const std::string& name) : module_t(name)
    {
    }
};



#endif //UPDATER_HPP
