set(CXX_COMPILER_NAME "")

if (WIN32)
    set(CMAKE_SYSTEM_NAME Windows)
    set(CXX_COMPILER_NAME "${CXX_COMPILER_NAME}.exe")
else ()
    set(CMAKE_SYSTEM_NAME Linux)
    set(C_COMPILER_NAME "${CXX_COMPILER_NAME}gcc")
    set(CXX_COMPILER_NAME "${CXX_COMPILER_NAME}g++")
endif ()

set(CMAKE_C_COMPILER ${C_COMPILER_NAME})
set(CMAKE_CXX_COMPILER ${CXX_COMPILER_NAME})

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

