#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
using namespace std;

const float radius = 30.0f;



class Board{
public:
    Board(int pattern[17][9]){
        for (int i = 0; i < 17; i++) {
            for (int j = 0; j < 9; j++) {
                sf::CircleShape hexagon(radius, 6);
                sf::Angle rotation(90);
                hexagon.setOutlineColor(sf::Color::Transparent);
                if (pattern[i][j] == 1) {
                    hexagon.setFillColor(sf::Color::Magenta);
                    hexagon.setOutlineColor(sf::Color::Black);
                } else if (pattern[i][j] == 2) {
                    hexagon.setFillColor(sf::Color::Transparent);
                }else if (pattern[i][j] == 3) {
                    hexagon.setFillColor(sf::Color::Yellow);
                    hexagon.setOutlineColor(sf::Color::Black);
                }else if (pattern[i][j] == 4) {
                    hexagon.setFillColor(sf::Color::Red);
                    hexagon.setOutlineColor(sf::Color::Black);
                }else{
                    hexagon.setFillColor(sf::Color::Transparent);
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

            }
        }
    }
    void draw(sf::RenderWindow& window){
        for (const sf::CircleShape &hexagon: hexagons) {
            window.draw(hexagon);
        }
    }

    void mouseClick(const sf::Event& event){
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            for (sf::CircleShape &hexagon: hexagons) {
                if (hexagon.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) &&
                    hexagon.getFillColor() != sf::Color::Transparent && hexagon.getFillColor() != sf::Color::Blue) {
                    hexagon.setOutlineColor(sf::Color::Cyan);
                }
            }
        }
    }
private:
    vector<sf::CircleShape> hexagons;
};


int main() {


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

//tworzenie okna
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Hexxagon",
                            sf::Style::Default,
                            sf::ContextSettings(0, 0, 8));

    window.clear(sf::Color::White);
Menu menu(800, 800);
menu.draw(window);
//Board board(boardPattern);




    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
//                board.mouseClick(event);
            }
        }
//        board.draw(window);
        window.display();
    }
}
