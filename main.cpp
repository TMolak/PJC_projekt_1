#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

//void pattern() {
//    //gorna piramida
//    for (int i = 1; i <= 5; i++) {
//        for (int j = 1; j <= 5 - i; j++) {
//            std::cout << "    ";
//        }
//        for (int j = 1; j <= i; j++) {
//            std::cout << "O       ";
//        }
//        std::cout << std::endl;
//    }
//    //srodek
//    for (int i = 0; i < 4; ++i) {
//        cout<<"    0   ";
//    }
//    cout << endl;
//    //dolna piramida
//    for (int i = 5; i >= 1; i--) {
//        for (int j = 1; j <= 5 - i; j++) {
//            std::cout << "    ";
//        }
//        for (int j = 1; j <= i; j++) {
//            std::cout << "O       ";
//        }
//        std::cout << std::endl;
//    }
//}



int main() {
//tworzenie okna
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test",
                            sf::Style::Default,
                            sf::ContextSettings(0, 0, 8));

    sf::CircleShape hexagon(60, 6);
    hexagon.setFillColor(sf::Color::Magenta);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(hexagon);
        window.display();
    }
}
