#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
//tworzenie okna
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test",
                            sf::Style::Default,
                            sf::ContextSettings(0, 0, 8));
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
}
