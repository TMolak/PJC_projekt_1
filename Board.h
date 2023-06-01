#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "Hexagon.h"
#include "Player.h"

class Board {
public:
    Board(int pattern[17][9]);

    void draw(sf::RenderWindow& window);
    void mouseClick(const sf::Event& event, Player& player);
    void hexagonColorChange(const sf::Event &event, Player& player);
    void setCurrentPlayer(Player player);
    Player getCurrentPlayer();
private:
    std::vector<Hexagon> hexagons;
    Player currentPlayer = Player(sf::Color());
};

#endif // BOARD_H
