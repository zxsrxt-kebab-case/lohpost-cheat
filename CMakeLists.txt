cmake_minimum_required(VERSION 3.31)
project(cheat)

set(CMAKE_COMPILER_ID_TESTS OFF)

set(CMAKE_CXX_STANDARD 26)

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
    set(CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
endif()


file(GLOB_RECURSE ALL_SOURCES
        "src/*.cpp"
        "src/*.c"
        "deps/*.cpp"
        "deps/*.c"
)

list(FILTER ALL_SOURCES EXCLUDE REGEX ".*CMakeFiles.*")
list(FILTER ALL_SOURCES EXCLUDE REGEX ".*cmake-build-.*")


add_library(cheat SHARED ${ALL_SOURCES})

if(MINGW)
    target_link_libraries(cheat PRIVATE
            -static-libgcc
            -static-libstdc++
            -Wl,-Bstatic,--whole-archive
            -lstdc++
            -lgcc
            -Wl,--no-whole-archive
    )
endif()

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
)


target_link_libraries(cheat PRIVATE d3d11.lib d3dcompiler.lib dxguid.lib)