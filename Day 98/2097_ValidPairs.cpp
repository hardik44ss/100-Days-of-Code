/*
Problem Statement:
Given a list of pairs representing directed edges in a graph, return an arrangement of the pairs such that for each pair (a, b), the next pair starts with b. If no such arrangement exists, return an empty list.

Example:
Input: pairs = [[1, 3], [3, 2], [2, 1]]
Output: [[1, 3], [3, 2], [2, 1]]

Input: pairs = [[1, 2], [2, 3], [3, 4], [4, 1]]
Output: [[1, 2], [2, 3], [3, 4], [4, 1]]

Constraints:
- 1 <= pairs.length <= 10^5
- pairs[i].length == 2
- 0 <= pairs[i][0], pairs[i][1] < 10^5
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjacencyList;
        unordered_map<int, int> inDegree, outDegree;

        for (const auto& pair : pairs) {
            adjacencyList[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }

        int startNode = pairs[0][0];
        for (const auto& [node, degree] : outDegree) {
            if (degree > inDegree[node]) {
                startNode = node;
                break;
            }
        }

        vector<int> path;
        stack<int> nodeStack;
        nodeStack.push(startNode);

        while (!nodeStack.empty()) {
            auto& neighbors = adjacencyList[nodeStack.top()];
            if (neighbors.empty()) {
                path.push_back(nodeStack.top());
                nodeStack.pop();
            } else {
                int nextNode = neighbors.back();
                nodeStack.push(nextNode);
                neighbors.pop_back();
            }
        }

        vector<vector<int>> arrangement;
        int pathSize = path.size();
        arrangement.reserve(pathSize - 1);

        for (int i = pathSize - 1; i > 0; --i) {
            arrangement.push_back({path[i], path[i-1]});
        }

        return arrangement;
    }
};

int main() {
    // Predefined input pairs
    vector<vector<int>> pairs = {{1, 3}, {3, 2}, {2, 1}};

    Solution sol;
    vector<vector<int>> result = sol.validArrangement(pairs);

    // Output the result
    cout << "Valid arrangement of pairs:" << endl;
    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "]" << endl;
    }

    return 0;
}

/*
Expected Output:
Valid arrangement of pairs:
[1, 3]
[3, 2]
[2, 1]
*/
