#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int r = matrix.size();
    int c = matrix[0].size();
    int total = r * c;
    int count = 0;

    int sRow = 0;
    int sCol = 0;
    int eRow = r - 1;
    int eCol = c - 1;

    while (count < total)
    {
        // Print starting row
        for (int i = sCol; count < total && i <= eCol; i++)
        {
            res.push_back(matrix[sRow][i]);
            count++;
        }
        sRow++;

        // Print Ending COlumn
        for (int i = sRow; count < total && i <= eRow; i++)
        {
            res.push_back(matrix[i][eCol]);
            count++;
        }
        eCol--;

        // Print Ending Row
        for (int i = eCol; count < total && i >= sCol; i--)
        {
            res.push_back(matrix[eRow][i]);
            count++;
        }
        eRow--;

        // Print Starting COlumn
        for (int i = eRow; count < total && i >= sRow; i--)
        {
            res.push_back(matrix[i][sCol]);
            count++;
        }
        sCol++;
    }

    return res;
}
int main()
{

    return 0;
}