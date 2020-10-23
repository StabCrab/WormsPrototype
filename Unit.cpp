//
// Created by trykr on 12.10.2020.
//

#include "Unit.h"

Unit::Unit(sf::Texture *texture, sf::Vector2f sizeUnit, float mass, sf::Vector2f position,
           sf::Vector2u imageCount, float switchTime, float speed)
           : Entity(texture, sizeUnit, mass, position),
           animation(texture, imageCount, switchTime),
           speed(speed), isFaceRight(true)
{
}

Unit::~Unit()
{

}

void Unit::MakePlayerStanding(float deltaTime)
{
    animation.Update(0, deltaTime, isFaceRight);
    setTextureRect(animation.uvRect);
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
    setTextureRect(animation.uvRect);
    move(movement);
}

sf::Vector2f Unit::getPlayerPostion() {
    return getBody().getPosition();
}

void Unit::MakePlayerFall(float deltaTime, const float gravity)
{
    sf::Vector2f movement(0,0);
    movement.y += gravity* getMass() * deltaTime;
    move(movement);
}

void Unit::MakePlayerFly(float deltaTime)
{
    sf::Vector2f movement(0,0);
    movement.y -= speed * deltaTime / 4.f;
    move(movement);
}

sf::Vector2f Unit::getPlayerBottomCoordinates()
{
    return sf::Vector2f (getBody().getPosition().x,
                         getBody().getPosition().y + (getBody().getSize().y / 2.f) - 5);
}

void Unit::unitWalk(bool isRight)
{
    isFaceRight = isRight;
    if (isRight)
    {
        getBody().getPoint(0);
    }
}

sf::Vector2f Unit::getPlayerLeftBottomCoordinates()
{
    return sf::Vector2f (getBody().getPosition().x - (getBody().getSize().x / 2.f),
                         getBody().getPosition().y + (getBody().getSize().y / 2.f) - 5);
}

sf::Vector2f Unit::getPlayerRightBottomCoordinates()
{
    return sf::Vector2f (getBody().getPosition().x + (getBody().getSize().x / 2.f),
                         getBody().getPosition().y + (getBody().getSize().y / 2.f) - 5);
}

sf::Vector2f Unit::getPlayerRightCoordinates()
{
    return sf::Vector2f (getBody().getPosition().x + (getBody().getSize().x / 2.f),
                         getBody().getPosition().y);
}

sf::Vector2f Unit::getPlayerLeftCoordinates() {
    return sf::Vector2f (getBody().getPosition().x - (getBody().getSize().x / 2.f),
                         getBody().getPosition().y);
}

void Unit::draw(sf::RenderWindow& window)
{
    drawBody(window);
    if (isShooting)
    {
        weapon->move(sf::Vector2f(10,0));
        weapon->drawBody(window);
    }
}

void Unit::shoot(sf::Vector2f crosshairDirection)
{
    if (isShooting)
        return;
    sf::Texture weaponTexture;
    weaponTexture.loadFromFile("RedPoint.png");
    weapon = new Weapon(&weaponTexture, sf::Vector2f(10,10), 5.f,
                  getBody().getPosition(), 20, 30.f);
    isShooting = true;
}

sf::Vector2f Unit::getWeaponCoordinates()
{
    return weapon->getBody().getPosition();
}

void Unit::weaponDestroy()
{
    isShooting = false;
    delete weapon;
    isShooting = false;
}

bool Unit::getIsShooting()
{
    return isShooting;
}

float Unit::getWeaponRadius()
{
    return weapon->getRadius();
}


