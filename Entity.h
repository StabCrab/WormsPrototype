//
// Created by trykr on 15.10.2020.
//

#ifndef WORMSPROTOTYPE_ENTITY_H
#define WORMSPROTOTYPE_ENTITY_H
#include "SFML/Graphics.hpp"

class Entity
{
private:
    sf::RectangleShape body;
    const float mass;

public:
    Entity(sf::Texture* texture,sf::Vector2f size ,float mass, sf::Vector2f position);
    ~Entity();
    sf::RectangleShape getBody();
    void move(sf::Vector2f movementVector);
    void setTextureRect(sf::IntRect textureRect);
    float getMass();
    void drawBody(sf::RenderWindow& window);

};


#endif //WORMSPROTOTYPE_ENTITY_H
