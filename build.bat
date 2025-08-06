@echo off
setlocal

if /i "%1"=="" (
    cmake -B build/debug -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Debug && cmake --build build/debug
)
if /i "%1"=="debug" (
    cmake -B build/debug -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Debug && cmake --build build/debug
)
if /i "%1"=="release" (
    cmake -B build/release -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release && cmake --build build/release
)
if /i "%1"=="clean" (
    rm -rf build
)

endlocal
@echo on
