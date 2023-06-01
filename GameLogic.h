

#ifndef PJC_PROJEKT_1_GAMELOGIC_H
#define PJC_PROJEKT_1_GAMELOGIC_H

#include <vector>
#include "Player.h"

class GameLogic {
private:
    int boardPattern[17][9];
    Player playerOne;
    Player playerTwo;
    Player* currentPlayer;
    
public:
    GameLogic(int pattern[17][9]);
    void switchPlayer();
    bool isGameOver();
    Player* getCurrentPlayer() const;
};


#endif //PJC_PROJEKT_1_GAMELOGIC_H
