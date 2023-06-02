#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Board.h"
#include "Player.h"

using namespace std;

const float radius = 30.0f;
const int fontSize = 35;
const int x = 1920;
const int y = 1080;

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

enum class MenuOption {
    NewGame,
    LoadGame,
    HighScores,
    Exit
};

enum class GameMode {
    PvP,
    PvC
};

MenuOption showMenuWindow(sf::RenderWindow &window, sf::Font &font) {


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
            if (event.type == sf::Event::Closed) {
                window.close();
                return MenuOption::Exit;
            }
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

        window.clear(sf::Color::White);
        sf::Texture background;
        if (!background.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\pictures\\background.jpg")) {
            std::cout << "Błąd ładowania tekstury tła" << std::endl;
        }
        sf::Sprite backgroundSprite(background);
        window.draw(backgroundSprite);
        window.draw(newGameText);
        window.draw(loadGameText);
        window.draw(highScoresText);
        window.draw(exitText);
        window.display();
    }

    return MenuOption::Exit;
}

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

//tworzenie okna
    sf::RenderWindow window(sf::VideoMode({x, y}), "Hexxagon",
                            sf::Style::Default,
                            sf::ContextSettings(0, 0, 8));
    sf::Texture background;
    if (!background.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\pictures\\background.jpg")) {
        std::cout << "Błąd ładowania tekstury tła" << std::endl;
        return -1;
    }
    sf::Sprite backgroundSprite(background);
    window.draw(backgroundSprite);
    window.clear(sf::Color::White);

    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\fonts\\Starjedi.ttf")) {
        std::cout << "Blad ladowania czcionki" << std::endl;
    }
    Player playerOne(sf::Color::Yellow);
    Player playerTwo(sf::Color::Red);

    int playerOneScoreValue = 0;
    int playerTwoScoreValue = 0;

    sf::Text playerOneScore(font);
    playerOneScore.setString("Hexagony gracza 1 :" + std::to_string(playerOneScoreValue));
//playerOneScore.setString("Hexagony gracza 1 :");
    playerOneScore.setCharacterSize(fontSize);
    playerOneScore.setFillColor(sf::Color::White);
    playerOneScore.setPosition({100, 800});

    sf::Text playerTwoScore(font);
    playerTwoScore.setString("Hexagony gracza 2 :" + std::to_string(playerTwoScoreValue));
//    playerTwoScore.setString("Hexagony gracza 2 :");
    playerTwoScore.setCharacterSize(fontSize);
    playerTwoScore.setFillColor(sf::Color::White);
    playerTwoScore.setPosition({100, 840});

    Board board(boardPattern);
    double playerNum = 1.0;
    while (window.isOpen()) {
        MenuOption option = showMenuWindow(window, font);

        if (option == MenuOption::Exit) {
            window.close();
        } else if (option == MenuOption::NewGame) {
            GameMode gameMode = showGameModeMenu(window, font);  // Wyświetlanie menu wyboru trybu gry

            if (gameMode == GameMode::PvP) {
                sf::RenderWindow gameWindow(sf::VideoMode({1920, 1080}), "Hexxagon",
                                            sf::Style::Default,
                                            sf::ContextSettings(0, 0, 8));

                Board board(boardPattern);

                // Pętla gry w nowym oknie
                while (gameWindow.isOpen()) {
                    sf::Event event;
                    while (gameWindow.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                            gameWindow.close();
                        } else if (event.type == sf::Event::MouseButtonPressed) {
                            if (event.mouseButton.button == sf::Mouse::Left) {
                                board.setCurrentPlayer(playerOne);
                                board.closeHexagons(event);
                                board.colorAttack(event);
                                board.hexagonColorChange(event);
                            }
                        }
                    }
                    playerOneScoreValue = board.playerOnePoints();
                    playerTwoScoreValue = board.playerTwoPoints();
                    playerOneScore.setString("Hexagony gracza 1 : " + std::to_string(playerOneScoreValue));
                    playerTwoScore.setString("Hexagony gracza 2 : " + std::to_string(playerTwoScoreValue));

                    if (board.playerOnePoints() == 58 || board.playerTwoPoints() == 58) {
                        gameWindow.close();
                        std::string winner;
                        if (board.playerOnePoints() == 58) {
                            winner = "Gracz 1";
                        } else {
                            winner = "Gracz 2";
                        }
                        sf::RenderWindow endGameWindow(sf::VideoMode({400, 200}), "Koniec gry");
                        sf::Text endGameText(font);
                        endGameText.setString("Koniec gry, wygral/a \n" + winner);
                        endGameText.setCharacterSize(24);
                        endGameText.setFillColor(sf::Color::Red);
                        endGameText.setPosition({50, 50});
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

                    gameWindow.clear(sf::Color::White);
                    sf::Sprite backgroundSprite(background);
                    gameWindow.draw(backgroundSprite);
                    board.draw(gameWindow);
                    gameWindow.draw(playerOneScore);
                    gameWindow.draw(playerTwoScore);
                    gameWindow.display();
                }
            } else if (gameMode == GameMode::PvC) {
                // Rozpocznij nową grę z komputerem
                // Dodaj odpowiednią logikę gry z komputerem
            }
        } else if (option == MenuOption::LoadGame) {
            // Wczytaj zapisaną grę
        } else if (option == MenuOption::HighScores) {
            // Wyświetl najlepsze wyniki
        }
    }

}
