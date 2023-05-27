#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

const int rows = 7;
const int columns = 7;
const float posX = 400.f;
const float posY = 400.f;
const float spacingX = 90.f;
const float spacingY = 90.f;
const float radius = 40.f;

vector<sf::CircleShape> hexagons;


int main() {
    int boardPattern[17][33] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,0,0,0,0},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

    };
//tworzenie okna
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Hexxagon",
                            sf::Style::Default,
                            sf::ContextSettings(0, 0, 8));

    window.clear(sf::Color::White);

    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 33; j++) {
            if(boardPattern[i][j] == 1){
                sf::CircleShape hexagon(radius, 6);
                hexagon.setFillColor(sf::Color::Magenta);
                hexagon.setOutlineThickness(2.f);
                hexagon.setOutlineColor(sf::Color::Black);
                float x = posX + (spacingX+radius);
                float y = posY + (spacingY+radius);

                hexagon.setPosition({x, y});
                hexagons.push_back(hexagon);
            }
        }
    }

//    for (int i = rows; i > 0; i--) {
//        for (int j = 0; j < ; ++j) {
//
//        }
//    }

    for (sf::CircleShape hexagon: hexagons) {
        window.draw(hexagon);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (sf::CircleShape &hexagon: hexagons) {
                    if (hexagon.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
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
