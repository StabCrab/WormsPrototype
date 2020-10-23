#include <iostream>
#include <SFML/Graphics.hpp>
#include "Unit.h"
#include "Terrain.h"
#include "GameWorld.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500),
                            "Worms Prototype");
    GameWorld world(window, "terrain2.png");
    world.runLevel();
    return 0;
}