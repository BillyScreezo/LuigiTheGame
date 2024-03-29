if (WIN32)
    set(CMAKE_SYSTEM_NAME Windows)
    set(CMAKE_C_COMPILER_WORKS 1)
    set(CMAKE_CXX_COMPILER_WORKS 1)
else ()
    set(CMAKE_SYSTEM_NAME Linux)
    set(C_COMPILER_NAME "gcc")
    set(CXX_COMPILER_NAME "g++")
    set(CMAKE_C_COMPILER ${C_COMPILER_NAME})
    set(CMAKE_CXX_COMPILER ${CXX_COMPILER_NAME})
endif ()

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

