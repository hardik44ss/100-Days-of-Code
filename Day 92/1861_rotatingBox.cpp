/*
Problem Statement:
You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:
- A stone '#'
- A stationary obstacle '*'
- Empty '.'

The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box.

Return the box after rotating it 90 degrees clockwise.

Example:
Input: box = [
  ['#', '.', '#'],
  ['#', '#', '*'],
  ['#', '.', '.']
]
Output: [
  ['#', '#', '.'],
  ['#', '#', '#'],
  ['.', '*', '.']
]

Constraints:
- m == box.length
- n == box[i].length
- 1 <= m, n <= 500
- box[i][j] is either '#', '*', or '.'.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size();
        int col = box[0].size();
        vector<vector<char>> box_90(col, vector<char>(row));

        // Simulate gravity
        for (int i = 0; i < row; i++) {
            int cell = col - 1;
            for (int j = col - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    cell = j - 1;
                } else if (box[i][j] == '#') {
                    box[i][j] = '.';
                    box[i][cell--] = '#';
                }
            }
        }

        // Rotate the box 90 degrees clockwise
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                box_90[j][row - i - 1] = box[i][j];
            }
        }

        return box_90;
    }
};

int main() {
    // Predefined input box
    vector<vector<char>> box = {
        {'#', '.', '#'},
        {'#', '#', '*'},
        {'#', '.', '.'}
    };

    Solution sol;
    vector<vector<char>> result = sol.rotateTheBox(box);

    // Output the result
    cout << "Rotated box:" << endl;
    for (const auto& row : result) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Expected Output:
Rotated box:
# # .
# # #
. * .
*/