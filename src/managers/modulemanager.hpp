//
// Created by zxsrxt on 07.06.2025.
//

#ifndef MODULEMANAGER_HPP
#define MODULEMANAGER_HPP

#include <map>
#include <unordered_map>
#include <memory>

#include "../modules/module_t.hpp"
#include "../singleton/singleton.hpp"


template<typename T>
concept is_module = requires
{
  requires std::is_base_of_v<module_t, T>;
};

class module_manager final : public singleton<module_manager>
{
    std::map<std::string, std::unique_ptr<module_t>> m_modules;
public:

    const std::map<std::string, std::unique_ptr<module_t>>& get_modules();
    module_t* get_module(const std::string& name);

    template<is_module module_type>
    void add_module(const std::string& name)
    {
        m_modules.try_emplace(name, std::make_unique<module_type>(name));
    }

    void initialize();
};



#endif //MODULEMANAGER_HPP
