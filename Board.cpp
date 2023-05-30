#include "Board.h"
#include "Hexagon.h"
#include <cmath>
const float radius = 30.0f;
int boardPattern[17][9] = {
        {0, 0, 0, 0, 4, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 3, 1, 1, 1, 3, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 2, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 2, 2, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 4, 1, 1, 1, 4, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 0}
};
Board::Board(int pattern[17][9]) {
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 9; j++) {
            sf::Vector2f position;
            float x = radius * j * 3.4;
            float y = radius * i;
            if (i % 2 != 0 && i != 0) {
                x += radius * 1.7;
            }
            position = { x, y };
            Hexagon hexagon(radius, position);

            sf::Angle rotation(90);
            if (pattern[i][j] == 1) {
                hexagon.setFillColor(sf::Color::Magenta);
                hexagon.setOutlineColor(sf::Color::Black);
            } else if (pattern[i][j] == 2) {
                hexagon.setFillColor(sf::Color::Transparent);
            } else if (pattern[i][j] == 3) {
                hexagon.setFillColor(sf::Color::Yellow);
                hexagon.setOutlineColor(sf::Color::Black);
            } else if (pattern[i][j] == 4) {
                hexagon.setFillColor(sf::Color::Red);
                hexagon.setOutlineColor(sf::Color::Black);
            } else {
                hexagon.setFillColor(sf::Color::Transparent);
            }
            hexagon.setOutlineThickness(2.f);



            hexagon.rotate(rotation);
            hexagons.push_back(hexagon);
        }
    }
}

void Board::draw(sf::RenderWindow& window) {
    for (const Hexagon& hexagon : hexagons) {
        hexagon.draw(window);
    }
}


void Board::mouseClick(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        for (Hexagon& hexagon : hexagons) {
            if (hexagon.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) &&
                hexagon.getFillColor() != sf::Color::Transparent && hexagon.getFillColor() != sf::Color::Blue) {
                hexagon.setOutlineColor(sf::Color::Cyan);

            }
        }
    }
}




