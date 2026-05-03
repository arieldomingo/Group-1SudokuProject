#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "SudokuBoard.h"

class GameManager {
private:
    SudokuBoard board;

    void translateInput(string input, int &row, int &col);

public:
    void displayMenu();
};

#endif
