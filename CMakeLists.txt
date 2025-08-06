cmake_minimum_required(VERSION 3.21)

Project(cpptemplate)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# /MDd /MP /Zi /arch:AVX2
add_compile_options($<$<CONFIG:Debug>:/MDd>)
add_compile_options($<$<CONFIG:Debug>:/MP>)
add_compile_options($<$<CONFIG:Debug>:/Zi>)
add_compile_options($<$<CONFIG:Debug>:/arch:AVX2>)

# /MD /MP /Oi /O2 /Gy /GL /Gw /fp:fast /arch:AVX2 /GR- /GS-
add_compile_options($<$<CONFIG:Release>:/MD>)
add_compile_options($<$<CONFIG:Release>:/MP>)
add_compile_options($<$<CONFIG:Release>:/Oi>)
add_compile_options($<$<CONFIG:Release>:/O2>)
add_compile_options($<$<CONFIG:Release>:/Gy>)
add_compile_options($<$<CONFIG:Release>:/GL>)
add_compile_options($<$<CONFIG:Release>:/Gw>)
add_compile_options($<$<CONFIG:Release>:/fp:fast>)
add_compile_options($<$<CONFIG:Release>:/arch:AVX2>)
add_compile_options($<$<CONFIG:Release>:/GR->)
add_compile_options($<$<CONFIG:Release>:/GS->)
add_link_options($<$<CONFIG:Release>:/LTCG>)

add_executable(cpptemplate src/main.cpp)
