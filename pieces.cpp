//pieces.cpp
#include <cmath>
#include <iostream>
using namespace std;

class pieces {
protected:
    int x, y;
    char color;
    int num;
public:
    pieces(int startX, int startY, char c) : x(startX), y(startY), color(c) {}

    bool sameColor(pieces* other){
        return other != nullptr && other->color == this->color;
    }

    virtual bool isValid(int endX, int endY, pieces* board[8][8]) = 0;

    virtual void move(int endX, int endY, pieces* board[8][8]) = 0;
    
    virtual char getSymbol() = 0;
};