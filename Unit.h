//
// Created by trykr on 12.10.2020.
//

#ifndef WORMSPROTOTYPE_UNIT_H
#define WORMSPROTOTYPE_UNIT_H
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Unit {
public:
    Unit(sf::Texture *texture, sf::Vector2u imageCount,
         float switchTime, float speed,
         sf::Vector2f size, sf::Vector2f position);
    ~Unit();

    void MakePlayerFly(float deltaTime); //TEMPORARY
    void MakePlayerStanding(float deltaTime);
    void MakePlayerFall(float deltaTime);
    void MakePlayerMoving(float deltaTime, bool isGoingRight);
    void Draw(sf::RenderWindow& window);
    sf::Vector2f getPlayerPostion();
    sf::Vector2f getPlayerBottomCoordinates();
    sf::Vector2f getPlayerRightBottomCoordinates();
    sf::Vector2f getPlayerLeftBottomCoordinates();
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool isFaceRight;
};


#endif //WORMSPROTOTYPE_UNIT_H
