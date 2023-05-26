#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


int main() {
//tworzenie okna
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "Hexxagon",
                            sf::Style::Default,
                            sf::ContextSettings(0, 0, 8));

    window.clear(sf::Color::White);

        const int rows = 7;
        const int columns = 7;
        const float posX = 100.f;
        const float posY = 100.f;
        const float spacingX = 90.f;
        const float spacingY = 90.f;
        const float radius = 40.f;

        vector<sf::CircleShape> hexagons;

        window.clear(sf::Color::White);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns - i; j++)
            {
                sf::CircleShape hexagon(radius, 6);
                hexagon.setFillColor(sf::Color::Magenta);
                hexagon.setOutlineThickness(2.f);
                hexagon.setOutlineColor(sf::Color::Black);
                float x = posX + (spacingX * j) + (i * (spacingX / 2.f));
                float y = posY + (spacingY * i);

                hexagon.setPosition({x, y});
                hexagons.push_back(hexagon);
                window.draw(hexagon);
            }
        }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (sf::CircleShape& hexagon : hexagons) {
                    if (hexagon.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        hexagon.setFillColor(sf::Color::Green);
                    }
                }
           }
        }
        for (const sf::CircleShape& hexagon : hexagons) {
            window.draw(hexagon);
        }
        window.display();
    }
}
