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
            sf::Texture textureFalcon;
            sf::Texture textureTie;
            sf::Texture textureLogo;

            Hexagon hexagon(radius, position);

            sf::Angle rotation(90);
            if (pattern[i][j] == 1) {
                if (textureLogo.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\pictures\\logo.jpg")) {
                    hexagon.setTexture(textureLogo);
                    hexagon.setFillColor(sf::Color::Magenta);
                    hexagon.setOutlineColor(sf::Color::Black);
                }
            } else if (pattern[i][j] == 2) {
                hexagon.setFillColor(sf::Color::Transparent);
            } else if (pattern[i][j] == 3) {
                if (textureFalcon.loadFromFile(
                        "C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\pictures\\falcon.jpg")) {
                    hexagon.setTexture(textureFalcon);
                    hexagon.setFillColor(sf::Color::Yellow);
                    hexagon.setOutlineColor(sf::Color::Black);
                }

            } else if (pattern[i][j] == 4) {
                if (textureTie.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\pictures\\tie.jpg")) {
                    hexagon.setTexture(textureTie);
                    hexagon.setFillColor(sf::Color::Red);
                    hexagon.setOutlineColor(sf::Color::Black);
                }
            } else if (pattern[i][j] == 5) {
                hexagon.setOutlineColor(sf::Color::Cyan);
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

std::vector<Hexagon> &Board::getHexagons() {
    return hexagons;
}

void Board::setCurrentPlayer(Player player) {
    currentPlayer = player;
}

Player Board::getCurrentPlayer() {
    return currentPlayer;
}

void Board::closeHexagons(sf::Event &event) {

    for (Hexagon &hexagon: hexagons) {
        if (hexagon.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) &&
            hexagon.getFillColor() != sf::Color::Transparent &&
            hexagon.getOutlineColor() != sf::Color::Cyan &&
            hexagon.getFillColor() == currentPlayer.getColor()) {

            sf::Vector2f clickedPosition = hexagon.getPosition();

            for (Hexagon &neighbourHexagon: hexagons) {
                if (neighbourHexagon.getFillColor() != sf::Color::Transparent &&
                    std::abs(hexagon.getPosition().x - neighbourHexagon.getPosition().x) <= radius * 2 &&
                    std::abs(hexagon.getPosition().y - neighbourHexagon.getPosition().y) <= radius * 2) {
                    neighbourHexagon.setOutlineColor(sf::Color::Cyan);

                }else{
                    hexagonColorChange(event);
                }

            }
        }
    }

}

void Board::hexagonColorChange(sf::Event &event) {
    for (Hexagon &hexagon: hexagons) {
        if (hexagon.getOutlineColor() == sf::Color::Cyan &&
            hexagon.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) &&
            hexagon.getFillColor() != currentPlayer.getColor()) {
            sf::Color changeColor = currentPlayer.getColor();
            hexagon.setOutlineColor(sf::Color::Black);
            hexagon.setFillColor(changeColor);
        }
    }
}




