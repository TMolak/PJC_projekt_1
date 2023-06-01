#include <SFML/Graphics.hpp>
#ifndef PJC_PROJEKT_1_PLAYER_H
#define PJC_PROJEKT_1_PLAYER_H


class Player {
private:
    sf::Color color;
public:
    Player(sf::Color playerColor);
    sf::Color getColor() const;
    bool getIsYellow() const;
};


#endif //PJC_PROJEKT_1_PLAYER_H
