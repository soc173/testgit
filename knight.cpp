// knight.cpp
#pragma once
#include "pieces.cpp"
#include <iostream>
#include <cmath>
using namespace std;

class knight : public pieces {
public:
    knight(int startX, int startY, char c) : pieces(startX, startY, c) {}

    bool isValid(int endX, int endY, pieces* board[8][8]) {
        int dx = abs(endX - x);
        int dy = abs(endY - y);

        if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
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
            cout << "Knight moved to (" << x << ", " << y << ")" << endl;
        } else {
            cout << "Invalid move, try again" << endl;
        }
    }

    char getSymbol() {
        return color == 'W' ? 'N' : 'n'; // 'N' for white knight, 'n' for black knight
    }

};
