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
    Unit unit(&unitTexture, sf::Vector2u(3, 9),
              0.2, 100 , sf::Vector2f(100, 150),
              sf::Vector2f(0,0));
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
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            while (terrain.getPixel(unit.getPlayerBottomCoordinates().x, unit.getPlayerBottomCoordinates().y) == sf::Color::Transparent)
                unit.MakePlayerFall(deltaTime);
            unit.MakePlayerMoving(deltaTime, true);
            while (terrain.getPixel(unit.getPlayerBottomCoordinates().x, unit.getPlayerBottomCoordinates().y) != sf::Color::Transparent)
            {
                unit.MakePlayerFly(deltaTime);
            }

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            while (terrain.getPixel(unit.getPlayerBottomCoordinates().x, unit.getPlayerBottomCoordinates().y) == sf::Color::Transparent)
                unit.MakePlayerFall(deltaTime);
            unit.MakePlayerMoving(deltaTime, false);
            while (terrain.getPixel(unit.getPlayerBottomCoordinates().x, unit.getPlayerBottomCoordinates().y) != sf::Color::Transparent)
            {
                unit.MakePlayerFly(deltaTime);
            }
        }
        else
        {
            while (terrain.getPixel(unit.getPlayerBottomCoordinates().x, unit.getPlayerBottomCoordinates().y) == sf::Color::Transparent)
                unit.MakePlayerFall(deltaTime);
            unit.MakePlayerStanding(deltaTime);
        }
        view.setCenter(unit.getPlayerPostion());
        unit.Draw(*window);
        terrain.Draw(*window);
        window->display();
        window->clear(sf::Color(150,150,150));
        window->setView(view);
    }
}
