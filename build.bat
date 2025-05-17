@echo off
setlocal

if /i "%1"=="release" (
    cmake -B build/release -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release && cmake --build build/release
) else (
    cmake -B build/debug -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Debug && cmake --build build/debug
)

endlocal
@echo on
