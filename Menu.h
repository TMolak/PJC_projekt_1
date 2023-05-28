#include <SFML/Graphics.hpp>

#ifndef PJC_PROJEKT_1_MENU_H
#define PJC_PROJEKT_1_MENU_H


class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);

private:
    int selected;
    sf::Font font;
    sf::Text text[4];
};


#endif //PJC_PROJEKT_1_MENU_H
