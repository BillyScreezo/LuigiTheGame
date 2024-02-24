cmake_minimum_required(VERSION 3.8)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(LuigiTheGame)

if (WIN32)
    # set(EXECUTABLE_NAME ${PROJECT_NAME}.exe)
    # TODO: add Debug and Release configuration for MSVC compiler
elseif (UNIX)
    # set(EXECUTABLE_NAME ${PROJECT_NAME})
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
    endif()

    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os")
    endif()
else ()
    message(FATAL_ERROR "Unsupported system")
endif()

set(EXECUTABLE_NAME ${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(${EXECUTABLE_NAME}
    main.cpp
    # ${SRC_DIR}/Enemy.cpp
    # ${SRC_DIR}/Foo.cpp
    # ${SRC_DIR}/Ground.cpp
    # ${SRC_DIR}/Levels.cpp
    # ${SRC_DIR}/Map.cpp
    # ${SRC_DIR}/MapCreator.cpp
    # ${SRC_DIR}/Player.cpp
    # ${SRC_DIR}/Prototype.cpp
    # ${SRC_DIR}/Source.cpp
    # ${SRC_DIR}/Timer.cpp
)

# TODO: add OpenMP lib
target_include_directories(${EXECUTABLE_NAME}
    PUBLIC
    ${INC_DIR}
)

# TODO: add executable size output
add_custom_command(TARGET ${EXECUTABLE_NAME}
    POST_BUILD
    COMMENT "[post-build] Copy compile_commands.json to root directory"
    COMMAND cp compile_commands.json ${CMAKE_CURRENT_SOURCE_DIR}/
)

