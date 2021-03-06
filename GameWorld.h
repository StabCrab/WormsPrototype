//
// Created by trykr on 16.10.2020.
//

#ifndef WORMSPROTOTYPE_GAMEWORLD_H
#define WORMSPROTOTYPE_GAMEWORLD_H
#include "Terrain.h"
#include "Unit.h"
static const float VIEW_HEIGHT = 500.f;
class GameWorld
{
private:
    sf::RenderWindow* window;
    Terrain terrain;
    sf::View view;
    sf::Texture unitTexture;
    float deltaTime = 0.f;
    sf::Clock clock;
    const float gravity = 20;
public:
    GameWorld(sf::RenderWindow& window, std::string level);
    ~GameWorld();
    void runLevel();
    bool checkIfCanMove(Unit unit, Terrain terrain, bool isRight);
};


#endif //WORMSPROTOTYPE_GAMEWORLD_H
