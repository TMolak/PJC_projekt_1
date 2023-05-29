#include "Menu.h"

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("./Starjedi.ttf")) {
        //error
    }
    menu[0].setFont(font);
    menu[0].setString("Nowa gra");
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MENU_SIZE+1)*1));

    menu[1].setFont(font);
    menu[1].setString("Wczytaj grę");
    menu[1].setFillColor(sf::Color::Red);
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MENU_SIZE+1)*2));

    menu[2].setFont(font);
    menu[2].setString("Najlepsze wyniki");
    menu[2].setFillColor(sf::Color::Red);
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MENU_SIZE+1)*3));

    menu[3].setFont(font);
    menu[3].setString("Wyjdz");
    menu[3].setFillColor(sf::Color::Red);
    menu[3].setPosition(sf::Vector2f(width / 2, height / (MENU_SIZE+1)*4));
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow& window){
    for (int i = 0; i < MENU_SIZE-1; ++i) {
        window.draw(menu[i]);
    }
}