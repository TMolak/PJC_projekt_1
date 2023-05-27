#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

const int rows = 7;
const int columns = 7;
const float posX = 100.f;
const float posY = 100.f;
const float spacingX = 60.f;
const float spacingY = 60.f;
const float radius = 30.0f;

vector<sf::CircleShape> hexagons;


int main() {

    int boardPattern[17][9] = {
            {0, 0, 0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 0, 0, 0},
            {0, 0, 1, 1, 2, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 2, 2, 1, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0}
    };

//tworzenie okna
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Hexxagon",
                            sf::Style::Default,
                            sf::ContextSettings(0, 0, 8));

    window.clear(sf::Color::White);


    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 9; j++) {
            sf::CircleShape hexagon(radius, 6);
            sf::Angle rotation(90);
            hexagon.setOutlineColor(sf::Color::White);
            if (boardPattern[i][j] == 1) {
                hexagon.setFillColor(sf::Color::Magenta);
                hexagon.setOutlineColor(sf::Color::Black);
            } else if (boardPattern[i][j] == 2) {
                hexagon.setFillColor(sf::Color::Blue);
                hexagon.setOutlineColor(sf::Color::Black);
            }
            hexagon.setOutlineThickness(2.f);

            float x = radius * j * 3.4;
            float y = radius * i;
            if (i % 2 != 0 && i != 0) {
                x += radius * 1.7;
            }
            hexagon.setPosition({x, y});
            hexagon.rotate(rotation);
            hexagons.push_back(hexagon);
            window.draw(hexagon);

        }
    }


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (sf::CircleShape &hexagon: hexagons) {
                    if (hexagon.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) &&
                        hexagon.getFillColor() != sf::Color::White && hexagon.getFillColor() != sf::Color::Blue) {
                        hexagon.setFillColor(sf::Color::Green);
                    }
                }
            }
        }
        for (const sf::CircleShape &hexagon: hexagons) {
            window.draw(hexagon);
        }
        window.display();
    }
}
