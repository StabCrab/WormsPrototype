//
// Created by trykr on 15.10.2020.
//

#include "Entity.h"

Entity::Entity(sf::Texture* texture,sf::Vector2f size ,float mass, sf::Vector2f position)
: mass(mass)
{
    body.setSize(size);
    body.setOrigin(body.getSize() / 2.f);
    texture->setSmooth(true);
    body.setTexture(texture);
    body.setPosition(position);
}

Entity::~Entity()
{

}

sf::RectangleShape Entity::getBody() {
    return body;
}

void Entity::move(sf::Vector2f movementVector)
{
    body.move(movementVector);
}

void Entity::setTextureRect(sf::IntRect textureRect)
{
    body.setTextureRect(textureRect);
}

float Entity::getMass() {
    return mass;
}

void Entity::drawBody(sf::RenderWindow& window)
{
    window.draw(body);
}
