//
// Created by zxsrxt on 07.06.2025.
//

#include "modulemanager.hpp"
#include "../modules/impl/esp/esp_module.hpp"
#include "../modules/impl/updater/updater_module.hpp"

const std::map<std::string, std::unique_ptr<module_t>>& module_manager::get_modules()
{
    return m_modules;
}
module_t* module_manager::get_module(const std::string& module_name)
{
    auto it = m_modules.find(module_name);

    if (it != m_modules.end())
        return it->second.get();

    throw std::runtime_error("module not found");
}


void module_manager::initialize()
{
    add_module<esp_module>("esp");
    add_module<updater_module>("updater");
}
