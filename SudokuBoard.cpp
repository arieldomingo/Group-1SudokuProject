#include <iostream>
#include "SudokuBoard.h"
using namespace std;

void SudokuBoard::loadPuzzle() {
    // Simple empty board (can customize)
}

void SudokuBoard::displayBoard() {
    cout << "\n   1 2 3 4 5 6 7 8 9\n";
    for (int i = 0; i < 9; i++) {
        cout << char('A' + i) << "  ";
        for (int j = 0; j < 9; j++) {
            if (grid[i][j].getValue() == 0)
                cout << ". ";
            else
                cout << grid[i][j].getValue() << " ";
        }
        cout << endl;
    }
}

void SudokuBoard::assignValue(int row, int col, int val) {
    grid[row][col].setValue(val);
    reactiveUpdate(row, col);
}

void SudokuBoard::reactiveUpdate(int row, int col) {
    int val = grid[row][col].getValue();

    // Row
    for (int j = 0; j < 9; j++) {
        if (j != col)
            grid[row][j].removeFromRow(val);
    }

    // Column
    for (int i = 0; i < 9; i++) {
        if (i != row)
            grid[i][col].removeFromCol(val);
    }

    // Box
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;

    for (int i = sr; i < sr + 3; i++) {
        for (int j = sc; j < sc + 3; j++) {
            if (i != row || j != col)
                grid[i][j].removeFromBox(val);
        }
    }

    // Update only affected cells
    for (int i = 0; i < 9; i++) {
        grid[row][i].refreshConsolidatedHints();
        grid[i][col].refreshConsolidatedHints();
    }

    for (int i = sr; i < sr + 3; i++) {
        for (int j = sc; j < sc + 3; j++) {
            grid[i][j].refreshConsolidatedHints();
        }
    }
}

void SudokuBoard::inspectCell(int row, int col) {
    auto r = grid[row][col].getRowHints();
    auto c = grid[row][col].getColHints();
    auto b = grid[row][col].getBoxHints();
    auto f = grid[row][col].getFinalHints();

    cout << "\nRow Hints: ";
    for (int x : r) cout << x << " ";

    cout << "\nColumn Hints: ";
    for (int x : c) cout << x << " ";

    cout << "\nBox Hints: ";
    for (int x : b) cout << x << " ";

    cout << "\nFinal Hints: ";
    for (int x : f) cout << x << " ";

    cout << endl;
}

void SudokuBoard::resetBoard() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            grid[i][j] = Cell();
}
