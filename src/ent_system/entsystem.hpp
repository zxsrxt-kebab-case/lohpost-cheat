//
// Created by zxsrxt on 05.06.2025.
//

#ifndef ENTSYSTEM_HPP
#define ENTSYSTEM_HPP

#include <vector>
#include "../singleton/singleton.hpp"
#include "../sdk/game/player_data/player_data.hpp"
#include "../sdk/unity/il2cpp_array/il2cpp_array.hpp"

class ent_system : public singleton<ent_system>
{
public:
    [[nodiscard]] il2cpp_array<player_data *> * get_controllers() const { return m_controllers; }
    void set_controllers(il2cpp_array<player_data *> *m_controllers) { this->m_controllers = m_controllers; }
    [[nodiscard]] player_data * get_controller() const { return m_controller; }
    void set_controller(player_data *m_controller) { this->m_controller = m_controller; }

private:
    il2cpp_array<player_data*>* m_controllers = nullptr;
    player_data* m_controller = nullptr;
};



#endif //ENTSYSTEM_HPP
