#include "Cell.h"

Cell::Cell() {
    value = 0;
    resetHints();
}

void Cell::resetHints() {
    rowHints.clear();
    colHints.clear();
    boxHints.clear();
    consolidatedHints.clear();

    for (int i = 1; i <= 9; i++) {
        rowHints.push_back(i);
        colHints.push_back(i);
        boxHints.push_back(i);
        consolidatedHints.push_back(i);
    }
}

void Cell::setValue(int v) {
    value = v;
    rowHints.clear();
    colHints.clear();
    boxHints.clear();
    consolidatedHints.clear();
}

int Cell::getValue() const {
    return value;
}

void Cell::removeFromRow(int num) {
    rowHints.erase(remove(rowHints.begin(), rowHints.end(), num), rowHints.end());
}

void Cell::removeFromCol(int num) {
    colHints.erase(remove(colHints.begin(), colHints.end(), num), colHints.end());
}

void Cell::removeFromBox(int num) {
    boxHints.erase(remove(boxHints.begin(), boxHints.end(), num), boxHints.end());
}

void Cell::refreshConsolidatedHints() {
    consolidatedHints.clear();

    for (int r : rowHints) {
        for (int c : colHints) {
            if (r == c) {
                for (int b : boxHints) {
                    if (r == b) {
                        consolidatedHints.push_back(r);
                    }
                }
            }
        }
    }
}

vector<int> Cell::getRowHints() { return rowHints; }
vector<int> Cell::getColHints() { return colHints; }
vector<int> Cell::getBoxHints() { return boxHints; }
vector<int> Cell::getFinalHints() { return consolidatedHints; }
