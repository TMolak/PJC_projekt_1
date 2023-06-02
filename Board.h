#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "Hexagon.h"
#include "Player.h"

class Board {
public:
    Board(int pattern[17][9]);

    void draw(sf::RenderWindow& window);
    void closeHexagons(sf::Event& event);
    void hexagonColorChange(sf::Event& event, Player& player);
    void setCurrentPlayer(Player player);
    Player getCurrentPlayer();
    std::vector<Hexagon>& getHexagons();
    void colorAttack(sf::Event &event);
    int playerOnePoints();
    int playerTwoPoints();

private:
    std::vector<Hexagon> hexagons;
    Player currentPlayer;
};

#endif // BOARD_H
