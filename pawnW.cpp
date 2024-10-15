//pawnW.cpp
#pragma once
#include "pieces.cpp"
#include <iostream>
#include <cmath>
using namespace std;

class pawnW:public pieces{
public:
    pawnW(int startX, int startY, char c) : pieces(startX, startY, c) {}

    bool isValid(int endX, int endY, pieces* board[8][8]) {
        pieces* target = board[endX][endY];
        if ((target == nullptr) || (abs(endX - x) == 1 && (endY - y == 1) && !sameColor(target) ) ) {
            return true;
        } else 
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

            cout << "pawnW moved to (" << x << ", " << y << ")" << endl;
            num = num+1;
        } else {
            cout << "Invalid move, try again" << endl;
        }
    }

    char getSymbol() {
        return 'P'; // 'P' for white pawn
    }

};