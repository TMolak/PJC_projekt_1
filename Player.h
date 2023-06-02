#include <SFML/Graphics.hpp>
#ifndef PJC_PROJEKT_1_PLAYER_H
#define PJC_PROJEKT_1_PLAYER_H


class Player {
private:
    sf::Color color;
public:
    Player(sf::Color playerColor);

    Player();

    sf::Color getColor() const;
    void setColor(sf::Color colorChange);
};


#endif //PJC_PROJEKT_1_PLAYER_H
