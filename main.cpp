#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"

using namespace std;

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
    newGameText.setCharacterSize(24);
    newGameText.setFillColor(sf::Color::White);
    newGameText.setPosition({100, 100});

    sf::Text loadGameText(font);
    loadGameText.setString("Wczytaj gre");
    loadGameText.setCharacterSize(24);
    loadGameText.setFillColor(sf::Color::White);
    loadGameText.setPosition({100, 150});

    sf::Text highScoresText(font);
    highScoresText.setString("Najlepsze wyniki");
    highScoresText.setCharacterSize(24);
    highScoresText.setFillColor(sf::Color::White);
    highScoresText.setPosition({100, 200});

    sf::Text exitText(font);
    exitText.setString("Wyjscie");
    exitText.setCharacterSize(24);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition({100, 250});

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
    PvP.setCharacterSize(24);
    PvP.setFillColor(sf::Color::White);
    PvP.setPosition({100, 100});

    sf::Text PvC(font);
    PvC.setString("Gra z komputerem");
    PvC.setCharacterSize(24);
    PvC.setFillColor(sf::Color::White);
    PvC.setPosition({100, 150});

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

//tworzenie okna
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Hexxagon",
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
    Player playerOne(sf::Color::Yellow);
    Player playerTwo(sf::Color::Red);

    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\tomek\\CLionProjects\\PJC_projekt_1\\fonts\\Starjedi.ttf")) {
        std::cout << "Blad ladowania czcionki" << std::endl;
    }
    sf::Text playerOneScore(font);
    playerOneScore.setString("Hexagony gracza 1 :");
    playerOneScore.setCharacterSize(24);
    playerOneScore.setFillColor(sf::Color::White);
    playerOneScore.setPosition({100, 800});

    sf::Text playerTwoScore(font);
    playerTwoScore.setString("Hexagony gracza 2 :");
    playerTwoScore.setCharacterSize(24);
    playerTwoScore.setFillColor(sf::Color::White);
    playerTwoScore.setPosition({100, 840});

    Board board(boardPattern);

    board.setCurrentPlayer(playerOne);
    GameMode gameMode = GameMode::PvP;


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

                // Inicjalizacja planszy i graczy
                Board board(boardPattern);
                board.setCurrentPlayer(playerOne);

                // Pętla gry w nowym oknie
                while (gameWindow.isOpen()) {
                    sf::Event event;
                    while (gameWindow.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                            gameWindow.close();
                        }
                        // Obsługa zdarzeń gry (kliknięcia, zmiana koloru itp.)

                        board.mouseClick(event, playerOne);
                        board.hexagonColorChange(event, playerOne);
                    }

                    // Aktualizacja stanu gry

                    // Czyszczenie, rysowanie i wyświetlanie planszy oraz innych elementów gry
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
