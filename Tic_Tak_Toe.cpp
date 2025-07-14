#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void initBoard() {
    char val = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = val++;
}


void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}


bool checkWin() {
    for (int i = 0; i < 3; i++) {

        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;


        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }


    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}


bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}


void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


bool makeMove(int pos) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if (pos < 1 || pos > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

int main() {
    initBoard();
    int move;

    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (!makeMove(move))
            continue;

        if (checkWin()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw()) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}
