#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include "Cell.h"

class SudokuBoard {
private:
    Cell grid[9][9];

    void recalculateRowHints(int row);
    void recalculateColumnHints(int col);
    void recalculateBoxHints(int row, int col);

    void reactiveUpdate(int row, int col);

public:
    void loadPuzzle();
    void displayBoard();

    void assignValue(int row, int col, int val);
    void inspectCell(int row, int col);

    void resetBoard();
};

#endif
