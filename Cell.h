#ifndef CELL_H
#define CELL_H

#include <vector>
using namespace std;

class Cell {
private:
    int value;
    vector<int> rowHints;
    vector<int> colHints;
    vector<int> boxHints;
    vector<int> consolidatedHints;

public:
    Cell();

    void setValue(int v);
    int getValue() const;

    void removeFromRow(int num);
    void removeFromCol(int num);
    void removeFromBox(int num);

    void refreshConsolidatedHints();

    vector<int> getRowHints();
    vector<int> getColHints();
    vector<int> getBoxHints();
    vector<int> getFinalHints();

    void resetHints();
};

#endif
