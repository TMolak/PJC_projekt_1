
#include "Player.h"

Player::Player(sf::Color playerColor) {
    color = playerColor;
}


sf::Color Player::getColor() const {
    return color;
}
