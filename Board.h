#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "Hexagon.h"

class Board {
public:
    Board(int pattern[17][9]);

    void draw(sf::RenderWindow& window);
    void mouseClick(const sf::Event& event);


private:
    std::vector<Hexagon> hexagons;
};

#endif // BOARD_H
