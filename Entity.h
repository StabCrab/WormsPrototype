//
// Created by trykr on 15.10.2020.
//

#ifndef WORMSPROTOTYPE_ENTITY_H
#define WORMSPROTOTYPE_ENTITY_H
#include "SFML/Graphics.hpp"

class Entity
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Image image;
    sf::Vector2f position;
    sf::Vector2f momentum;

    const float gravity = 9.8;
    const float mass;

public:
    Entity(sf::Image& image, float mass, sf::Vector2f position);
    ~Entity();

    virtual bool isCollidesWithTerrain() = 0;

};


#endif //WORMSPROTOTYPE_ENTITY_H
