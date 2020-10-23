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

void Terrain::boom(sf::Vector2f position, float radius)
{
    int terrainMaxY = sprite.getPosition().y + sprite.getTexture()->getSize().y;
    int terrainMaxX = sprite.getPosition().x + sprite.getTexture()->getSize().x;

    for (float y = position.y - radius; y <= position.y + radius; ++y) {
        if (y < sprite.getPosition().y || y >= terrainMaxY) continue;
        for (float x = position.x - radius; x <= position.x + radius; ++x) {
            if (x < sprite.getPosition().x || x >= terrainMaxX) continue;
            // Determine distance between origin and current checked pixel.
            double distance = std::sqrt(std::pow(x - position.x, 2) + std::pow(y - position.y, 2));

            // If the distance is smaller than the target radius, clear that pixel (we are in the circle).
            if (distance <= radius) {
                image.setPixel(x - sprite.getPosition().x, y - sprite.getPosition().y, {0, 0, 0, 0});
            }
        }
    }

    // The image has been updated, the texture and sprite need to be notified.
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}
