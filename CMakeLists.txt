cmake_minimum_required(VERSION 3.21)

project(geode-collab VERSION 0.1.0)

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "iOS" OR IOS)
    set(CMAKE_OSX_ARCHITECTURES "arm64")
else()
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
endif()

find_package(Geode REQUIRED)

add_geode_mod(geode-collab
    SOURCES
        src/main.cpp
        src/CollabSession.cpp
)
