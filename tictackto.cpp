#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void drawBoard() {
    cout << "-------------" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "| ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

void takeTurn() {
    int position;
    cout << "Player " << currentPlayer << ", enter a position: ";
    cin >> position;

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if(board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Position already taken. Try again." << endl;
        takeTurn();
    } else {
        board[row][col] = currentPlayer;
    }
}

bool checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

bool checkTie() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    if(currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

int main() {
    cout << "Welcome to Tic Tac Toe!" << endl;
    drawBoard();
    while(!checkWin() && !checkTie()) {
        takeTurn();
        drawBoard();
        if(checkWin()) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if(checkTie()) {
            cout << "Tie game!" << endl;
        } else {
            switchPlayer();
        }
    }
    return 0;
}
