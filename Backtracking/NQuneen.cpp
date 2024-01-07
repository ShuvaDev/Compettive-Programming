#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int n;

bool board[1000][1000];

void printBoard() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j]) {
                cout << " Q ";
            } else {
                cout << " . ";
            }
        }
        cout << endl;
    }
    for(int i = 1; i <= 3 * n; i++) cout << "-";
    cout << endl;
}

bool isValid(int row, int col) {
    for(int i = 0; i < col; i++) {
        if(board[row][i] == 1) {
            return false;
        }
    }
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 1) {
            return false;
        }
    }
    // Upper Left Corner

    for(int i = row - 1, j = col - 1; i >= 0 && col >= 0; i--, j--) {
        if(board[i][j] == 1) {
            return false;
        }
    }
    // Lower Left Corner

    for(int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
        if(board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

void generate(int col) {
    if(col >= n) {
        printBoard();
        return;
    }

    for(int row = 0; row < n; row++) {
        if(isValid(row, col)) {
            board[row][col] = 1;
            generate(col + 1);
        }
        board[row][col] = 0;
    }
}

int main() {
    n = 1;

    generate(0);
    
    
    
    return 0;
}