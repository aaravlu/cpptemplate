cmake_minimum_required(VERSION 3.21)

Project(cpptemplate)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER "C:/BuildTools/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe")
set(CMAKE_CXX_COMPILER "C:/BuildTools/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe")
set(CMAKE_LINKER "C:/BuildTools/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/link.exe")

add_compile_options($<$<CONFIG:Debug>:/MP>)

add_compile_options($<$<CONFIG:Release>:/O2>) # 最大化速度
add_compile_options($<$<CONFIG:Release>:/Os>)  # 优化大小
add_compile_options($<$<CONFIG:Release>:/Gy>)  # 函数级链接
add_compile_options($<$<CONFIG:Release>:/Gw>)  # 全局数据优化
add_compile_options($<$<CONFIG:Release>:/Oi>)  # 内联函数扩展
add_compile_options($<$<CONFIG:Release>:/GR->) # 禁用 RTTI
add_compile_options($<$<CONFIG:Release>:/GS->) # 禁用缓冲区检查
add_compile_options($<$<CONFIG:Release>:/GL>)  # 全程序优化

add_executable(cpptemplate src/main.cpp)
