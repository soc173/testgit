//king.cpp
#pragma once
#include "pieces.cpp"
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

class king:public pieces{
public:
    king(int startX, int startY, char c) : pieces(startX, startY, c) {}

    bool isValid(int endX, int endY, pieces* board[8][8]) {
        if (abs(endX - x) <= 1 && abs(endY - y) <= 1) {
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

            cout << "King moved to (" << x << ", " << y << ")" << endl;
            num = num+1;
        } else {
            cout << "Invalid move, try again" << endl;
        }
    }

    char getSymbol() {
        return color == 'W' ? 'K' : 'k'; // 'K' for white king, 'k' for black king
    }


};