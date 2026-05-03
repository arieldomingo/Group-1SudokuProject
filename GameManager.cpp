#include <iostream>
#include "GameManager.h"
using namespace std;

void GameManager::translateInput(string input, int &row, int &col) {
    row = toupper(input[0]) - 'A';
    col = input[1] - '1';
}

void GameManager::displayMenu() {
    int choice;
    string pos;
    int val, row, col;

    while (true) {
        cout << "\n1. Assign Value\n2. Inspect Cell\n3. Reset\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter position (e.g., A1) and value: ";
            cin >> pos >> val;

            translateInput(pos, row, col);
            board.assignValue(row, col, val);

        } else if (choice == 2) {
            cout << "Enter position: ";
            cin >> pos;

            translateInput(pos, row, col);
            board.inspectCell(row, col);

        } else if (choice == 3) {
            board.resetBoard();

        } else if (choice == 4) {
            break;
        }

        board.displayBoard();
    }
}
