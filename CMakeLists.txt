cmake_minimum_required(VERSION 3.31)
project(cheat)

set(CMAKE_COMPILER_ID_TESTS OFF)
set(CMAKE_CXX_STANDARD 26)

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
    set(CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
endif()

include(FetchContent)

FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.91.9b
)
FetchContent_Declare(
        minhook
        GIT_REPOSITORY https://github.com/TsudaKageyu/minhook.git
        GIT_TAG v1.3.4
)

FetchContent_MakeAvailable(imgui minhook)

file(GLOB_RECURSE PROJECT_SOURCES
        "src/*.cpp"
        "src/*.c"
        "main.cpp"
)

file(GLOB IMGUI_SOURCES
    ${imgui_SOURCE_DIR}/*.cpp
)

list(APPEND IMGUI_SOURCES
    ${imgui_SOURCE_DIR}/backends/imgui_impl_dx11.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_win32.cpp
)
file(GLOB_RECURSE MH_SOURCES
    ${minhook_SOURCE_DIR}/*.c
)

list(FILTER IMGUI_SOURCES EXCLUDE REGEX ${imgui_SOURCE_DIR}/examples/)
list(FILTER PROJECT_SOURCES EXCLUDE REGEX ".*CMakeFiles.*")
list(FILTER PROJECT_SOURCES EXCLUDE REGEX ".*cmake-build-.*")

add_library(cheat SHARED ${PROJECT_SOURCES} ${IMGUI_SOURCES} ${MH_SOURCES})

target_include_directories(cheat PRIVATE
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
        ${minhook_SOURCE_DIR}/include
)

target_link_libraries(cheat PRIVATE
        kernel32
        user32
        gdi32
        winspool
        shell32
        ole32
        oleaut32
        uuid
        dwmapi
        comdlg32
        advapi32
        d3d11
        d3dcompiler
        dxguid
)

if(MINGW)
    target_link_options(cheat PRIVATE
            -static-libgcc
            -static-libstdc++
            -Wl,-Bstatic,--whole-archive
            -lstdc++
            -lgcc
            -Wl,--no-whole-archive
    )
endif()