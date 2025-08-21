cmake_minimum_required(VERSION 3.21)

Project(cpptemplate)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    # /arch:AVX2 /MDd /MP /Zi
    # /arch:AVX2 /MD /MP /Oi /O2 /Gy /GL /Gw /fp:fast /GR- /GS-
    add_compile_options(
        $<$<CONFIG:Debug>:/arch:AVX2>
        $<$<CONFIG:Debug>:/MDd>
        $<$<CONFIG:Debug>:/MP>
        $<$<CONFIG:Debug>:/Zi>

        $<$<CONFIG:Release>:/arch:AVX2>
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
        $<$<CONFIG:Release>:/MANIFEST:NO>
        $<$<CONFIG:Release>:/MERGE:_RDATA=.rdata>
        $<$<CONFIG:Release>:/OPT:REF>
        $<$<CONFIG:Release>:/OPT:ICF>
    )
endif(MSVC)

add_executable(test "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp")
