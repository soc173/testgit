// table.cpp
#pragma once
#include "pieces.cpp"
#include "king.cpp"
#include "queen.cpp"
#include "bishop.cpp"
#include "knight.cpp"
#include "rook.cpp"
#include "pawnB.cpp"
#include "pawnW.cpp"
#include <iostream>
using namespace std;

class table {
private:
    pieces* board[8][8];
    bool isWhiteTurn;
public:
    table() {
        
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = nullptr;
            }
        }
        isWhiteTurn = true; 
    }


    void setPieces() {
        // Set Black pieces
        board[0][0] = new rook(0, 0, 'B');
        board[0][1] = new knight(0, 1, 'B');
        board[0][2] = new bishop(0, 2, 'B');
        board[0][3] = new queen(0, 3, 'B');
        board[0][4] = new king(0, 4, 'B');
        board[0][5] = new bishop(0, 5, 'B');
        board[0][6] = new knight(0, 6, 'B');
        board[0][7] = new rook(0, 7, 'B');
        
        for (int i = 0; i < 8; i++) {
            board[1][i] = new pawnB(1, i, 'B');
        }

        // Set White pieces
        board[7][0] = new rook(7, 0, 'W');
        board[7][1] = new knight(7, 1, 'W');
        board[7][2] = new bishop(7, 2, 'W');
        board[7][3] = new queen(7, 3, 'W');
        board[7][4] = new king(7, 4, 'W');
        board[7][5] = new bishop(7, 5, 'W');
        board[7][6] = new knight(7, 6, 'W');
        board[7][7] = new rook(7, 7, 'W');
        
        for (int i = 0; i < 8; i++) {
            board[6][i] = new pawnW(6, i, 'W');
        }
    }

    void startGame() {
        setPieces(); 
        printBoard(); 
    }

    void printBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == nullptr) {
                    cout << "x ";
                } else {
                    cout << board[i][j]->getSymbol() << " ";
                }
            }
            cout << endl;
        }
    }

    void gameLoop() {
        string fromInput, toInput;

        while (true) {
            printBoard();
            cout << (isWhiteTurn ? "White's turn (W)" : "Black's turn (B)") << endl;

            // Nhập vị trí bắt đầu (ví dụ: e2)
            cout << "Enter start position (e.g., e2): ";
            getline(cin, fromInput);

            // Kiểm tra người chơi muốn thoát
            if (fromInput == "q") {
                cout << "Game ended!" << endl;
                break;
            }

            // Nhập vị trí kết thúc (ví dụ: e4)
            cout << "Enter end position (e.g., e4): ";
            getline(cin, toInput);

            if (toInput == "q") {
                cout << "Game ended!" << endl;
                break;
            }

            // Phân tích dữ liệu đầu vào từ người chơi
            int fromX = fromInput[0] - 'a';
            int fromY = fromInput[1] - '1';
            int toX = toInput[0] - 'a';
            int toY = toInput[1] - '1';

            // Kiểm tra vị trí đầu vào có hợp lệ không
            if (fromX < 0 || fromX >= 8 || fromY < 0 || fromY >= 8 ||
                toX < 0 || toX >= 8 || toY < 0 || toY >= 8) {
                cout << "Invalid input. Please enter positions within the board." << endl;
                continue;
            }

            pieces* selectedPiece = board[fromY][fromX];
            pieces* targetPiece = board[toY][toX];

            // Kiểm tra quân cờ có tồn tại ở vị trí bắt đầu không
            if (selectedPiece == nullptr) {
                cout << "No piece at the selected position. Try again." << endl;
                continue;
            }

            // Kiểm tra đúng lượt chơi
            if ((isWhiteTurn && selectedPiece->getSymbol() >= 'a') ||
                (!isWhiteTurn && selectedPiece->getSymbol() <= 'Z')) {
                cout << "Not your turn. Try again." << endl;
                continue;
            }

            // Kiểm tra nước đi hợp lệ
            if (selectedPiece->isValid(toY, toX, board)) {
                // Nếu quân vua đen bị ăn, trắng thắng và kết thúc trò chơi
                if (targetPiece != nullptr && (dynamic_cast<king*>(targetPiece) != nullptr) && targetPiece->getSymbol() == 'B') {
                    cout << "Black King captured! White wins!" << endl;
                    break;
                }

                // Di chuyển quân cờ
                selectedPiece->move(toY, toX, board);

                // Đổi lượt chơi
                isWhiteTurn = !isWhiteTurn;
            } else {
                cout << "Invalid move. Please try again." << endl;
            }
        }
}


    ~table() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] != nullptr) {
                    delete board[i][j];
                }
            }
        }
    }
};
