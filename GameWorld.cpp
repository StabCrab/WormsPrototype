//
// Created by trykr on 16.10.2020.
//

#include "GameWorld.h"

GameWorld::GameWorld(sf::RenderWindow& window, std::string level)
{
    this->window = &window;
    terrain.setTexture(level);
    view.setCenter(0,0);
    view.setSize(VIEW_HEIGHT, VIEW_HEIGHT);
    unitTexture.loadFromFile("Textures/tux_from_linux.png");
}

GameWorld::~GameWorld() {

}

void GameWorld::runLevel()
{
    sf::Texture weaponTexture;
    weaponTexture.loadFromFile("RedPoint.png");
    Unit unit(&unitTexture, sf::Vector2f (100, 150), 10.f, sf::Vector2f(0.f,400),
              sf::Vector2u(3,9), 0.25, 75);
    while (window->isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
            if (event.type == sf::Event::Resized)
            {
                view.setSize(VIEW_HEIGHT * (float(window->getSize().x) / float (window->getSize().y)), VIEW_HEIGHT);
            }
            switch (event.key.code)
            {
                case sf::Keyboard::W:
                {

                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (terrain.getPixel(unit.getPlayerBottomCoordinates().x, unit.getPlayerBottomCoordinates().y) == sf::Color::Transparent)
                unit.MakePlayerFall(deltaTime, gravity);
            while (terrain.getPixel(unit.getPlayerBottomCoordinates().x, unit.getPlayerBottomCoordinates().y) != sf::Color::Transparent)
            {
                unit.MakePlayerFly(deltaTime);
            }
            if (checkIfCanMove(unit, terrain, true))
                unit.MakePlayerMoving(deltaTime, true);


        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (terrain.getPixel(unit.getPlayerBottomCoordinates().x, unit.getPlayerBottomCoordinates().y) == sf::Color::Transparent)
                unit.MakePlayerFall(deltaTime, gravity);
            while (terrain.getPixel(unit.getPlayerBottomCoordinates().x, unit.getPlayerBottomCoordinates().y) != sf::Color::Transparent)
            {
                unit.MakePlayerFly(deltaTime);
            }
            if (checkIfCanMove(unit, terrain, false))
                unit.MakePlayerMoving(deltaTime, false);

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            unit.shoot(sf::Vector2f(1,0));
        }
        else
        {
            if (terrain.getPixel(unit.getPlayerBottomCoordinates().x, unit.getPlayerBottomCoordinates().y) == sf::Color::Transparent)
                unit.MakePlayerFall(deltaTime, gravity);
            unit.MakePlayerStanding(deltaTime);
        }
        if (unit.getIsShooting())
        {
            if (terrain.getPixel(unit.getWeaponCoordinates().x, unit.getWeaponCoordinates().y) != sf::Color::Transparent
            || unit.getWeaponCoordinates().x < 0 || unit.getWeaponCoordinates().x > 2000)
            {
                terrain.boom(unit.getWeaponCoordinates(), unit.getWeaponRadius());
                unit.weaponDestroy();
            }
        }
        view.setCenter(unit.getPlayerPostion());
        unit.draw(*window);
        terrain.Draw(*window);
        window->display();
        window->clear(sf::Color(150,150,150));
        window->setView(view);
    }
}

bool GameWorld::checkIfCanMove(Unit unit, Terrain terrain, bool isRight)
{
    if (isRight)
    {
        if (terrain.getPixel(unit.getPlayerRightCoordinates().x, unit.getPlayerRightCoordinates().y) == sf::Color::Transparent)
            return true;
        else
            return false;
    }
    else
    {
        if (terrain.getPixel(unit.getPlayerLeftCoordinates().x, unit.getPlayerLeftCoordinates().y) == sf::Color::Transparent)
            return true;
        else
            return false;
    }
}
