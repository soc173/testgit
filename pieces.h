#ifndef PIECES_H
#define PIECES_H

class pieces {
protected:
    int x, y;
    char color;
    int num;
public:
    pieces(int startX, int startY, char c);

    bool sameColor(pieces* other);

    virtual bool isValid(int endX, int endY, pieces* board[8][8]) = 0;
    virtual void move(int endX, int endY, pieces* board[8][8]) = 0;
    virtual char getSymbol() = 0;
};

#endif // PIECES_H
