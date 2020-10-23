//
// Created by trykr on 19.10.2020.
//

#ifndef WORMSPROTOTYPE_WEAPON_H
#define WORMSPROTOTYPE_WEAPON_H
#include "Entity.h"

class Weapon : public Entity
{
private:
    int damage;
    float explosionRadius;
public:
    Weapon(sf::Texture *texture, sf::Vector2f size, float mass, sf::Vector2f position, int damage,
           float explosionRadius);
    ~Weapon();
    void launch(sf::Vector2f movementVector);
    float getRadius();
};


#endif //WORMSPROTOTYPE_WEAPON_H
