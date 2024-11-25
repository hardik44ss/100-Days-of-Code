/*
Problem Statement:
The sliding puzzle is a 2x3 board with 5 tiles (numbered 1 to 5) and one empty space (represented by 0). The goal is to move the tiles around until the board is in the solved state:

1 2 3
4 5 0

You can move the tiles by sliding them into the empty space. Implement a function that returns the minimum number of moves required to solve the puzzle, or -1 if it is unsolvable.

Example:
Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.

Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.

Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the minimum number of moves required to solve the puzzle.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int dr[] = {0, 1, 0, -1};
        int dc[] = {-1, 0, 1, 0};
        vector<vector<int>> res = {{1, 2, 3}, {4, 5, 0}};
        int r, c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    r = i;
                    c = j;
                    break;
                }
            }
        }
        queue<pair<pair<int, int>, pair<vector<vector<int>>, int>>> q;
        q.push({{r, c}, {board, 0}});
        map<vector<vector<int>>, int> mp;
        mp[board]++;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            vector<vector<int>> v = q.front().second.first;
            int steps = q.front().second.second;
            q.pop();

            if (v == res) return steps;
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nc < 3 && nr < 2 && nr >= 0 && nc >= 0) {
                    vector<vector<int>> newBoard = v;
                    swap(newBoard[row][col], newBoard[nr][nc]);
                    if (mp.find(newBoard) == mp.end()) {
                        q.push({{nr, nc}, {newBoard, steps + 1}});
                        mp[newBoard]++;
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    // Predefined input board
    vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};

    Solution sol;
    int result = sol.slidingPuzzle(board);

    // Output the result
    cout << "Minimum number of moves to solve the puzzle: " << result << endl;

    return 0;
}

/*
Expected Output:
Minimum number of moves to solve the puzzle: 1
*/