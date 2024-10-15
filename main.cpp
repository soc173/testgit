#include "pieces.cpp"
#include "king.cpp"
#include "queen.cpp"
#include "bishop.cpp"
#include "knight.cpp"
#include "rook.cpp"
#include "pawnB.cpp"
#include "pawnW.cpp"
#include "table.cpp"
#include <iostream>
using namespace std;


int main() {
    table chessTable;
    chessTable.gameLoop();

    return 0;
}
