cmake_minimum_required(VERSION 3.20)
project(2022_project_henrey_T)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")

# Export compile commands for completion engines (optional)
# will be found in the cmake-build-debug file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT USE_INSTALL_RESOURCE_PATH)
    set(RESOURCE_PATH "${PROJECT_SOURCE_DIR}/content/")
else()
    set(RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}/content/")
endif()

# Find SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_executable(2022_project_henrey_T
        src/main.cpp
        Game_Logic/Player.cpp
        Game_representation/Windows/Game.cpp
        Game_Logic/Stopwatch.cpp
        Game_Logic/World.cpp
        Game_representation/Camera/Camera.cpp
        Game_representation/InputToGame/TileMap.cpp
        Game_representation/InputToGame/TileMap.h
        Game_representation/InputToGame/InputParser.cpp
        Game_representation/InputToGame/InputParser.h
        Game_Logic/Interval.h Game_representation/Windows/Menu.cpp Game_representation/Windows/Menu.h Game_Logic/structures_enums_std_include.h Game_representation/StateManager.h)

# Set include directory search paths
target_include_directories(2022_project_henrey_T
        PRIVATE
        "${PROJECT_BINARY_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        )

# Set executable RPATH
set_target_properties(2022_project_henrey_T
        PROPERTIES
        INSTALL_RPATH
        "${CMAKE_INSTALL_PREFIX}/lib"
        )

# Link executable to required SFML modules
target_link_libraries(2022_project_henrey_T sfml-graphics sfml-audio)

# Set executable install location
install(TARGETS 2022_project_henrey_T DESTINATION bin)


# Set install location for resources
install(DIRECTORY content
        DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
        )


IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()



