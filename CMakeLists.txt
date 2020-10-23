cmake_minimum_required(VERSION 3.16)
project(WormsPrototype)

set(CMAKE_CXX_STANDARD 20)
add_executable(WormsPrototype
        main.cpp
        GameWorld.h GameWorld.cpp
        Terrain.h Terrain.cpp
        Animation.h Animation.cpp
        Unit.h Unit.cpp
        Terrain.h Terrain.cpp
        Entity.h Entity.cpp
        Weapon.h Weapon.cpp)

set(SFML_ROOT "D:/Libraries/SFML")

set(CMAKE_MODULE_PATH "D:/Libraries/SFML/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics network audio window system )

include_directories(D:/Libraries/SFML/include/SFML)
target_link_libraries(WormsPrototype D:/Libraries/SFML/lib sfml-graphics sfml-network sfml-audio sfml-window sfml-system)