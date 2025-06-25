//
// Created by zxsrxt on 25.06.2025.
//

#ifndef HOOKMANAGER_HPP
#define HOOKMANAGER_HPP
#include <unordered_map>
#include <memory>
#include <string>

#include "../hooks/base_hook.hpp"
#include "../singleton/singleton.hpp"

template<class T>
concept is_hook = requires
{
    requires std::is_base_of_v<base_hook, T>;
};

class hook_manager final : public singleton<hook_manager>
{
    std::unordered_map<std::string, std::unique_ptr<base_hook>> hooks;

public:
    const std::unordered_map<std::string, std::unique_ptr<base_hook>>& get_hooks() const { return hooks; }

    template<is_hook hook>
    void add_hook(const std::string& name)
    {
        hooks.try_emplace(name, std::make_unique<hook>(name));
    }

    void hook();
    void initialize();
};



#endif //HOOKMANAGER_HPP
