#include "Terrain.h"

Terrain::Terrain()
{

}

Terrain::~Terrain()
{

}

void Terrain::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    sprite.setPosition(0,0);
}

sf::Color Terrain::getPixel(int x, int y)
{
    return image.getPixel(x,y);
}

sf::Vector2f Terrain::getSpritePostition() {
    return sprite.getPosition();
}

void Terrain::setPixel(int x, int y)
{
    //image.setPixel(x, y, sf::Color::Red);
}

void Terrain::setTexture(std::string filename)
{
    image.loadFromFile(filename);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}
