cmake_minimum_required(VERSION 3.21)

Project(cpptemplate)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# /MDd /MP /Zi /arch:AVX2
add_compile_options(
    $<$<CONFIG:Debug>:/MDd>
    $<$<CONFIG:Debug>:/MP>
    $<$<CONFIG:Debug>:/Zi>
    $<$<CONFIG:Debug>:/arch:AVX2>
)

# /MD /MP /Oi /O2 /Gy /GL /Gw /fp:fast /arch:AVX2 /GR- /GS- /EHsc-
add_compile_options(
    $<$<CONFIG:Release>:/arch:AVX2>
    $<$<CONFIG:Release>:/EHsc->
    $<$<CONFIG:Release>:/fp:fast>
    $<$<CONFIG:Release>:/Gy>
    $<$<CONFIG:Release>:/GL>
    $<$<CONFIG:Release>:/Gw>
    $<$<CONFIG:Release>:/MD>
    $<$<CONFIG:Release>:/MP>
    $<$<CONFIG:Release>:/Oi>
    $<$<CONFIG:Release>:/O2>
    $<$<CONFIG:Release>:/GR->
    $<$<CONFIG:Release>:/GS->
)

# /OPT:REF /OPT:ICF /LTCG /MERGE:_RDATA=.rdata
add_link_options(
    $<$<CONFIG:Release>:/LTCG>
    $<$<CONFIG:Release>:/MERGE:_RDATA=.rdata>
    $<$<CONFIG:Release>:/OPT:REF>
    $<$<CONFIG:Release>:/OPT:ICF>
)

add_executable(cpptemplate src/main.cpp)
