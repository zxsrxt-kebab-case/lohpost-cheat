//
// Created by zxsrxt on 07.06.2025.
//

#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP
#include <functional>
#include <vector>


#include "../event/event_t.hpp"

#include "../singleton/singleton.hpp"


class event_callback
{
public:
    enum class event_type_e
    {
        once,
        on
    };

    event_type_e m_type;
    std::function<void(event_t&)> m_callback;

    event_callback(event_type_e type,
                  std::function<void(event_t&)> callback)
        : m_type(type), m_callback(callback) {}

    bool operator==(const event_callback& other) const {
        return m_type == other.m_type
            && m_callback.target_type() == other.m_callback.target_type();
    }

};

class event_manager final : public singleton<event_manager>
{
private:
    std::vector<event_callback> m_callbacks;

public:
    void add_callback(const event_callback &callback);
    void remove_callback(const event_callback &callback);
    void on_event(event_t& event);
};



#endif //EVENTMANAGER_HPP
