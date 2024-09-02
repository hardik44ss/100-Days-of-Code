#include <iostream>
using namespace std;

int main() {

    int row;
    cin >> row;

    int col;
    cin >> col;

    //creating a 2D array
    int** arr = new int*[row];
    for(int i=0; i<row; i++) {
        arr[i] = new int[col];
    }

    //taking input
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> arr[i][j];
        }
    }

    //taking output
    cout << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }


    //releasing memory inside arr
    for(int i=0; i<row; i++) {
        delete [] arr[i];
    }   

    delete []arr; //Free the memory

    return 0;
}

    // Visual representation of the 2D array in memory (array of pointers)

    /*
       int **arr> [ int* ][ int* ][ int* ][ int* ]  (array of pointers)
        |             |       |       |       |
        v             v       v       v       v
       +---+       _____   _____   _____   _____
       |   | ----> |int|   |int|   |int|   |int|  -> Row 1
       |   |       |int|   |int|   |int|   |int|
       |   |       |int|   |int|   |int|   |int|
       |   |       |int|   |int|   |int|   |int|
       |   |       |int|   |int|   |int|   |int|
       +---+       +---+   +---+   +---+   +---+
       
       Each element in `arr` points to the corresponding row in the 2D array.
       The 2D array is essentially an array of arrays (rows).
    */