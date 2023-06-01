#include <SFML/Graphics.hpp>
#ifndef PJC_PROJEKT_1_HEXAGON_H
#define PJC_PROJEKT_1_HEXAGON_H


class Hexagon {
public:
    Hexagon(float radius, sf::Vector2f position);
    void setFillColor(sf::Color color);
    sf::Color getFillColor() const;
    sf::Vector2f getPosition();
    sf::Color getOutlineColor();
    void setTexture(const sf::Texture& texture);
    const sf::Texture* getTexture() const;
    void setOutlineColor(sf::Color color);
    void setOutlineThickness(float thickness);
    void setPosition(sf::Vector2f position);
    void rotate(sf::Angle angle);
    bool contains(sf::Vector2f point) const;
    void draw(sf::RenderWindow& window) const;

private:
    sf::CircleShape shape;
};


#endif //PJC_PROJEKT_1_HEXAGON_H
