#include <iostream>
#include <vector>
using namespace std;

// Searching in a sorted 2D array using binary search
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    int c = matrix[0].size();

    int start = 0;
    int end = r * c - 1;

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (matrix[mid / c][mid % c] == target)
        {
            return true;
        }
        else if (matrix[mid / c][mid % c] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
} // Time complexity : O(log(m*n))

int main()
{

    return 0;
}