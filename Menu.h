#ifndef PJC_PROJEKT_1_MENU_H
#define PJC_PROJEKT_1_MENU_H

#include <SFML/Graphics.hpp>

#define MENU_SIZE 4

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow& window);

private:
    int selected{};
    sf::Font font;
    sf::Text text[MENU_SIZE];
};


#endif //PJC_PROJEKT_1_MENU_H
