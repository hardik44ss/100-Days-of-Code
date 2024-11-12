#include <iostream>
#include <vector>
using namespace std;

// Insertion Sort using recursion
void insertionSort(vector<int> &arr, int i, int n)
{
    if(i==n){
        return;
    }
    int temp = arr[i];
    int j = i - 1;
    for (; j >= 0; j--)
    {
        if (arr[j] > temp)
        {
            // shift
            arr[j + 1] = arr[j];
        }
        else
        { // ruk jao
            break;
        }
    }
    // copy temp value
    arr[j + 1] = temp;
    insertionSort(arr, i+1, n);
}

int main()
{
    vector<int> vec = {4, 2, 3, 6, 2, 4, 6, 3};
    insertionSort(vec, 1, vec.size());
    for (int i : vec)
    {
        cout << i << " ";
    }
    return 0;
}