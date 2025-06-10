//
// Created by zxsrxt on 07.06.2025.
//

#ifndef MODULEMANAGER_HPP
#define MODULEMANAGER_HPP

#include <vector>
#include <memory>

#include "../modules/module_t.hpp"
#include "../singleton/singleton.hpp"


class module_manager : public singleton<module_manager>
{
public:
    std::vector<std::unique_ptr<module_t>> modules;

    void initialize();
};



#endif //MODULEMANAGER_HPP
