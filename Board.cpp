#include "Board.h"
#include "Hexagon.h"
#include <cmath>

const float radius = 30.0f;

/**
 * Konstruktor klasy Board
 * @param pattern tablica na podstawie ktorej tworzona jest plansza obiektow hexagon
 */
Board::Board(int pattern[17][9]) {
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 9; j++) {
            /**
             * Ustawienie wspolrzednych dla kazdego szesciokata (ustawienie tych wartosci na podstawie prob i bledow)
             */
            sf::Vector2f position;
            float x = radius * j * 3.4;
            float y = radius * i;
            if (i % 2 != 0 && i != 0) {
                x += radius * 1.7;
            }
            position = {x, y};
//            sf::Texture textureFalcon;
//            sf::Texture textureTie;
//            sf::Texture textureLogo;
/**
 * Stworzenie obiektu szesciokata z promieniem zainicjowanym jako stala w klasie i pozycja wyliczona wyzej
 */
            Hexagon hexagon(radius, position);
/**
 * Rotacja o 90 stopni
 */
            sf::Angle rotation(90);
            /**
             * Na postawie tablicy ustawiany jest kolor kazdego z hexagonow
             * 1 - pole neutralne o kolorze magenta
             * 2 - pola przezroczyste sluzace temu zeby szesciokaty mi sie nie rozjechaly
             * 3 - pola zolte nalezace do gracza z kolorem zoltym
             * 4 - pola czerwone nalezace do gracza z kolorem czerwonym
             * Dodalem opcje pobrania grafik dla kazdego pola zamiast kolor ale nie zdazylem ich poprawnie zaimplementowac
             */
            if (pattern[i][j] == 1) {
//                if (textureLogo.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\pictures\\logo.jpg")) {
//                    hexagon.setTexture(textureLogo);
                hexagon.setFillColor(sf::Color::Magenta);
                hexagon.setOutlineColor(sf::Color::Black);
//                }
            } else if (pattern[i][j] == 2) {
                hexagon.setFillColor(sf::Color::Transparent);
            } else if (pattern[i][j] == 3) {
//                if (textureFalcon.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\pictures\\falcon.jpg")) {
//                    hexagon.setTexture(textureFalcon);
                hexagon.setFillColor(sf::Color::Yellow);
                hexagon.setOutlineColor(sf::Color::Black);
//                }

            } else if (pattern[i][j] == 4) {
//                if (textureTie.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\pictures\\tie.jpg")) {
//                    hexagon.setTexture(textureTie);
                hexagon.setFillColor(sf::Color::Red);
                hexagon.setOutlineColor(sf::Color::Black);
//                }
            } else {
                hexagon.setFillColor(sf::Color::Transparent);
            }
            hexagon.setOutlineThickness(2.f);
/**
 * Zrotowanie kazdego szesciokata o 90 stopni i dodanie go do vectora szesciokatow
 */

            hexagon.rotate(rotation);
            hexagons.push_back(hexagon);
        }
    }
}

/**
 * Metoda rysujaca okno z plansza
 * @param window okno
 */
void Board::draw(sf::RenderWindow &window) {
    for (const Hexagon &hexagon: hexagons) {
        hexagon.draw(window);
    }
}

/**
 * Metoda zwracajaca vector z szesciokatami
 * @return zwraca szesciokaty
 */
std::vector<Hexagon> &Board::getHexagons() {
    return hexagons;
}

/**
 * Metoda ustawiajaca aktualnego gracza
 * @param player przekazanie akutalnego gracza
 */
void Board::setCurrentPlayer(Player player) {
    currentPlayer = player;
}

/**
 * Metoda zwracajaca aktualnego gracza
 * @return zwraca aktualnego gracza
 */
Player Board::getCurrentPlayer() {
    return currentPlayer;
}

/**
 * Metoda odpowiadajaca za podswietlenie (w moim wypadku zmiane koloru na cyan) najblizszych szesciokatow dla szesciokatu zaznaczonego przez gracza
 * @param event pobiera event
 */
void Board::closeHexagons(sf::Event &event) {
/**
 * Iteracja po vectorze z szesciokatami
 */
    for (Hexagon &hexagon: hexagons) {
        /**
         * Warunek na podstawie ktorego pobierana jest pozycja kliknietego szesciokata
         */
        if (hexagon.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) &&
            hexagon.getFillColor() != sf::Color::Transparent &&
            hexagon.getOutlineColor() != sf::Color::Cyan &&
            hexagon.getFillColor() == currentPlayer.getColor()) {

            sf::Vector2f clickedPosition = hexagon.getPosition();
            /**
             * Iteracja po szesciokatach w poszukiwaniu szesciokatow ktore sa najblizej wybranego przez nas szesciokata
             * Warunek sprawdza czy szesciokat nie jest przezroczysty oraz czy jest w okolicy dwoch promieni
             * Szesciokat spelniajacy warunki ma zmieniane obramowanie na cyan
             */
            for (Hexagon &neighbourHexagon: hexagons) {
                if (neighbourHexagon.getFillColor() != sf::Color::Transparent &&
                    std::abs(hexagon.getPosition().x - neighbourHexagon.getPosition().x) <= radius * 2 &&
                    std::abs(hexagon.getPosition().y - neighbourHexagon.getPosition().y) <= radius * 2) {

                    neighbourHexagon.setOutlineColor(sf::Color::Cyan);
                }
            }

        }
    }

}
/**
 * Metoda zmieniajaca kolor wypelniajacy szesciokat wybrany przez gracza
 * oraz zmienia kolor akutalnego gracza na przeciwny
 * @param event pobiera event
 * @param player pobiera gracza
 */
void Board::hexagonColorChange(sf::Event &event, Player &player) {
    /**
     * Pobieranie koloru aktualnego gracza
     * ustawianie koloru ktory zostanie zmieniony graczowi po przejsciu calej metody
     */
    sf::Color currentPlayerColor = player.getColor();
    sf::Color nextPlayerColor;
    if (currentPlayerColor == sf::Color::Yellow) {
        nextPlayerColor = sf::Color::Red;

    } else {
        nextPlayerColor = sf::Color::Yellow;
    }
    /**
     * Iteracja po szescioaktach
     * Sprawdzanie warunku dla szesciokata, musi on byc w obszarze kliknietym przez gracza,
     * nie moze miec wszystkich kolorow obramowan ktore sa dostepne w bilbiotece
     * (spowodowane jest to tym ze w przypadku ustawienie warunku hexagon.getOutlineColor() == sf::Color::Cyan
     * program nie dzialal poprawnie),
     * musi byc inny niz kolor aktualnego gracza i nie moze byc transpareny
     *
     */
    for (Hexagon &hexagon: hexagons) {
        if (hexagon.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) &&
            hexagon.getFillColor() != sf::Color::Transparent &&
            hexagon.getOutlineColor() != sf::Color::Red &&
            hexagon.getOutlineColor() != sf::Color::White &&
            hexagon.getOutlineColor() != sf::Color::Green &&
            hexagon.getOutlineColor() != sf::Color::Blue &&
            hexagon.getOutlineColor() != sf::Color::Yellow &&
            hexagon.getOutlineColor() != sf::Color::Magenta &&
            hexagon.getOutlineColor() != sf::Color::Transparent &&
            hexagon.getOutlineColor() != sf::Color::Black &&
            hexagon.getFillColor() != currentPlayer.getColor()) {

            sf::Color changeColor = currentPlayer.getColor();
            /**
             * Wypenienie wybranego szesciokata (ktory spelnia warunki) kolorem gracza
             */
            hexagon.setFillColor(changeColor);
            /**
             * Zmiana koloru gracza
             */
            player.setColor(nextPlayerColor);

            sf::Vector2f clickedPosition = hexagon.getPosition();
    /**
     * Przywrocenie wszystkim szesciokatom czarnej ramki
     */
            for (Hexagon &neighbourHexagon: hexagons) {
                if (neighbourHexagon.getFillColor() != sf::Color::Transparent) {
                    neighbourHexagon.setOutlineColor(sf::Color::Black);
                }
            }
            hexagon.setOutlineColor(sf::Color::Black);
        }
    }
}
/**
 * Metoda odpowiadajaca za przejmowanie kolorow przeciwnika
 * @param event pobiera event
 */
void Board::colorAttack(sf::Event &event) {
    for (Hexagon &hexagon: hexagons) {
        for (Hexagon &neighbourHexagon: hexagons) {
            /**
             * Jezeli szesciokaty w najbliszej okolicy sa koloru przecinwika zostaja zastapione kolorem gracza
             */
            if (hexagon.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) &&
                neighbourHexagon.getFillColor() != sf::Color::Transparent &&
                neighbourHexagon.getFillColor() != sf::Color::Magenta &&
                neighbourHexagon.getFillColor() != currentPlayer.getColor() &&
                std::abs(hexagon.getPosition().x - neighbourHexagon.getPosition().x) <= radius * 2 &&
                std::abs(hexagon.getPosition().y - neighbourHexagon.getPosition().y) <= radius * 2) {

                sf::Vector2f clickedPosition = hexagon.getPosition();
                sf::Color changeColor = currentPlayer.getColor();
                neighbourHexagon.setFillColor(changeColor);
            }
        }
    }
}
/**
 * Metody te zwracaja aktualna liczbe szesciokatow kazdego gracza
 * robia to liczac przez wszystkie szesciokaty ile jest szesciokatow konkretnego koloru
 * @return zwracaja int z iloscia szesciokatow odpowiedniego koloru
 */
int Board::playerOnePoints() {
    int result = 0;
    for (Hexagon &hexagon: hexagons) {
        if (hexagon.getFillColor() == sf::Color::Yellow) {
            result++;
        }
    }
    return result;
}

int Board::playerTwoPoints() {
    int result = 0;
    for (Hexagon &hexagon: hexagons) {
        if (hexagon.getFillColor() == sf::Color::Red) {
            result++;
        }
    }
    return result;
}

