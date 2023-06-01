#include "Board.h"
#include "Hexagon.h"
#include <cmath>

const float radius = 30.0f;

Board::Board(int pattern[17][9]) {
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 9; j++) {
            sf::Vector2f position;
            float x = radius * j * 3.4;
            float y = radius * i;
            if (i % 2 != 0 && i != 0) {
                x += radius * 1.7;
            }
            position = {x, y};
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

void Board::draw(sf::RenderWindow &window) {
    for (const Hexagon &hexagon: hexagons) {
        hexagon.draw(window);
    }
}

void Board::setCurrentPlayer(Player player) {
    currentPlayer = player;
}

Player Board::getCurrentPlayer() {
    return currentPlayer;
}

void Board::mouseClick(const sf::Event &event, Player player) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        for (Hexagon &hexagon: hexagons) {
            if (hexagon.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) &&
                hexagon.getFillColor() != sf::Color::Transparent &&
                hexagon.getOutlineColor() != sf::Color::Cyan &&
                hexagon.getFillColor() == player.getColor()) {

                sf::Vector2f clickedPosition = hexagon.getPosition();
                for (Hexagon &neighbourHexagon: hexagons) {
                    if (neighbourHexagon.getFillColor() != sf::Color::Transparent &&
                        std::abs(hexagon.getPosition().x - neighbourHexagon.getPosition().x) <= radius * 2 &&
                        std::abs(hexagon.getPosition().y - neighbourHexagon.getPosition().y) <= radius * 2) {
                        neighbourHexagon.setOutlineColor(sf::Color::Cyan);
                    }
                }
            }
        }

    }
}

void Board::hexagonColorChange(const sf::Event &event, Player player) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        for (Hexagon &hexagon: hexagons) {
            if (hexagon.getOutlineColor() == sf::Color::Cyan &&
                hexagon.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) &&
                hexagon.getFillColor() != player.getColor()) {
                sf::Color changeColor = player.getColor();
                hexagon.setOutlineColor(sf::Color::Black);
                hexagon.setFillColor(changeColor);

            }
        }
    }
}




