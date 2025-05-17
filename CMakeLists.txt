cmake_minimum_required(VERSION 3.21)

Project(cpptemplate)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER "C:/BuildTools/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe")
set(CMAKE_CXX_COMPILER "C:/BuildTools/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe")
set(CMAKE_LINKER "C:/BuildTools/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/link.exe")

add_compile_options($<$<CONFIG:Debug>:/MP>)

add_compile_options($<$<CONFIG:Release>:/O2>)
add_compile_options($<$<CONFIG:Release>:/Ot>)
add_compile_options($<$<CONFIG:Release>:/GL>)
add_compile_options($<$<CONFIG:Release>:/arch:AVX2>)
add_compile_options($<$<CONFIG:Release>:/fp:fast>)

add_executable(cpptemplate src/main.cpp)