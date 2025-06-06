//
// Created by zxsrxt on 06.06.2025.
//

#include "nbehaviour.hpp"

n_identity *n_behaviour::identity()
{
    return *reinterpret_cast<n_identity **>((uintptr_t)this + 0x38);
}
