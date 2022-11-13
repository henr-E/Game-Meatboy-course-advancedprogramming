cmake_minimum_required(VERSION 3.20)
project(2022_project_henrey_T)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")

SET(SRC
        src/main.cpp
        src/input.cpp
        src/input.h
        src/update.cpp
        src/update.h
        src/draw.cpp
        src/draw.h
        src/player.cpp
        src/player.h)

ADD_EXECUTABLE(hw ${SRC})

INSTALL(TARGETS hw DESTINATION bin)

IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()



#include_directories(/usr/local/include)
#find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
#include_directories(${SFML_INCLUDE_DIRS})
#target_link_libraries(2022_project_henrey_T sfml-window sfml-graphics sfml-audio sfml-network)
