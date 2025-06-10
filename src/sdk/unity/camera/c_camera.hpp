//
// Created by zxsrxt on 05.06.2025.
//

#ifndef C_CAMERA_HPP
#define C_CAMERA_HPP

#include "../component/c_component.hpp"
#include "../structs/vec3.hpp"
#include "../common.hpp"

#include <imgui.h>


class c_camera : public c_component
{
public:
    struct c_matrix
    {
        float m[4][4];
        float* operator[](int i)
        {
            return m[i];
        }
    };
    struct w2s_ret
    {
        bool checker;
        ImVec2 pos;
    };
    static c_camera* get_main();
    w2s_ret w2s(vec3_t pos);
};



#endif //C_CAMERA_HPP
