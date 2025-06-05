//
// Created by zxsrxt on 05.06.2025.
//
#pragma once


#include <vector>
#include <string>
#include <cstdint>
#include <Windows.h>
#include <initializer_list>
#include <ranges>

#define IAPI(str) GetProcAddress( GetModuleHandle( "GameAssembly.dll" ), str )

