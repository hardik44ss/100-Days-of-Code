#include <iostream>
using namespace std;

//852. Peak Index in a Mountain Array

int peak(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid; // Update `e` to `mid` instead of `mid = e`
        }
    }
    return s; // Return `s` as it represents the peak index
}

int main()
{
    int arr[8] = {1, 2, 3, 6, 4, 3, 2, 1};
    cout << "Peak element index : " << peak(arr, 8) << endl;
    return 0;
}
