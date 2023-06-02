
#include "Hexagon.h"

Hexagon::Hexagon(float radius, sf::Vector2f position) : shape(radius, 6){
    shape.setOutlineColor(sf::Color::Transparent);
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineThickness(2.f);
    shape.setPosition(position);
    shape.setTexture(nullptr);
}
void Hexagon::setTexture(const sf::Texture& texture) {
    shape.setTexture(&texture);
}

const sf::Texture* Hexagon::getTexture() const {
    return shape.getTexture();
}
void Hexagon::setFillColor(sf::Color color) {
    shape.setFillColor(color);
}

void Hexagon::setOutlineColor(sf::Color color) {
    shape.setOutlineColor(color);
}
sf::Color Hexagon::getOutlineColor() {
    return shape.getOutlineColor();
}

void Hexagon::setOutlineThickness(float thickness) {
    shape.setOutlineThickness(thickness);
}

void Hexagon::setPosition(sf::Vector2f position) {
    shape.setPosition(position);
}
sf::Vector2f Hexagon::getPosition() {
    return shape.getPosition();
}
sf::Color Hexagon::getFillColor() const {
    return shape.getFillColor();
}

void Hexagon::rotate(sf::Angle angle) {
    shape.rotate(angle);
}

bool Hexagon::contains(sf::Vector2f point) const {
    return shape.getGlobalBounds().contains(point);
}

void Hexagon::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}