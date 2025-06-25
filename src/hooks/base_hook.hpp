//
// Created by zxsrxt on 25.06.2025.
//

#ifndef BASE_HOOK_HPP
#define BASE_HOOK_HPP

class base_hook
{
    std::string m_name;
    bool m_hooked = false;
public:
    virtual ~base_hook() = default;

    virtual void install() = 0;

    bool& get_hooked()
    {
        return m_hooked;
    }

    explicit base_hook(const std::string& name) : m_name(name) {};
};

#endif //BASE_HOOK_HPP
