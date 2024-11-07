#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    // Helper function to check if placing 'val' at board[row][col] is safe
    bool isSafe(const vector<vector<char>>& board, int row, int col, char val) {
        for (int i = 0; i < 9; i++) {
            // Check if 'val' exists in the current row or column
            if (board[i][col] == val || board[row][i] == val) 
                return false;

            // Check if 'val' exists in the 3x3 sub-box
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == val && (subRow != row || subCol != col))
                return false;
        }
        return true;
    }

    // Main function to check if the Sudoku board is valid
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // Only validate filled cells
                if (board[i][j] != '.') {
                    char currentVal = board[i][j];
                    // Temporarily mark cell as empty to avoid self-checking
                    board[i][j] = '.';
                    if (!isSafe(board, i, j, currentVal)) {
                        return false;
                    }
                    // Restore original value
                    board[i][j] = currentVal;
                }
            }
        }
        return true;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    bool result = solution.isValidSudoku(board);
    if (result) {
        printf("The Sudoku board is valid.\n");
    } else {
        printf("The Sudoku board is not valid.\n");
    }

    return 0;
}
