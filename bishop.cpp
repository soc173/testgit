// bishop.cpp
#pragma once
#include "pieces.cpp"
#include <iostream>
#include <cmath>
using namespace std;

class bishop : public pieces {
public:
    bishop(int startX, int startY, char c) : pieces(startX, startY, c) {}

    bool isValid(int endX, int endY, pieces* board[8][8]) {
        if (abs(endX - x) == abs(endY - y)) {
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
            cout << "Bishop moved to (" << x << ", " << y << ")" << endl;
        } else {
            cout << "Invalid move, try again" << endl;
        }
    }
    char getSymbol() {
        return color == 'W' ? 'B' : 'b'; // 'B' for white bishop, 'b' for black bishop
    }

};
