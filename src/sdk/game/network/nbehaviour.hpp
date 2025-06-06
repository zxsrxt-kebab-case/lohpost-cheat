//
// Created by zxsrxt on 06.06.2025.
//

#ifndef NBEHAVIOUR_HPP
#define NBEHAVIOUR_HPP

#include "../../unity/component/c_component.hpp"
#include "nidentity.hpp"

class n_behaviour : public c_component
{
public:
    n_identity* identity();
};



#endif //NBEHAVIOUR_HPP
