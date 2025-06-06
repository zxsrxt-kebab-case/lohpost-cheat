//
// Created by zxsrxt on 05.06.2025.
//

#ifndef ENTSYSTEM_HPP
#define ENTSYSTEM_HPP

#include <vector>
#include "../singleton/singleton.hpp"
#include "../sdk/game/character/newcharactercontroller.hpp"

class ent_system : public singleton<ent_system>
{
public:
    std::vector<new_character_controller*> m_controllers;
    new_character_controller* m_controller;
};



#endif //ENTSYSTEM_HPP
