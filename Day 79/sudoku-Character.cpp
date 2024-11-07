#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>> &sudoku, char val) {
    for(int i = 0; i < 9; i++) {
        // Row check
        if(sudoku[row][i] == val) {
            return false;
        }

        // Column Check
        if(sudoku[i][col] == val) {
            return false;
        }

        // 3x3 Matrix Check
        if(sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>> &sudoku) {
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            
            // Empty Cell
            if(sudoku[row][col] == '.') {

                for(char val = '1'; val <= '9'; val++) {
                    if(isSafe(row, col, sudoku, val)) {
                        sudoku[row][col] = val;

                        bool nextSol = solve(sudoku);
                        if(nextSol) {
                            return true;
                        } else {
                            sudoku[row][col] = '.';
                        }

                    }
                }
                return false;
            }
        }
    }
    return true;
}

void validSudoku(vector<vector<char>> &sudoku) {
    solve(sudoku);
}

int main() {
    vector<vector<char>> sudoku(9, vector<char>(9, '.'));

    cout << "Enter the sudoku: " << endl;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }

    validSudoku(sudoku);

    cout << "Solved Sudoku: " << endl;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
3 . 6 5 . 8 4 . .
5 2 . . . . . . .
. 8 7 . . . . 3 1
. . 3 . 1 . . 8 .
9 . . 8 6 3 . . 5
. 5 . . 9 . 6 . .
1 3 . . . . 2 5 .
. . . . . . . 7 4
. . 5 2 . 6 3 . .
*/