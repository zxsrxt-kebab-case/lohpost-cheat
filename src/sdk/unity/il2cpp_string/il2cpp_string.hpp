//
// Created by zxsrxt on 05.06.2025.
//

#ifndef IL2CPP_STRING_HPP
#define IL2CPP_STRING_HPP

#include <cstdint>
#include <string>

//more accurate cls
class il2cpp_string
{
public:
    char pad[sizeof(void*) * 2];
    int32_t length;
    char chars[ 1 ];

    std::string get_string( );
};

std::string utf16le_to_utf8( const std::u16string& u16str );



#endif
