//
// Created by trykr on 19.10.2020.
//

#include "Weapon.h"

Weapon::Weapon(sf::Texture *texture, sf::Vector2f size, float mass, sf::Vector2f position, int damage,
               float explosionRadius) : Entity(texture, size, mass, position)
{
    this->damage = damage;
    this->explosionRadius = explosionRadius;
}

Weapon::~Weapon()
{

}

void Weapon::launch(sf::Vector2f movementVector)
{
    move(movementVector);
}

float Weapon::getRadius() {
    return explosionRadius;
}
