//
// Created by trykr on 12.10.2020.
//

#include "Unit.h"

Unit::Unit(sf::Texture *texture, sf::Vector2u imageCount,
           float switchTime, float speed,
           sf::Vector2f size, sf::Vector2f position)
               : animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    isFaceRight = true;
    body.setSize(size);
    body.setOrigin(body.getSize() / 2.f);
    texture->setSmooth(true);
    body.setTexture(texture);
    body.setPosition(position);
}

Unit::~Unit()
{

}

void Unit::MakePlayerStanding(float deltaTime)
{
    animation.Update(0, deltaTime, isFaceRight);
    body.setTextureRect(animation.uvRect);
}

void Unit::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

void Unit::MakePlayerMoving(float deltaTime, bool isGoingRight)
{
    sf::Vector2f movement(0,0);

    if(isGoingRight)
    {
        isFaceRight = true;
        movement.x += speed * deltaTime;
    }
    else
    {
        isFaceRight = false;
        movement.x -= speed * deltaTime;
    }
    animation.Update(1, deltaTime, isFaceRight);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}

sf::Vector2f Unit::getPlayerPostion() {
    return body.getPosition();
}

void Unit::MakePlayerFall(float deltaTime)
{
    sf::Vector2f movement(0,0);
    movement.y += speed * deltaTime / 4.f;
    body.move(movement);
}

void Unit::MakePlayerFly(float deltaTime)
{
    sf::Vector2f movement(0,0);
    movement.y -= speed * deltaTime / 4.f;
    body.move(movement);
}

sf::Vector2f Unit::getPlayerBottomCoordinates()
{
    return sf::Vector2f (body.getPosition().x, body.getPosition().y + (body.getSize().y / 2.f) - 5);
}

sf::Vector2f Unit::getPlayerRightBottomCoordinates() {
    return sf::Vector2f(body.getPosition().x + body.getSize().x / 2.f, body.getPosition().y + (body.getSize().y / 2.f));
}

sf::Vector2f Unit::getPlayerLeftBottomCoordinates() {
    return sf::Vector2f(body.getPosition().x - body.getSize().x / 2.f, body.getPosition().y + (body.getSize().y / 2.f));
}

