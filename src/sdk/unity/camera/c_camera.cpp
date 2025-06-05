//
// Created by zxsrxt on 05.06.2025.
//

#include "c_camera.hpp"

c_camera *c_camera::get_main()
{
    return reinterpret_cast<c_camera *(*)()>(il2cpp_icall::resolve("UnityEngine.Camera::get_main"))();
}

inline float dot(const vec3_t &Vec1, const vec3_t &Vec2)
{
    return Vec1.x * Vec2.x + Vec1.y * Vec2.y + Vec1.z * Vec2.z;
}

c_camera::w2s_ret c_camera::w2s(vec3_t pos)
{
    ImVec2 screen = ImGui::GetIO( ).DisplaySize;

    auto internal = *reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(this) + 0x10);
    auto mtx = *reinterpret_cast<c_matrix*>(internal + 740);

    vec3_t trans_vec = vec3_t( mtx[ 0 ][ 3 ], mtx[ 1 ][ 3 ], mtx[ 2 ][ 3 ] );
    vec3_t right_vec = vec3_t( mtx[ 0 ][ 0 ], mtx[ 1 ][ 0 ], mtx[ 2 ][ 0 ] );
    vec3_t up_vec = vec3_t( mtx[ 0 ][ 1 ], mtx[ 1 ][ 1 ], mtx[ 2 ][ 1 ] );

    float w = dot( trans_vec, pos ) + mtx[ 3 ][ 3 ];
    if ( w < 0.9f )
        return w2s_ret{ false, {0, 0} };

    float y = dot( up_vec, pos ) + mtx[ 3 ][ 1 ];
    float x = dot( right_vec, pos ) + mtx[ 3 ][ 0 ];

    return w2s_ret{ true, {( screen.x / 2 ) * ( 1.f + x / w ), ( screen.y / 2 ) * ( 1.f - y / w )} };
}
