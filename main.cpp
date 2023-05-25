#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


int main() {
//tworzenie okna
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "Hexxagon",
                            sf::Style::Default,
                            sf::ContextSettings(0, 0, 8));

    window.clear(sf::Color::White);
    const float radius = 40.f;
    sf::CircleShape hexagon(radius, 6);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
//            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//                hexagon.setFillColor(sf::Color::Green);
//            }
        }

        const int rows = 7;
        const int columns = 7;
        const float posX = 100.f;
        const float posY = 100.f;
        const float spacingX = 90.f;
        const float spacingY = 90.f;

        window.clear(sf::Color::White);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns - i; j++)
            {
                hexagon.setFillColor(sf::Color::Magenta);
                hexagon.setOutlineThickness(2.f);
                hexagon.setOutlineColor(sf::Color::Black);

                float x = posX + (spacingX * j) + (i * (spacingX / 2.f));
                float y = posY + (spacingY * i);

                hexagon.setPosition({x, y});
                window.draw(hexagon);
            }
        }

        window.display();
    }
}
