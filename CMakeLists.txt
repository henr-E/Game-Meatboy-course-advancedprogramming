cmake_minimum_required(VERSION 3.20)
project(2022_project_henrey_T)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")

# Export compile commands for completion engines (optional)
# will be found in the cmake-build-debug file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_library(logicLibrary_meatBoy
        Game_Logic/structures_enums_std_include.h
        Game_Logic/Camera.h

        Game_Logic/World.h
        Game_Logic/World.cpp

        Game_Logic/Models/Model.h
        Game_Logic/Stopwatch.h
        Game_Logic/Stopwatch.cpp
        Game_Logic/AbstractFactory.h

        Game_Logic/Models/PlayerModel.h
        Game_Logic/Models/WallModel.h
        Game_Logic/Models/GoalModel.h
        Game_Logic/Models/PlayerModel.cpp

        Game_Logic/Observer.h
        Game_Logic/Subject.cpp
        Game_Logic/Subject.h
        Game_Logic/Models/Model.cpp Game_Logic/Camera.cpp)

add_executable(2022_project_henrey_T
        src/main.cpp


        Game_representation/InputToGame/InputParser.h
        Game_representation/InputToGame/InputParser.cpp

        Game_representation/States/LevelState.h
        Game_representation/States/MenuState.h
        Game_representation/States/State.h

        Game_representation/States/LevelState.cpp
        Game_representation/States/MenuState.cpp
        Game_representation/States/State.cpp


        Game_representation/Game.h
        Game_representation/Game.cpp
        Game_representation/States/StateManager.cpp
        Game_representation/States/StateManager.h

        Game_representation/Views/View.h

        Game_representation/ConcreteFactory.h

        Game_representation/Views/PlayerView.cpp
        Game_representation/Views/PlayerView.h
        Game_representation/Views/WallView.cpp
        Game_representation/Views/WallView.h
        Game_representation/Views/GoalView.cpp
        Game_representation/Views/GoalView.h
        Game_representation/ConcreteFactory.cpp)

### Set include directory search paths
#target_include_directories(2022_project_henrey_T
#        PRIVATE
#        "${PROJECT_BINARY_DIR}"
#        "${CMAKE_CURRENT_SOURCE_DIR}/include"
#        )
#
## Set executable RPATH
#set_target_properties(2022_project_henrey_T
#        PROPERTIES
#        INSTALL_RPATH
#        "${CMAKE_INSTALL_PREFIX}/lib"
#        )

# Link executable to required SFML modules
target_link_libraries(2022_project_henrey_T sfml-graphics sfml-audio logicLibrary_meatBoy)

# Set executable install location
install(TARGETS 2022_project_henrey_T DESTINATION bin)

## Set install location for resources
#install(DIRECTORY content
#        DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
#        )


IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()



