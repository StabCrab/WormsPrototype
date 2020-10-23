//
// Created by trykr on 12.10.2020.
//

#ifndef WORMSPROTOTYPE_UNIT_H
#define WORMSPROTOTYPE_UNIT_H
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Entity.h"
#include "Weapon.h"
class Unit : public Entity {
public:
    Unit(sf::Texture *texture, sf::Vector2f sizeUnit, float mass, sf::Vector2f position,
         sf::Vector2u imageCount, float switchTime, float speed);
    ~Unit();

    void MakePlayerFly(float deltaTime); //TEMPORARY
    void MakePlayerStanding(float deltaTime);
    void MakePlayerFall(float deltaTime, const float gravity);
    void MakePlayerMoving(float deltaTime, bool isGoingRight);
    bool getIsShooting();
    sf::Vector2f getPlayerPostion();
    sf::Vector2f getPlayerBottomCoordinates();
    sf::Vector2f getPlayerLeftBottomCoordinates();
    sf::Vector2f getPlayerRightBottomCoordinates();
    sf::Vector2f getPlayerRightCoordinates();
    sf::Vector2f getPlayerLeftCoordinates();
    sf::Vector2f getWeaponCoordinates();
    float getWeaponRadius();
    void unitWalk(bool isRight);
    void shoot(sf::Vector2f crosshairDirection);
    void draw(sf::RenderWindow& window);
    void weaponDestroy();
private:
    Animation animation;
    float speed;
    bool isFaceRight;
    bool isShooting = false;
    Weapon* weapon;
};


#endif //WORMSPROTOTYPE_UNIT_H
