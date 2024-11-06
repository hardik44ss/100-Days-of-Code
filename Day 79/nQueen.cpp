#include <bits/stdc++.h>
using namespace std;

/*

    Time Complexity : O(N!)
    Space Complexity : O(N*N)
    
    Where N is the number of Queens.

*/

bool isSafe(vector<vector<int>>&chessBoard, int row, int col)
{
	// Check this row on the left
    for(int i = 0; i < col; i++)
    {
        if(chessBoard[row][i] == 1)
        {
            return false; 
        }
    }
    // Check upper left diagonal
    for(int i = row, j = col ; i >= 0 and j >= 0; i--, j--)
    {
        if(chessBoard[i][j] == 1)
        {
            return false;
        }
    }
    // Check lower left diagonal
    for(int i = row, j = col ; i < chessBoard.size() and j>=0; i++, j--)
    {
        if(chessBoard[i][j] == 1)
        {
            return false;
        }
    }
    // If it's safe to place the queen 
    return true;
}

//Function to add valid configuration
void addSolution(vector<vector<int>>&chessBoard, int n, vector<vector<int>>&ans) 
{
    vector<int> currentAnswer;
    int size = chessBoard.size();

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            currentAnswer.push_back(chessBoard[i][j]);
        }
    }
    ans.push_back(currentAnswer);
}

void nQueensHelper(vector<vector<int>>& chessBoard, int col, int n, vector<vector<int>>& ans) 
{
	// If all the queens have been placed
    if (col >= n) 
    {  
        addSolution(chessBoard, n, ans);
        return;
    }

    // Try all the rows
    for (int row = 0; row < n; row++) 
    {           
    	// Check if its safe to place the queen here
        if (isSafe(chessBoard, row, col)) 
        {     
        	// Mark queen placed
            chessBoard[row][col] = 1;  

            // Try placing rest of the queens
            nQueensHelper(chessBoard, col + 1, n, ans);  

            // Unmark the cell to backtrack 
            chessBoard[row][col] = 0;  
        }
    }

    return;
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> chessBoard(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    nQueensHelper(chessBoard, 0, n, ans);

    return ans;
}

int main() {
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    vector< vector<int> > solution = nQueens(n);
    int i = 0;

    for(vector<int> x : solution) {
        cout << endl << "Possible Configuration [" << ++i << "] : ";
        for(int y : x) {
            cout << y << " ";
        }
    }

    return 0;
}