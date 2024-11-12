#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Experiment 9: Implementation of Recursive Dynamic Programming for the 0/1 Knapsack Problem
 * 
 * Course Outcome: 4
 * 
 * - The problem involves selecting a subset of items such that their total weight does not exceed the knapsack's capacity,
 *   and their total value is maximized.
 * - This implementation uses recursive dynamic programming with memoization to optimize repeated calculations.
 * 
 * Steps:
 * 1. Create a DP table to store results of subproblems.
 * 2. Use recursion to explore both possibilities: including or excluding the current item.
 * 3. Return the maximum profit obtained.
 * 
 * Relevant Book/Standard Code: Dynamic Programming algorithms for solving optimization problems.
 */

int knapsackRecursive(vector<vector<int>>& dp, vector<int>& values, vector<int>& weights, int W, int n) {
    // Base case: If no items are left or capacity is 0
    if (n == 0 || W == 0)
        return 0;

    // If value is already calculated
    if (dp[n][W] != -1)
        return dp[n][W];

    // If weight of the nth item is more than knapsack capacity W, then this item cannot be included in the optimal solution
    if (weights[n - 1] > W)
        return dp[n][W] = knapsackRecursive(dp, values, weights, W, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return dp[n][W] = max(values[n - 1] + knapsackRecursive(dp, values, weights, W - weights[n - 1], n - 1),
                              knapsackRecursive(dp, values, weights, W, n - 1));
}

int knapsack(int W, vector<int>& values, vector<int>& weights, int n) {
    // Create a dp table to store results of subproblems
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return knapsackRecursive(dp, values, weights, W, n);
}

int main() {
    // Number of items
    int n = 4;

    // Capacity of knapsack
    int W = 50;

    // Item values
    vector<int> values = {60, 100, 120, 30};

    // Item weights
    vector<int> weights = {10, 20, 30, 40};

    // Calculate the maximum profit
    int maxProfit = knapsack(W, values, weights, n);

    // Output the result
    cout << "The maximum profit is: " << maxProfit << endl;

    return 0;
}

/*
Expected Output:
The maximum profit is: 220
*/