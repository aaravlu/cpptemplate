cmake_minimum_required(VERSION 3.21)

Project(cpptemplate)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options($<$<CONFIG:Debug>:/MP>)
add_compile_options($<$<CONFIG:Debug>:/MD>)
add_compile_options($<$<CONFIG:Debug>:/ZI>)

add_compile_options($<$<CONFIG:Release>:/MD>)
add_compile_options($<$<CONFIG:Release>:/O2>)
add_compile_options($<$<CONFIG:Release>:/GR->)
add_compile_options($<$<CONFIG:Release>:/GY>)
add_compile_options($<$<CONFIG:Release>:/GL>)
add_compile_options($<$<CONFIG:Release>:/GW>)
add_compile_options($<$<CONFIG:Release>:/OI>)
add_compile_options($<$<CONFIG:Release>:/GS->)

add_executable(cpptemplate src/main.cpp)
add_executable(cpptemplate src/main.cpp)
