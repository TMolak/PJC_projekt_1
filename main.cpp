#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "Board.h"
#include "Player.h"

using namespace std;
/**
 * Stałe użyte w programie
 */
const float radius = 30.0f;
const int fontSize = 35;
const int x = 1920;
const int y = 1080;
int gameCont = 0;
/**
 * Tablica dwuwymiarowa reprezentujaca plansze
 */
int boardPattern[17][9] = {
        {0, 0, 0, 0, 4, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 3, 1, 1, 1, 3, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 2, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 2, 2, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 4, 1, 1, 1, 4, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 0}
};
/**
 * Enum class reprezentujace opcje do wyboru w Menu Glownym
 */
enum class MenuOption {
    NewGame,
    LoadGame,
    HighScores,
    Exit
};
/**
 * Enum class reprezentujace opcje do wyboru w Menu wyobru trybu gry PvP oznacza gre z drugim graczem
 * PvC przeciwko komputerowi
 */
enum class GameMode {
    PvP,
    PvC
};

/**
 * Funkcja wyswietlajaca Menu z mozliwym wyorem Nowej gry, zaladowania poprzedniej, najwyzszego wyniku i wyjscia z programu
 * @param window referencja do okna w bilbiotece SFML
 * @param font regerencja do fontu
 * @return zwraca wybrana opcje w Menu
 */
MenuOption showMenuWindow(sf::RenderWindow &window, sf::Font &font) {

/**
 * Ustawienie wartosci tekstowej dla kazdego trybu gry
 */
    sf::Text newGameText(font);
    newGameText.setString("Nowa gra");
    newGameText.setCharacterSize(fontSize);
    newGameText.setFillColor(sf::Color::White);
    newGameText.setPosition({100, (y / 2 - 100)});

    sf::Text loadGameText(font);
    loadGameText.setString("Wczytaj gre");
    loadGameText.setCharacterSize(fontSize);
    loadGameText.setFillColor(sf::Color::White);
    loadGameText.setPosition({100, (y / 2 - 100) + 50});

    sf::Text highScoresText(font);
    highScoresText.setString("Najlepsze wyniki");
    highScoresText.setCharacterSize(fontSize);
    highScoresText.setFillColor(sf::Color::White);
    highScoresText.setPosition({100, (y / 2 - 100) + 100});

    sf::Text exitText(font);
    exitText.setString("Wyjscie");
    exitText.setCharacterSize(fontSize);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition({100, (y / 2 - 100) + 150});

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            /**
             * Obsluga zamkniecia okna aplikacji
             */
            if (event.type == sf::Event::Closed) {
                window.close();
                return MenuOption::Exit;
            }
            /**
             * Obsluga klikniecia mysza na opcje w Menu
             */
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);
                if (newGameText.getGlobalBounds().contains(mousePosition)) {
                    return MenuOption::NewGame;
                }
                if (loadGameText.getGlobalBounds().contains(mousePosition)) {
                    return MenuOption::LoadGame;
                }
                if (highScoresText.getGlobalBounds().contains(mousePosition)) {
                    return MenuOption::HighScores;
                }
                if (exitText.getGlobalBounds().contains(mousePosition)) {
                    return MenuOption::Exit;
                }
            }
        }
        /**
        * Ustawienie tla aplikacji
        */
        window.clear(sf::Color::White);
        sf::Texture background;
        if (!background.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\pictures\\background.jpg")) {
            std::cout << "Błąd ładowania tekstury tła" << std::endl;
        }
        sf::Sprite backgroundSprite(background);
        /**
         * Narysowanie wszystkich elementow w oknie
         */
        window.draw(backgroundSprite);
        window.draw(newGameText);
        window.draw(loadGameText);
        window.draw(highScoresText);
        window.draw(exitText);
        window.display();
    }

    return MenuOption::Exit;
}

/**
 *
 * Funkcja wyswietlajaca wybor trybu gry z mozliwym wyborem gry na drugiego gracza lub na komputer
 * @param window referencja do okna w bilbiotece SFML
 * @param font regerencja do fontu
 * @return zwraca wybrana opcje
 */
GameMode showGameModeMenu(sf::RenderWindow &window, sf::Font &font) {
    sf::Text PvP(font);
    PvP.setString("Gra na innego gracza");
    PvP.setCharacterSize(fontSize);
    PvP.setFillColor(sf::Color::White);
    PvP.setPosition({100, (y / 2 - 100)});

    sf::Text PvC(font);
    PvC.setString("Gra z komputerem");
    PvC.setCharacterSize(fontSize);
    PvC.setFillColor(sf::Color::White);
    PvC.setPosition({100, (y / 2 - 100) + 50});

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return GameMode::PvP;
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);
                if (PvP.getGlobalBounds().contains(mousePosition)) {
                    return GameMode::PvP;
                }
                if (PvC.getGlobalBounds().contains(mousePosition)) {
                    return GameMode::PvC;
                }
            }
        }

        window.clear(sf::Color::White);
        sf::Texture background;
        if (!background.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\pictures\\background.jpg")) {
            std::cout << "Błąd ładowania tekstury tła" << std::endl;
        }
        sf::Sprite backgroundSprite(background);
        window.draw(backgroundSprite);
        window.draw(PvP);
        window.draw(PvC);
        window.display();
    }

    return GameMode::PvP;
}

int main() {


    sf::RenderWindow window(sf::VideoMode({x, y}), "Hexxagon",
                            sf::Style::Default,
                            sf::ContextSettings(0, 0, 8));
/**
 * Tworzenie obiektu Texture do ustawienia obrazka w tle aplikacji
 */
    sf::Texture background;
    /**
     * Sprawdzenie czy obrazek się zaladowal
     */
    if (!background.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\pictures\\background.jpg")) {
        std::cout << "Błąd ładowania tekstury tła" << std::endl;
    }
    sf::Sprite backgroundSprite(background);
    window.draw(backgroundSprite);
    window.clear(sf::Color::White);

    /**
     * Ustawienei fontu dla aplikacji
     */
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\fonts\\Starjedi.ttf")) {
        std::cout << "Blad ladowania czcionki" << std::endl;
    }

    /**
     * Stworzenie obiektow graczy, ustawienie im kolorow
     */
    Player playerOne(sf::Color::Yellow);
    Player playerTwo(sf::Color::Red);
    /**
     * Zainicjowanie zmiennych odpowiadajacych za pukntacje kazdego gracza
     */
    int playerOneScoreValue = 0;
    int playerTwoScoreValue = 0;
/**
 * Stworzenie obiektow Text wyswietlajacych punkty graczy
 */
    sf::Text playerOneScore(font);
    playerOneScore.setString("Hexagony gracza 1 :" + std::to_string(playerOneScoreValue));
    playerOneScore.setCharacterSize(fontSize);
    playerOneScore.setFillColor(sf::Color::White);
    playerOneScore.setPosition({100, 800});

    sf::Text playerTwoScore(font);
    playerTwoScore.setString("Hexagony gracza 2 :" + std::to_string(playerTwoScoreValue));
    playerTwoScore.setCharacterSize(fontSize);
    playerTwoScore.setFillColor(sf::Color::White);
    playerTwoScore.setPosition({100, 840});


    while (window.isOpen()) {
        /**
         * Wywolanie Okna Menu w oknie aplikacji
         */
        MenuOption option = showMenuWindow(window, font);
        /**
         * Funkcja warunkowa dla Menu
         * Opcja exit poowoduje wyjscie z programu
         * Opcja New Game wlacza wywoluje Menu wyboru trybu gry
         * Opcja LoadGame nie zostala zainicjalizowana (ale wywolywala by okno z mozliwoscia wczytania poprzedniej gry)
         * Opcja HighScores zczytuje wartosci z pliku scores i wyswietla na ekranie
         */
        if (option == MenuOption::Exit) {
            window.close();
        } else if (option == MenuOption::NewGame) {
            /**
             * Wywolanie Okna z Menu wyboru trybu gry
             */
            GameMode gameMode = showGameModeMenu(window, font);
            /**
             * Funkcja warunkowa sprawdzajaca wybor trybu
             * Opcja PvP przenosi nas do okna z rozgrywka przeciwko drugiemu graczowi
             * Opcja PvC nie zostala zainicjalizowana (ale wywolywala by okno z rozgrywka przeciwko komputerowi)
             */
            if (gameMode == GameMode::PvP) {
                /**
                 * Stworzenie okna dla rozgrywki
                 */
                sf::RenderWindow gameWindow(sf::VideoMode({1920, 1080}), "Hexxagon",
                                            sf::Style::Default,
                                            sf::ContextSettings(0, 0, 8));
                /**
                 * Stworzenie obiektu planszy z przekazaniem wczesniej zainicjowanej tablicy
                 */
                Board board(boardPattern);


                while (gameWindow.isOpen()) {
                    sf::Event event;
                    while (gameWindow.pollEvent(event)) {

                        if (event.type == sf::Event::Closed) {
                            gameWindow.close();
                            /**
                             * Warunek dla wcisniecia lewego przycisku myszy
                             */
                        } else if (event.type == sf::Event::MouseButtonPressed) {
                            if (event.mouseButton.button == sf::Mouse::Left) {
                                /**
                                 * Wywolanie metod odpowiadajacych za rozgrwke
                                 * Przypisanie aktualnego gracza
                                 * Wyznaczenie najblizszych szesciokatow
                                 * Zmiana szesciokatow przeciwnika gdy sa w poblizu
                                 * Zmiana szesciokatow po klinieciu na jeden z aktualnie podswietlonych
                                 */
                                board.setCurrentPlayer(playerOne);
                                board.closeHexagons(event);
                                board.colorAttack(event);
                                board.hexagonColorChange(event, playerOne);
                            }
                        }
                    }
/**
 * Wywoalnie metod zliczajacych ilosc szesciokatow kazdego gracza i dodanie ich do textu do wyswietlenia
 */
                    playerOneScoreValue = board.playerOnePoints();
                    playerTwoScoreValue = board.playerTwoPoints();
                    playerOneScore.setString("Hexagony gracza 1 : " + std::to_string(playerOneScoreValue));
                    playerTwoScore.setString("Hexagony gracza 2 : " + std::to_string(playerTwoScoreValue));

                    /**
                     * Obsluga wygranej w przypadku gdy jeden z graczy osiagnie maksymalna liczbe szesciokatow na planszy
                     */
                    if (board.playerOnePoints() >= 58 || board.playerTwoPoints() >= 58) {
                        gameWindow.close();
                        std::string winner;
                        if (board.playerOnePoints() >= 58) {
                            winner = "Gracz 1";
                        } else {
                            winner = "Gracz 2";
                        }
                        gameCont++;
                        /**
                         * Zainicjowanie okna informujacego o koncu gry i wygranej jednego z graczy
                         */
                        sf::RenderWindow endGameWindow(sf::VideoMode({400, 200}), "Koniec gry");
                        sf::Text endGameText(font);
                        endGameText.setString("Koniec gry, wygral/a \n" + winner);
                        endGameText.setCharacterSize(24);
                        endGameText.setFillColor(sf::Color::Red);
                        endGameText.setPosition({50, 50});
                        /**
                         * Zapisywanie informacji o wygranej do pliku
                         */
                        std::fstream fileOut;
                        fileOut.open("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\files\\scores.txt",
                                     std::ios::app);
                        if (fileOut.is_open()) {
                            fileOut << "Gre  " << gameCont << " wygral/a " << winner << endl;
                            fileOut.close();
                        }
                        while (endGameWindow.isOpen()) {
                            sf::Event event;
                            while (endGameWindow.pollEvent(event)) {
                                if (event.type == sf::Event::Closed) {
                                    endGameWindow.close();
                                }
                            }

                            endGameWindow.clear(sf::Color::Black);
                            endGameWindow.draw(endGameText);
                            endGameWindow.display();
                        }
                        break;
                    }
/**
 * Dodanie elementow do okna, ustawienie tla, wyswietlenie i odswiezenie informacji
 */
                    gameWindow.clear(sf::Color::White);
                    sf::Sprite backgroundSprite(background);
                    gameWindow.draw(backgroundSprite);
                    board.draw(gameWindow);
                    gameWindow.draw(playerOneScore);
                    gameWindow.draw(playerTwoScore);
                    gameWindow.display();
                }
            } else if (gameMode == GameMode::PvC) {
                /**
                 * Stworzenie okna dla rozgrywki
                 */
                sf::RenderWindow pvcWindow(sf::VideoMode({1920, 1080}), "Hexxagon",
                                            sf::Style::Default,
                                            sf::ContextSettings(0, 0, 8));
                /**
                 * Stworzenie obiektu planszy z przekazaniem wczesniej zainicjowanej tablicy
                 */
                Board board(boardPattern);


                while (pvcWindow.isOpen()) {
                    sf::Event event;
                    while (pvcWindow.pollEvent(event)) {

                        if (event.type == sf::Event::Closed) {
                            pvcWindow.close();
                            /**
                             * Warunek dla wcisniecia lewego przycisku myszy
                             */
                        } else if (event.type == sf::Event::MouseButtonPressed) {
                            if (event.mouseButton.button == sf::Mouse::Left) {
                                /**
                                 * Wywolanie metod odpowiadajacych za rozgrwke
                                 * Przypisanie aktualnego gracza
                                 * Wyznaczenie najblizszych szesciokatow
                                 * Zmiana szesciokatow przeciwnika gdy sa w poblizu
                                 * Zmiana szesciokatow po klinieciu na jeden z aktualnie podswietlonych
                                 */
                                board.setCurrentPlayer(playerOne);
                                board.closeHexagons(event);
                                board.colorAttack(event);
                                board.hexagonColorChange(event, playerOne);
                            }
                        }
                    }
/**
 * Wywoalnie metod zliczajacych ilosc szesciokatow kazdego gracza i dodanie ich do textu do wyswietlenia
 */
                    playerOneScoreValue = board.playerOnePoints();
                    playerTwoScoreValue = board.playerTwoPoints();
                    playerOneScore.setString("Hexagony gracza 1 : " + std::to_string(playerOneScoreValue));
                    playerTwoScore.setString("Hexagony Komputera : " + std::to_string(playerTwoScoreValue));

                    /**
                     * Obsluga wygranej w przypadku gdy jeden z graczy osiagnie maksymalna liczbe szesciokatow na planszy
                     */
                    if (board.playerOnePoints() >= 58 || board.playerTwoPoints() >= 58) {
                        pvcWindow.close();
                        std::string winner;
                        if (board.playerOnePoints() >= 58) {
                            winner = "Gracz";
                        } else {
                            winner = "Komputer";
                        }
                        gameCont++;
                        /**
                         * Zainicjowanie okna informujacego o koncu gry i wygranej gracza lub komputera
                         */
                        sf::RenderWindow endGameWindow(sf::VideoMode({400, 200}), "Koniec gry");
                        sf::Text endGameText(font);
                        endGameText.setString("Koniec gry, wygral/a \n" + winner);
                        endGameText.setCharacterSize(24);
                        endGameText.setFillColor(sf::Color::Red);
                        endGameText.setPosition({50, 50});
                        /**
                         * Zapisywanie informacji o wygranej do pliku
                         */
                        std::fstream fileOut;
                        fileOut.open("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\files\\scores.txt",
                                     std::ios::app);
                        if (fileOut.is_open()) {
                            fileOut << "Gre  " << gameCont << " wygral/a " << winner << endl;
                            fileOut.close();
                        }
                        while (endGameWindow.isOpen()) {
                            sf::Event event;
                            while (endGameWindow.pollEvent(event)) {
                                if (event.type == sf::Event::Closed) {
                                    endGameWindow.close();
                                }
                            }

                            endGameWindow.clear(sf::Color::Black);
                            endGameWindow.draw(endGameText);
                            endGameWindow.display();
                        }
                        break;
                    }
/**
 * Dodanie elementow do okna, ustawienie tla, wyswietlenie i odswiezenie informacji
 */
                    pvcWindow.clear(sf::Color::White);
                    sf::Sprite backgroundSprite(background);
                    pvcWindow.draw(backgroundSprite);
                    board.draw(pvcWindow);
                    pvcWindow.draw(playerOneScore);
                    pvcWindow.draw(playerTwoScore);
                    pvcWindow.display();
                }
            }
        } else if (option == MenuOption::LoadGame) {

        } else if (option == MenuOption::HighScores) {
            sf::RenderWindow highScoresWindow(sf::VideoMode({1920, 1080}), "HighScores",
                                              sf::Style::Default,
                                              sf::ContextSettings(0, 0, 8));


            std::vector<std::string> scores;
            std::fstream fileIn;
/**
 * Zczytywanie linii z pliku i dodawanie ich do vecotra scores
 */
            fileIn.open("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\files\\scores.txt", std::ios::in);
            if (fileIn.is_open()) {
                std::string line;
                while (std::getline(fileIn, line)) {
                    scores.push_back(line);
                }
                fileIn.close();
            }
            sf::Text text(font);
            text.setCharacterSize(fontSize);
            text.setFillColor(sf::Color::White);
            while (highScoresWindow.isOpen()) {
                sf::Event event;
                while (highScoresWindow.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        highScoresWindow.close();
                    }
                }

                highScoresWindow.clear(sf::Color::White);
                sf::Sprite backgroundSprite(background);
                highScoresWindow.draw(backgroundSprite);
/**
 * Wyswietlanie wartosci zapisanych w wektozre na ekran
 */
                float startY = 100.0f;
                for (const auto& score : scores) {
                    text.setString(score);
                    text.setPosition({50.0f, startY});
                    highScoresWindow.draw(text);
                    startY += 50.0f;
                }
                highScoresWindow.display();
            }
        }
    }

}
