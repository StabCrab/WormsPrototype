//
// Created by trykr on 11.10.2020.
//

#ifndef WORMSPROTOTYPE_ANIMATION_H
#define WORMSPROTOTYPE_ANIMATION_H
#include "SFML/Graphics.hpp"
class Animation
{
public:
    sf::IntRect uvRect;

    void Update(unsigned int row, float deltaTime, bool faceRight);

    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();
private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    float totalTime;
    float switchTime;
};


#endif //WORMSPROTOTYPE_ANIMATION_H
