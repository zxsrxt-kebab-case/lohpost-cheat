//
// Created by zxsrxt on 07.06.2025.
//

#ifndef EVENT_HPP
#define EVENT_HPP
#include <string>


class event_t
{
private:
    std::string m_name;
    bool m_is_cancel;
public:
    explicit event_t(const std::string &name) : m_name(name), m_is_cancel(false) {}
    virtual ~event_t() = default;

    void set_cancel(const bool c) { m_is_cancel = c; }
    [[nodiscard]] bool get_cancel() const { return m_is_cancel; }

    [[nodiscard]] std::string get_name() const { return m_name; }
};



#endif //EVENT_HPP
