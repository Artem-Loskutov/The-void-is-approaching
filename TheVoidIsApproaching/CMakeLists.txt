cmake_minimum_required(VERSION 4.0.2)
project(TheVoidIsApproaching)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
${PROJECT_SOURCE_DIR}
${PROJECT_SOURCE_DIR}/Include-Files
${PROJECT_SOURCE_DIR}/Code-Files
)

set(SOURCES
    main.cpp
    Code-Files/json-loader.cpp
    Code-Files/main-functions.cpp
    Code-Files/battle.cpp
    Code-Files/entity-class.cpp
    Code-Files/inventory-class.cpp
    Code-Files/game-class.cpp
)

add_executable(game ${SOURCES})
