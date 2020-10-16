//
// Created by trykr on 15.10.2020.
//

#include "Entity.h"

Entity::Entity(sf::Image &image, float mass, sf::Vector2f position)  : mass(mass), momentum(0,0)
{
    this->image = image;
    this->texture.loadFromImage(image);
    this->sprite.setTexture(texture);
    this->position = position;
}

Entity::~Entity()
{

}
