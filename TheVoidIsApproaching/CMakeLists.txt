cmake_minimum_required(VERSION 4.0.2)
project(TheVoidIsApproaching)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
${PROJECT_SOURCE_DIR}
${PROJECT_SOURCE_DIR}/include
${PROJECT_SOURCE_DIR}/src
)

set(SOURCES
    main.cpp
    src/json-loader.cpp
    src/game.cpp
    src/entity.cpp
    src/inventory.cpp
    src/battle.cpp
    src/main-functions.cpp
    src/interface.cpp
)

add_executable(game ${SOURCES})
