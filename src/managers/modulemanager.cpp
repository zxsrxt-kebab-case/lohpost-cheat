//
// Created by zxsrxt on 07.06.2025.
//

#include "modulemanager.hpp"
#include "../modules/impl/espmodule.hpp"

void module_manager::initialize()
{
    m_modules["esp"] = std::make_unique<esp_module>("esp");
}
