// rook.cpp
#pragma once
#include "pieces.cpp"
#include <iostream>
using namespace std;

class rook : public pieces {
public:
    rook(int startX, int startY, char c) : pieces(startX, startY, c) {}

    bool isValid(int endX, int endY, pieces* board[8][8]) {
        if (endX == x || endY == y) {
            pieces* target = board[endX][endY];
            if (target == nullptr || !sameColor(target)) {
                return true;
            }
        }
        return false;
    }

    void move(int endX, int endY, pieces* board[8][8]) {
        if (isValid(endX, endY, board)) {
            if (board[endX][endY] != nullptr) {
                delete board[endX][endY];
            }
            board[endX][endY] = this;
            board[x][y] = nullptr;
            x = endX;
            y = endY;
            cout << "Rook moved to (" << x << ", " << y << ")" << endl;
        } else {
            cout << "Invalid move, try again" << endl;
        }
    }

    char getSymbol() {
        return color == 'W' ? 'R' : 'r'; // 'R' for white rook, 'r' for black rook
    }

};
