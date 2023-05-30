#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"


using namespace std;

enum class Player{
    Player_One,
    Player_Two
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

    Board board(boardPattern);

    Player currentPlayer = Player::Player_One;

    Hexagon* selectedHexagon = nullptr;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {

                board.mouseClick(event);
            }
        }
        board.draw(window);
        window.display();
    }
}
