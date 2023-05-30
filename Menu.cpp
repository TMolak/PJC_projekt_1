//#include <iostream>
//#include "Menu.h"
//
//Menu::Menu(float width, float height) {
//
//    if (!font.loadFromFile("fonts/Starjedi.ttf")) {
//        std::cout << "Nie zaladowano fontu" << std::endl;
//    }
//
//
//    text[1].setFont(font);
//    text[1].setFillColor(sf::Color::Red);
//    text[1].setString("Nowa gra");
//    text[1].setCharacterSize(70);
//    text[1].setPosition(sf::Vector2f(width / 2, height / (MENU_SIZE + 1) * 1));
//
//    text[2].setFont(font);
//    text[2].setFillColor(sf::Color::Red);
//    text[2].setString("Wczytaj grę");
//    text[2].setCharacterSize(70);
//    text[2].setPosition(sf::Vector2f(width / 2, height / (MENU_SIZE + 1) * 2));
//
//    text[3].setFont(font);
//    text[3].setFillColor(sf::Color::Red);
//    text[3].setString("Najlepsze wyniki");
//    text[3].setCharacterSize(70);
//    text[3].setPosition(sf::Vector2f(width / 2, height / (MENU_SIZE + 1) * 3));
//
//    text[4].setFont(font);
//    text[4].setFillColor(sf::Color::Red);
//    text[4].setString("Wyjdz");
//    text[4].setCharacterSize(70);
//    text[4].setPosition(sf::Vector2f(width / 2, height / (MENU_SIZE + 1) * 4));
//}
//
//Menu::~Menu() {}
//
//void Menu::draw(sf::RenderWindow& window) {
//    for (int i = 0; i < MENU_SIZE; ++i) {
//        window.draw(text[i]);
//    }
//}