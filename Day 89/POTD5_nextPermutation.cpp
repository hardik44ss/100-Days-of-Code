/*
Problem Statement:
Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order).

Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

Examples:

Input: arr = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.

Input: arr = [3, 2, 1]
Output: [1, 2, 3]
Explanation: As arr[] is the last permutation, the next permutation is the lowest one.

Input: arr = [3, 4, 2, 5, 1]
Output: [3, 4, 5, 1, 2]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int index1 = -1;
        stack<int> st;
        int index2 = -1;
        int len = arr.size();
        st.push(arr[len - 1]);
        int i = len - 2;
        while (i >= 0 && arr[i] >= st.top()) {
            st.push(arr[i]);
            i--;
        }
        index1 = i;

        if (st.size() == len) {
            sort(arr.begin(), arr.end());
            return;
        }
        i = len - 1;
        while (!st.empty()) {
            if (arr[index1] < st.top()) {
                index2 = i;
            }
            arr[i] = st.top();
            i--;
            st.pop();
        }
        swap(arr[index1], arr[index2]);
    }
};

int main() {
    // Predefined input array
    vector<int> arr = {2, 4, 1, 7, 5, 0};

    Solution sol;
    sol.nextPermutation(arr);

    // Output the result
    cout << "Next permutation: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Expected Output:
Next permutation: 2 4 5 0 1 7
*/