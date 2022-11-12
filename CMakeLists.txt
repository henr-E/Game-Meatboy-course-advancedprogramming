cmake_minimum_required(VERSION 3.20)
project(2022_project_henrey_T)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(2022_project_henrey_T
        main.cpp)

INSTALL(TARGETS 2022_project_henrey_T DESTINATION bin)
IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()